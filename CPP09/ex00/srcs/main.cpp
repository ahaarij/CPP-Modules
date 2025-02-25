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
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cout << "Error: could not open file" << std::endl;
}