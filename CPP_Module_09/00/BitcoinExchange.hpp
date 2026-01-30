#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include "ReadCSV.hpp"

#define DAYS	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
#define LIMIT_AMOUNT 1000

class Bitcoin{
private:
	std::map<std::string, float> _database;
	std::map<std::string, float> _dataInput;

public:
	Bitcoin();
	Bitcoin(const Bitcoin &other);
	Bitcoin &operator=(const Bitcoin &other);
	Bitcoin(const std::string &file);
	~Bitcoin();

	class NotValidFormatException : public std::exception{
		const char *what() const throw();
	};
	class NotValidFormatDateException : public std::exception{
		const char *what() const throw();
	};
	class NotFoundPreviouslyDateException : public std::exception{
		const char *what() const throw();
	};
	class NegativeAmountException : public std::exception{
		const char *what() const throw();
	};
	class NotValidFormatMultierException : public std::exception{
		const char *what() const throw();
	};
	void btcExchange();
	bool validationMonth(std::string month);
	bool validationDay(std::string day, std::string month);
	bool parseDate(std::string date);
	std::string previouslyDate(std::string date);
};

#endif

