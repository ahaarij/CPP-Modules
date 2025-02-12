#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    ;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    *this = copy;
}

ScalarConverter::~ScalarConverter()
{
    ;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
    (void)copy;
    return *this;
}

void ScalarConverter::convert(std::string str)
{
    size_t len = str.length();
    e_type type = whatType(str, len);
    switch(type)
    {
        case INVALID:
		{
            std::cout << "Invalid Input!" << std::endl;
			break;
		}
        case SPECIAL:
		{
			printSpecial(str);
			break;
		}
		case CHAR:
		{
			convertChar(str, len);
			break;
		}
		case INT:
		{
			convertInt(str);
			break;
		}
		case FLOAT:
		{
			convertFloat(str);
			break;
		}
		case DOUBLE:
		{
			convertDouble(str);
			break;
		}
    }
}
