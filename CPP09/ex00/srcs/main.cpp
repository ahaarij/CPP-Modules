#include "../includes/BitcoinExchange.hpp"

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
			a.readInput(argv[1]);
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cout << "Error: Not Enough Arguments`" << std::endl;
}

// shouldnt beable to use more than 1000 rate and less than 0