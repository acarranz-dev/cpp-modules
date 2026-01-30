#include "PmergeMe.hpp"
#include <algorithm>
#include <utility>
#include <sys/time.h>
#include <iomanip>
#include <typeinfo>
#include <climits>
#include <sstream>

PmergeMe::PmergeMe(): _vecPairs(0), _vecResult(0) , _vectorTime(0) , _deqPairs(0),
 _deqResult(0), _dequeTime(0), _jacobSequence(0) {}

PmergeMe::PmergeMe(std::string &input){
	if (!parseInput(input))
		throw NotValidInputException();
	sortContainer(_vecPairs,  input);
	sortContainer(_deqPairs,  input);
	std::cout << "Before: " << input << std::endl;
	std::cout << "After:  ";
	printContainer(_vecResult);
	std::cout << std::endl;
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _size
			  << " elements with std::vector : "
			  << _vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _size
			  << " elements with std::deque : "
			  << _dequeTime << " us" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other) :  _vecPairs(other._vecPairs) , _vecResult(other._vecResult),
	_vectorTime(0), _deqPairs(other._deqPairs) ,_deqResult(other._deqResult), _dequeTime(other._dequeTime),
	_jacobSequence(other._jacobSequence) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other){
	if (this != &other)	{
		_vecPairs = other._vecPairs;
		_vecResult = other._vecResult;
		_vectorTime = other._vectorTime;
		_deqPairs = other._deqPairs;
		_deqResult = other._deqResult;
		_dequeTime = other._dequeTime;
		_jacobSequence = other._jacobSequence;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

const char *PmergeMe::NotValidInputException::what() const throw(){
	return "Invalid input format";
}

const char *PmergeMe::MaxIntException::what() const throw(){
	return "Number exceeds INT_MAX limit";
}

const char *PmergeMe::PositiveNumbersException::what() const throw(){
	return "Only positive numbers are allowed";
}

bool PmergeMe::parseInput(std::string input){
	if (input.size() < 3)
		return false;
	for (size_t i = 0; i < input.size(); i++){
		if (!std::isdigit(input[i]) && (input[i] != ' ')){
			if (input[i] == '-')
				throw PositiveNumbersException();
			return false;
		}
	}

	return true;
}

int PmergeMe::jacobsthalNumber(int n){
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthalNumber(n - 1) + 2 * jacobsthalNumber(n - 2);
}

std::vector<int> PmergeMe::generateJacobsthalSequence(int size){
	std::vector<int> sequence;
	if (size > 1)
		sequence.push_back(1);
	int groupIndex = 3;
	while (jacobsthalNumber(groupIndex - 1) < size ){
		int currentJac = jacobsthalNumber(groupIndex);
		int prevJac = jacobsthalNumber(groupIndex - 1);
		for (int i = currentJac; i > prevJac; i--){
			if (i < size)
				sequence.push_back(i);
		}
		groupIndex++;
	}
	sequence.insert(sequence.end(), 0);
	return sequence;
}

template <typename Container>
Container PmergeMe::createPair(Container &container, std::string &input){
	if (!parseInput(input))
		throw NotValidInputException();

	std::istringstream iss(input);
	long value;
	int count = 0;
	typename Container::value_type currentPair;
	while (iss >> value){
		if (value > INT_MAX)
			throw MaxIntException();
		if (value < 0)
			throw PositiveNumbersException();
		if (count % 2 == 0)
			currentPair.first = static_cast<int>(value);
		else{
			currentPair.second = static_cast<int>(value);
			if (currentPair.first < currentPair.second)
				std::swap(currentPair.first, currentPair.second);
			container.push_back(currentPair);
		}
		count++;
	}
	if (count % 2 != 0){
		currentPair.second = currentPair.first;
		currentPair.first = -1;
		container.push_back(currentPair);
	}
	std::sort(container.begin(), container.end());
	if (container[0].first == -1){
		container.push_back(std::make_pair(container[0].first, container[0].second));
		container.erase(container.begin());
	}
	_size = static_cast<size_t>(count);
	return container;
}

template <typename Container>
int PmergeMe::binarySearch(const Container &result, int nbr, int start, int end)
{
	if (start > end)
		return start;
	int half = (end + start) / 2;
	if (result[half] == nbr)
		return half;
	if (result[half] > nbr)
		return binarySearch(result, nbr, start, half - 1);
	return binarySearch(result, nbr, half + 1, end);
}

template <typename PairContainer>
int PmergeMe::findPair(const PairContainer &pairs, int lower)
{
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].second == lower)
			return pairs[i].first;
	}
	return -1;
}

template <typename PairContainer, typename ResultContainer>
int PmergeMe::findPairIndex(const PairContainer &pairs, const ResultContainer &result, int lower)
{
	int pairValue = findPair(pairs, lower);
	if (pairValue == -1)
		return result.size() - 1;
	for (size_t i = 0; i < result.size(); i++)
	{
		if (pairValue == result[i])
			return i;
	}
	return pairValue;
}

template <typename PairContainer, typename ResultContainer>
void PmergeMe::insertLowers(PairContainer & pairs, ResultContainer & containerResult)
{
	for (size_t i = 0; i < pairs.size(); i++){
		if (pairs[i].first > 0)
			containerResult.push_back(pairs[i].first);
	}
	if (!pairs.empty()){
		containerResult.insert(containerResult.begin(), pairs[0].second);
		pairs.erase(pairs.begin());
	}
	_jacobSequence = generateJacobsthalSequence(static_cast<int>(pairs.size()));
	for (size_t i = 0; i < pairs.size(); i++)
	{
		int valueToInsert = pairs[_jacobSequence[i]].second;
		int pairIndex = findPairIndex(pairs, containerResult, valueToInsert);
		int index = binarySearch(containerResult, valueToInsert, 0, pairIndex);
		containerResult.insert(containerResult.begin() + index, valueToInsert);
	}
}

template <typename Container>
void PmergeMe::sortContainer(Container & container, std::string & input)
{
	struct timeval start, end;
	gettimeofday(&start, NULL);
	container = createPair(container, input);
	bool isVector = (typeid(Container) == typeid(std::vector<std::pair<int, int> >));
	if (isVector)
		insertLowers(container, _vecResult);
	else
		insertLowers(container, _deqResult);
	gettimeofday(&end, NULL);
	long seconds = end.tv_sec - start.tv_sec;
	long microseconds = end.tv_usec - start.tv_usec;
	double duration = seconds * 1000000 + microseconds;
	if (isVector)
		_vectorTime = duration;
	else
		_dequeTime = duration;
}

template <typename Container>
void PmergeMe::printConatinerPair(Container & pair)
{
	for (size_t i = 0; i < pair.size(); i++)
		std::cout << "[" << i << "]Biggers: " << pair[i].first << std::endl;
	for (size_t i = 0; i < pair.size(); i++)
		std::cout << "[" << i << "]Lowers: " << pair[i].second << std::endl;
	std::cout << std::endl;
}

template <typename Container>
void PmergeMe::printContainer(Container & container)
{
	for (size_t i = 0; i < container.size(); i++)
		std::cout << container[i] << " ";
	std::cout << std::endl;
}
