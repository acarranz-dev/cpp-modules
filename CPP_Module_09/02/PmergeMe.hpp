#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>

class PmergeMe{
private:
	std::vector<std::pair<int, int> >	_pairs;
	std::vector<int> 					_jacobSequence;
	std::vector<int>					_result;

	std::deque<std::pair<int, int> >	_deqPairs;
	std::deque<int> 					_deqJacobSequence;
	std::deque<int>						_deqResult;

	std::vector<int> 					_originalArray;
	double 								_dequeTime;
	double 								_vectorTime;

	//  METHODS
	bool parseInput(std::string input);
	int jacobsthalNumber(int n);

	//VECTOR
	std::vector<std::pair<int, int> > intToPair(std::vector<int> arr);
	std::vector<std::pair<int, int> > createPair(std::string &input);
	int binarySearch(int nbr, int start, int end);
	void insertLowers(std::vector<std::pair<int, int> > &pairs);
	std::vector<int> generateJacobsthalSequence(size_t size);
	int findPairIndex(int lower);
	int findPair(int pair);
	void sortVector(std::string &input);

	//DEQUE
	std::deque<std::pair<int, int> > intToPairDeque(std::deque<int> arr);
	std::deque<std::pair<int, int> > createPairDeque(std::string &input);
	int binarySearchDeque(int nbr, int start, int end);
	void insertLowersDeque(std::deque<std::pair<int, int> > &pairs);
	std::deque<int> generateJacobsthalSequenceDeque(size_t size);
	int findPairIndexDeque(int lower);
	int findPairDeque(int pair);
	void sortDeque(std::string &input);


public:
	PmergeMe();
	PmergeMe(std::string &input);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	//  EXCEPCIONS
	class NotValidInputException : public std::exception{
		const char *what() const throw();
	};

	// DEBUG
	void printVectorPair(std::vector<std::pair<int, int> > pair);
	void printVector(std::vector<int> vec);
	void printDeque(std::deque<int> deq);
};

#endif
