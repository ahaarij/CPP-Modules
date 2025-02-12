#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include <math.h>

# define MIN_INT std::numeric_limits<int>::min()
# define MAX_INT std::numeric_limits<int>::max()
# define MIN_FLOAT std::numeric_limits<float>::min()
# define MAX_FLOAT std::numeric_limits<float>::max()
# define MIN_DOUBLE std::numeric_limits<double>::min()
# define MAX_DOUBLE std::numeric_limits<double>::max()

enum	e_type
{
	SPECIAL=0,
	CHAR = 1,
	INT = 2,
	FLOAT = 3,
	DOUBLE = 4,
	INVALID = -1
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &copy);
    public:
        static void convert(std::string toConvert);
};

e_type	whatType(std::string &str, size_t &len);

int		isFloat(std::string &str, size_t &len, size_t &dot);
int		isInt(std::string &str, size_t &len);
int		isSpecial(std::string &str);
int		isChar(std::string &str, size_t &len);

void    convertChar(std::string &str, size_t &len);
void    printSpecial(std::string &str);
void    convertDouble(const std::string &str);
void    convertFloat(const std::string &str);
void    convertInt(const std::string &str);