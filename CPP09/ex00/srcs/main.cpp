#include "../includes/BitcoinExchange.hpp"

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

void	BitcoinExchange::readInput(std::string file)
{
	std::ifstream	input;
	std::string		line;

	input.open(file);
	if(input.fail())
	{
		std::cerr < "Error: could not open file" << std::endl;
		input.close();
		exit(0);
	}
	while(!input.eof())
	{
		std::string date;
		std::getline(input, line);
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

		float btc = 0.0
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	BitcoinExchange a;
	if(argc == 2)
	{
		try
		{
			a.readDatabase();
			a.printDatabase();
			a.readInput(argv[1]);
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cout << "Error: could not open file" << std::endl;
}