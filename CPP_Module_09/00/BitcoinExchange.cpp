#include "BitcoinExchange.hpp"
#include <fstream>
#include <cmath>
#include <limits>



//EXCEPTIONS
const char *Bitcoin::NotValidFormatException::what() const throw(){
	return "Not valid format : \"date | number\".";
}

const char *Bitcoin::NotValidFormatDateException::what() const throw(){
	return "bad input => ";
}

const char *Bitcoin::NotValidFormatMultierException::what() const throw(){
	return "too large a number.";
}

const char *Bitcoin::NotFoundPreviouslyDateException::what() const throw(){
	return "Not found previously date.";
}

const char *Bitcoin::NegativeAmountException::what() const throw(){
	return "not a positive number.";
}

//CONSTRUCTORS
Bitcoin::Bitcoin(){
	ReadCSV _data("data.csv", ',');
	_database = _data.getData();
}

Bitcoin::Bitcoin(const Bitcoin &other) : _database(other._database)  {}


Bitcoin &Bitcoin::operator=(const Bitcoin &other){
	if (this != &other)
		_database = other._database;
	return *this;
}

Bitcoin::Bitcoin(const std::string &file){
	ReadCSV _data("data.csv", ',');
	_database = _data.getData();
	ReadCSV inputFile(file, '|');
	_dataInput = inputFile.getData();
	this->btcExchange();
}

Bitcoin::~Bitcoin(){}

//METHODS
bool Bitcoin::validationMonth(std::string month){
	for (size_t i = 0; i < month.size(); i++){
		if (!(std::isdigit(month[i])))
			return false;
	}
	int _month = atoi(month.c_str());
	return (_month <= 12  && _month > 0);
}

bool Bitcoin::validationDay(std::string day, std::string month){
	for (size_t i = 0; i < day.size(); i++){
		if (!(std::isdigit(day[i])))
			return false;
	}
	int _day = atoi(day.c_str());
	int _month = atoi(month.c_str());
	int daysInMonth[] = DAYS;
	return (_day > 0 && _day <= daysInMonth[_month]);
}

bool Bitcoin::parseDate(std::string date){
	std::string _month;
	std::string _day;
	std::string _year;
	size_t i = 0;


	while(date[i] && date[i] != '-'){
		if(!std::isdigit(date[i]))
			return false;
		_year += date[i];
		i++;
	}
	i++;
	while(date[i] && date[i] != '-'){
		_month += date[i];
		i++;
	}
	i++;
	while(date[i]){
		_day += date[i];
		i++;
	}
	if (_month.empty() || _day.empty() || _year.empty())
		return false;
	if (!validationMonth(_month) || !validationDay(_day, _month))
		return false;
	return true;
}


std::string Bitcoin::previouslyDate(std::string date){
	std::map<std::string, float>::iterator it = _database.lower_bound(date);
	if (it == _database.begin())
		throw NotFoundPreviouslyDateException();
	--it;
	return it->first;
}

void Bitcoin::btcExchange(){
		for (std::map<std::string, float>:: iterator it = _dataInput.begin();
			it != _dataInput.end(); it++){
			std::string date = it->first;
			float price = it->second;
			try{

				if (!parseDate(it->first))
					throw NotValidFormatDateException();
				if(_database.find(date) == _database.end())
					date = previouslyDate(date);
				if (std::isnan(price))
					throw NotValidFormatException();
				if (price > LIMIT_AMOUNT)
					throw NotValidFormatMultierException();
				if	(price < 0)
					throw NegativeAmountException();
				float total = price * _database[date];
				std::cout << date << " => " << price << " = " << total << std::endl;
			}
			catch(const std::exception &e){
				std::cout << "Error: " << e.what();
				if (dynamic_cast<const Bitcoin::NotValidFormatDateException*>(&e))
					std::cout <<  date << price;
				std::cout << std::endl;
				continue;
			}
	}

}
