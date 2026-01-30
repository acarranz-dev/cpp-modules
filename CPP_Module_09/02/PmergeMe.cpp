#include "PmergeMe.hpp"
#include <algorithm>
#include <utility>
#include <sys/time.h>
#include <iomanip>

PmergeMe::PmergeMe(): _pairs(0), _jacobSequence(0), _result(0) , _deqPairs(0),
	_deqJacobSequence(0), _deqResult(0), _originalArray(0), _dequeTime(0), _vectorTime(0){}

PmergeMe::PmergeMe(std::string &input)
{
	if (!parseInput(input))
		throw NotValidInputException();
	sortVector(input);
	sortDeque(input);
	std::cout << "Before: ";
	printVector(_originalArray);
	std::cout << "After:  ";
	printVector(_result);
	std::cout << std::endl;
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _originalArray.size()
			  << " elements with std::vector : "
			  << _vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _originalArray.size()
			  << " elements with std::deque : "
			  << _dequeTime << " us" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other) :  _pairs(other._pairs) , _jacobSequence(other._jacobSequence),
	_result(other._result), _deqPairs(other._deqPairs), _deqJacobSequence(other._deqJacobSequence),
	_deqResult(other._deqResult), _originalArray(other._originalArray), _dequeTime(0), _vectorTime(0) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other){
	if (this != &other)	{
		_pairs = other._pairs;
		_jacobSequence = other._jacobSequence;
		_result = other._result;
		_deqPairs = other._deqPairs;
		_deqJacobSequence = other._deqJacobSequence;
		_deqResult = other._deqResult;
		_originalArray = other._originalArray;
		_dequeTime = other._dequeTime;
		_vectorTime = other._vectorTime;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

const char *PmergeMe::NotValidInputException::what() const throw(){
	return "Input no válido";
}

bool PmergeMe::parseInput(std::string input){
	if (input.size() < 3)
		return false;
	for (size_t i = 0; i < input.size(); i++){
		if (!std::isdigit(input[i]) && (input[i] != ' '))
			return false;
	}
	return true;
}

std::vector<std::pair<int, int> > PmergeMe::intToPair(std::vector<int> arr){
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < arr.size() - 1; i += 2){
		int bigger = std::max(arr[i] , arr[i + 1]);
		int lower = std::min(arr[i] , arr[i + 1]);
		pairs.push_back(std::make_pair(bigger, lower));
	}
	std::sort(pairs.begin(),pairs.end());
	if(arr.size() % 2 != 0)
		pairs.push_back(std::make_pair(-1, arr[arr.size() - 1]));
	return pairs;
}

std::vector<std::pair<int, int> > PmergeMe::createPair(std::string &input){
	if (!parseInput(input))
		throw NotValidInputException();
	std::vector<int> arr;
	std::string nbr;
	for (size_t i = 0; i < input.size(); i++){
		if (std::isdigit(input[i]))
			nbr += input[i];
		else{
			arr.push_back(std::atoi(nbr.c_str()));
			nbr.clear();
		}
	}
	if (!nbr.empty())
		arr.push_back(std::atoi(nbr.c_str()));
	_originalArray = arr;
	return intToPair(arr);

}

int PmergeMe::binarySearch(int nbr, int start, int end){
	if (start > end)
		return start;
	int half = (end + start) / 2;
	if (_result[half] == nbr)
		return half;
	if (_result[half] > nbr)
		return binarySearch(nbr, start, half - 1);
	return binarySearch(nbr, half + 1, end);
}

int PmergeMe::jacobsthalNumber(int n){
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthalNumber(n - 1) + 2 * jacobsthalNumber(n - 2);
}

std::vector<int> PmergeMe::generateJacobsthalSequence(size_t size){
	std::vector<int> sequence;
	if (size > 1)
		sequence.push_back(1);
	size_t groupIndex = 3;
	while (jacobsthalNumber(static_cast<int>(groupIndex - 1)) < static_cast<int>(size)){
		int currentJac = jacobsthalNumber(static_cast<int>(groupIndex));
		int prevJac = jacobsthalNumber(static_cast<int>(groupIndex - 1));
		for (int i = currentJac; i > prevJac; i--){
			if (i < static_cast<int>(size))
				sequence.push_back(i);
		}
		groupIndex++;
	}
	sequence.insert(sequence.end(), 0);
	return sequence;
}

int PmergeMe::findPair(int pair){
	for (size_t i = 0; i < _pairs.size(); i++){
		if (_pairs[i].second == pair)
			return _pairs[i].first;
	}
	return _result.size() -1;
}

int PmergeMe::findPairIndex(int lower){
	int pair = findPair(lower);
	for (size_t i = 0; i < _result.size(); i++){
		if (pair == _result[i])
			return i;
	}
	return pair;
}

void PmergeMe::insertLowers(std::vector<std::pair<int, int> > &pairs){
	for (size_t i = 0; i < pairs.size(); i++){
		if (pairs[i].first > 0)
			_result.push_back(pairs[i].first);
	}
	if (!pairs.empty())
		_result.insert(_result.begin(), pairs[0].second);
	for (size_t i = 1; i < pairs.size(); i++){
		int valueToInsert = pairs[_jacobSequence[i - 1]].second;
		int pairIndex = findPairIndex(valueToInsert);
		int index = binarySearch(valueToInsert, 0, pairIndex);
		_result.insert(_result.begin() + index, valueToInsert);
	}
}

//DEQUE

std::deque<std::pair<int, int> > PmergeMe::intToPairDeque(std::deque<int> arr){
	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i < arr.size() - 1; i += 2){
		int bigger = std::max(arr[i] , arr[i + 1]);
		int lower = std::min(arr[i] , arr[i + 1]);
		pairs.push_back(std::make_pair(bigger, lower));
	}
	std::sort(pairs.begin(),pairs.end());
	if(arr.size() % 2 != 0)
		pairs.push_back(std::make_pair(-1, arr[arr.size() - 1]));
	return pairs;
}

std::deque<std::pair<int, int> > PmergeMe::createPairDeque(std::string &input){
	if (!parseInput(input))
		throw NotValidInputException();
	std::deque<int> arr;
	std::string nbr;
	for (size_t i = 0; i < input.size(); i++){
		if (std::isdigit(input[i]))
			nbr += input[i];
		else{
			arr.push_back(std::atoi(nbr.c_str()));
			nbr.clear();
		}
	}
	if (!nbr.empty())
		arr.push_back(std::atoi(nbr.c_str()));
	return intToPairDeque(arr);

}

int PmergeMe::binarySearchDeque(int nbr, int start, int end){
	if (start > end)
		return start;
	int half = (end + start) / 2;
	if (_deqResult[half] == nbr)
		return half;
	if (_deqResult[half] > nbr)
		return binarySearchDeque(nbr, start, half - 1);
	return binarySearchDeque(nbr, half + 1, end);
}

std::deque<int> PmergeMe::generateJacobsthalSequenceDeque(size_t size){
	std::deque<int> sequence;
	if (size > 1)
		sequence.push_back(1);
	size_t groupIndex = 3;
	while (jacobsthalNumber(static_cast<int>(groupIndex - 1)) < static_cast<int>(size)){
		int currentJac = jacobsthalNumber(static_cast<int>(groupIndex));
		int prevJac = jacobsthalNumber(static_cast<int>(groupIndex - 1));
		for (int i = currentJac; i > prevJac; i--){
			if (i < static_cast<int>(size))
				sequence.push_back(i);
		}
		groupIndex++;
	}
	sequence.insert(sequence.end(), 0);
	return sequence;
}

int PmergeMe::findPairDeque(int pair){
	for (size_t i = 0; i < _deqPairs.size(); i++){
		if (_deqPairs[i].second == pair)
			return _deqPairs[i].first;
	}
	return _deqResult.size() -1;
}

int PmergeMe::findPairIndexDeque(int lower){
	int pair = findPairDeque(lower);
	for (size_t i = 0; i < _deqResult.size(); i++){
		if (pair == _deqResult[i])
			return i;
	}
	return pair;
}

void PmergeMe::insertLowersDeque(std::deque<std::pair<int, int> > &pairs){
	for (size_t i = 0; i < pairs.size(); i++){
		if (pairs[i].first > 0)
			_deqResult.push_back(pairs[i].first);
	}
	if (!pairs.empty())
		_deqResult.insert(_deqResult.begin(), pairs[0].second);
	for (size_t i = 1; i < pairs.size(); i++){
		int valueToInsert = pairs[_deqJacobSequence[i - 1]].second;
		int pairIndex = findPairIndexDeque(valueToInsert);
		int index = binarySearchDeque(valueToInsert, 0, pairIndex);
		_deqResult.insert(_deqResult.begin() + index, valueToInsert);
	}
}



//DEBUG
void PmergeMe::printVectorPair(std::vector<std::pair<int, int> > pair){
	for (size_t i = 0; i < pair.size(); i++)
		std::cout << "["<< i <<"]Biggers: "<< pair[i].first << std::endl;
	for (size_t i = 0; i < pair.size(); i++)
		std::cout << "["<< i <<"]Lowers: "<< pair[i].second << std::endl;
	std::cout << std::endl;
}

void PmergeMe::printVector(std::vector<int> vec){
	for (size_t i = 0; i < vec.size(); i++)
		std::cout <<  vec[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::printDeque(std::deque<int> deq){
	std::cout <<  "Result: ";
	for (size_t i = 0; i < deq.size(); i++)
		std::cout <<  deq[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::sortVector(std::string &input){
	struct timeval start, end;
	gettimeofday(&start, NULL);
	_pairs = createPair(input);
	_jacobSequence = generateJacobsthalSequence(_pairs.size()  - 1);
	insertLowers(_pairs);
    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double duration = seconds * 1000000 + microseconds;
	_vectorTime = duration;
}

void PmergeMe::sortDeque(std::string &input){
	struct timeval start, end;
	gettimeofday(&start, NULL);
	_deqPairs = createPairDeque(input);
	_deqJacobSequence = generateJacobsthalSequenceDeque(_deqPairs.size()  - 1);
	insertLowersDeque(_deqPairs);
    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double duration = seconds * 1000000 + microseconds;
	_dequeTime = duration;
}

//./a.out "$(shuf -i 1-100000 -n 10000 | tr '\n' ' ')"
