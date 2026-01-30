#ifndef READCSV_HPP
#define READCSV_HPP

#include <fstream>
#include <cmath>
#include <limits>
#include <map>

class ReadCSV{
private:
	std::map<std::string, float> _csv;
public:
	ReadCSV();
	ReadCSV(const std::string file, const char separator);
	ReadCSV(const ReadCSV &other);
	ReadCSV &operator=(const ReadCSV &other);
	~ReadCSV();

	class OpenFileException : public std::exception{
		const char *what() const throw();
	};

	std::map<std::string, float> openCSV(const std::string _file,
		const char separator);
	std::map<std::string, float> loadCSV(std::map<std::string, float> &fileData,
		std::string line, char toFind);

	const std::map<std::string, float> &getData() const;
};

#endif
