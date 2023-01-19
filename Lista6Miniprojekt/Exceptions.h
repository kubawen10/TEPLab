#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class CouldNotOpenFileException : public std::runtime_error {
public :
	CouldNotOpenFileException(const std::string& pathToFile) : std::runtime_error( std::string("Could not open file: ") + pathToFile) {}
};

class FileParsingException : public std::runtime_error {
public:
	FileParsingException(const std::string& msg) : std::runtime_error(msg) {}
};

class InvalidArgumentException : public std::runtime_error {
public:
	InvalidArgumentException(const std::string& msg) : std::runtime_error(msg) {}
};

#endif