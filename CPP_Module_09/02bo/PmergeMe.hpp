#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <deque>

class PmergeMe{
private:
	std::vector<std::pair<int, int> >	_vecPairs;
	std::vector<int>					_vecResult;
	double 								_vectorTime;

	std::deque<std::pair<int, int> >	_deqPairs;
	std::deque<int>						_deqResult;
	double 								_dequeTime;

	std::vector<int> 					_jacobSequence;
	size_t								_size;

	bool parseInput(std::string input);
	int jacobsthalNumber(int n);
	std::vector<int> generateJacobsthalSequence(int size);

	template <typename Container>
	Container createPair(Container &container, std::string &input);
	template <typename Container>
	int binarySearch(const Container& result, int nbr, int start, int end);
	template <typename PairContainer, typename ResultContainer>
	void insertLowers(PairContainer &pairs, ResultContainer &containerResult);
	template <typename Container>
	int findPair(const Container& pairs, int pair);
	template <typename PairContainer, typename ResultContainer>
	int findPairIndex(const PairContainer &pairs, const ResultContainer &result, int lower);
	template <typename Container>
	void sortContainer(Container &conatiner, std::string &input);
	template <typename Container>
	void printConatinerPair(Container &pair);
	template <typename Container>
	void printContainer(Container &container);

public:
	PmergeMe();
	PmergeMe(std::string &input);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	class NotValidInputException : public std::exception{
		const char *what() const throw();
	};
	class MaxIntException : public std::exception{
		const char *what() const throw();
	};
	class PositiveNumbersException : public std::exception{
		const char *what() const throw();
	};
};
#endif

//"$(shuf -i 1-100000 -n 100 | tr '\n' ' ')"
