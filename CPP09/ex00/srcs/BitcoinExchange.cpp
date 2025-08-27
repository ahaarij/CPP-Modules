#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	this->operator=(copy);
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	(void)copy;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	;
}



void BitcoinExchange::readDatabase()
{
	std::ifstream input;
	std::string database;
	input.open("./data.csv");
	while(!input.eof())
	{
		input >> database;
		std::string date = database.substr(0, 10).erase(4, 1).erase(6, 1);
		float rate = 0.0;
		std::stringstream convert;
		convert << database.substr(11);
		convert >> rate;
		_database.insert(std::make_pair(date, rate));
	}
	input.close();
}

void BitcoinExchange::printDatabase()
{
    std::map<std::string, float>::iterator it;
    for (it = _database.begin(); it != _database.end(); ++it) {
        std::cout << "Date: " << it->first << ", Rate: " << it->second << std::endl;
    }
}

void BitcoinExchange::printOutput(std::string inputdate, float btcs)
{
    std::map<std::string, float>::iterator it = this->_database.lower_bound(inputdate);
    
	if(it == this->_database.end()) // should hypotheticallyl be the last date if its at the end
		--it;
    else if (it != this->_database.begin() && it->first != inputdate) // lower if not exatc match
		--it;
    else if (it == this->_database.begin() && it->first != inputdate){
		std::cerr << "Invalid Date Format : Earlier than earliest date in database\n";
		return ;
	}

    std::cout << inputdate.insert(4, "-").insert(7, "-") << " => " 
              << std::fixed << std::setprecision(2) << btcs 
              << " = " << std::fixed << std::setprecision(2) 
              << btcs * it->second << "\n";
}

int		BitcoinExchange::Parsing(int month, int day, std::string raate, float rate, std::string line)
{
	size_t i = line.find("|");
	if(line[i + 1] != ' ' || line[i - 1] != ' ') // bbefore after
	{
		std::cerr << "Invalid Pipe\n";
		return (-1);
	}
	if(line.substr(4, 1) != "-" && line.substr(7, 1) != "-") //date dashes
	{
		std::cerr << "Invalid Date Format\n";
		return (-1);
	}
	int count = 0;
	for(size_t j = 0; j < raate.length(); j++) // 
	{
		if(raate[0] == '.') //no .5, more like 0.5
		{
			std::cerr << "Invalid Rate Formattt\n";
			return (-1);
		}
		if(raate[j] == '.') // counts how many dec
			count++;
		if(!(isdigit(raate[j])) && raate[j] != '.' && (count == 1 || count == 0))
		{
			std::cerr << "Invalid Rate Format\n";
			return (-1);
		}
	}
	int month_lim[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(month < 1 || month > 12)
	{
		std::cerr << "Invalid Date Format\n";
		return (-1);
	}
	if(day > month_lim[month - 1] || day < 1)
	{
		std::cerr << "Out of month range\n";
		return (-1);
	}
	if(rate < 0.00 || rate > 1000.00)
	{
		std::cerr << "Rate out of Range\n";
		return (-1);
	}
	return (0);
}

void	BitcoinExchange::readInput(std::string file)
{
	std::ifstream	input;
	std::string		line;

	input.open(file.c_str());
	if(input.fail())
	{
		std::cerr << "Error: could not open file\n";
		input.close();
		exit(0);
	}
	while(!input.eof())
	{
		std::string date;
		std::getline(input, line);
		if(line[0] == '\0')
		{
			std::cerr << "Error: Empty Line!\n";
			// input.close();
			// exit(0);
			continue;
		}

		std::string lowercase_line = line;
		std::transform(lowercase_line.begin(), lowercase_line.end(), lowercase_line.begin(), ::tolower);
		

		//removing spaces in header to compare
		lowercase_line.erase(std::remove(lowercase_line.begin(), lowercase_line.end(), ' '), lowercase_line.end());

		if (lowercase_line == "date|value" || lowercase_line == "date,value" || lowercase_line == "date|exchange_rate" || lowercase_line == "date,exchange_rate")
			continue;
		
		int year = 0;
		int month = 0;
		int day = 0;
		std::stringstream y,m,d;
		y << line.substr(0, 4);
		m << line.substr(5, 2);
		d << line.substr(8, 2);
		y >> year;
		m >> month;
		d >> day;
		if(line.length() < 14)
		{
			std::cerr << "Invalid Format!" << std::endl;
			continue;
		}
		std::string rate = line.substr(13, line.find('\0'));

		float btc = 0.00;
		std::stringstream bit;
		bit << rate;
		bit >> btc;
		std::stringstream oss;
		if (month < 10 && day < 10)
			oss << (year * 10) << (month * 10) << day;
		else if (day < 10)
			oss << year << (month * 10) << day;
		else if (month < 10)
			oss << (year * 10) << month << day;
		else
			oss << year << month << day;
		date = oss.str();
		if(Parsing(month, day, rate, btc, line) == 0)
			printOutput(date, btc);
	}
}