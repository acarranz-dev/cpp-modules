#include "ReadCSV.hpp"
#include "cstdlib"

//EXCEPTIONS
const char *ReadCSV::OpenFileException::what() const throw(){
	return "could not open database file.";
}

//COSNTRUCTORS
ReadCSV::ReadCSV() {}

ReadCSV::ReadCSV(const std::string file, const char separator) {
	_csv = openCSV(file, separator);
}

ReadCSV::ReadCSV(const ReadCSV &other) : _csv(other._csv) {}

ReadCSV &ReadCSV::operator=(const ReadCSV &other){
	if (this != &other)
		_csv = other._csv;
	return *this;
}
ReadCSV::~ReadCSV() {}

//METHODS
static std::string trim(const std::string &str){
	size_t first = str.find_first_not_of(" \t\n\r");
	if (first == std::string::npos)
		return "";
	size_t last = str.find_last_not_of(" \t\n\r");
	return str.substr(first, (last - first + 1));
}

std::map<std::string, float> ReadCSV::loadCSV(std::map<std::string, float> &fileData, std::string line, char toFind){
	size_t pos = line.find(toFind);
	if (pos == 0)
		return fileData;
	if (pos == std::string::npos){
			std::string date = line;
			fileData[date] = std::numeric_limits<float>::quiet_NaN();
	}
	else{
		std::string date = trim(line.substr(0, pos));
		float value = std::atof( line.substr(pos +1).c_str());
		fileData[date] = value;
	}
	return fileData;
}

std::map<std::string, float> ReadCSV::openCSV(const std::string _file, const char separator){
	std::map<std::string, float> fileData;
	std::ifstream file(_file.c_str());
	if (!file.is_open())
		throw OpenFileException();
	std::string line;
	std::getline(file, line);
	while(std::getline(file, line)){
		size_t pos = std::string::npos;
		(void)pos;
		if (line.empty())
			continue;
		fileData = loadCSV(fileData, line, separator);
	}
	return fileData;
}
//GETTERS
const std::map<std::string, float> &ReadCSV::getData() const{
	return _csv;
}
