#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
        return (std::cerr << "Error: no arguments provided" << std::endl, 1);

    // list approach
    {
        std::cout << GREY << BOLD << UNDER << "Using std::list" << RESET << std::endl << std::endl;
        clock_t start = clock();
        std::list<std::pair<int,int> > lister;
        std::list<int> main_chain;

        int additional_value = -1; // if odd

        try
        {
            print_before(argv);
            create_pairs(&lister, argv, &additional_value); // pairs created {3, 8}, {5, 7}
            sort_pairs(&lister);   // pairs sorteddd {8, 3}, {7, 5}
            mergeSort(lister.begin(), lister.end(), 0); // 

            init_main_chain(&main_chain, lister);
			
            insert_into_main_chain(lister, &main_chain, additional_value);

            print_after(main_chain);
            clock_t end = clock();
            std::cout << CYAN << "Time taken to process : " << YELLOW << main_chain.size() << CYAN << " elements using " << GREEN << "std::list " << CYAN << ": " << PURPLE << UNDER << BOLD << static_cast<double>(end - start) / 1000 << " milliseconds" << RESET << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    std::cout << "\n\n";

    // deque approach
    {
	    std::cout << GREY << BOLD << UNDER << "Using std::deque" << RESET << std::endl << std::endl; 
		clock_t start = clock();
		std::deque< std::pair<int, int> > dequey;
		std::deque<int> main_chain;
		int additional_value = -1;

		try
		{
			print_before(argv);
			create_pairs2(&dequey, argv, &additional_value);
			sort_pairs2(&dequey);
			mergeSort2(dequey.begin(), dequey.end(), 0);
			init_main_chain2(&main_chain, dequey);
			insert_into_main_chain2(dequey, &main_chain, additional_value);
			print_after2(main_chain);
			
			clock_t end = clock();
            std::cout << CYAN << "Time taken to process : " << YELLOW << main_chain.size() << CYAN << " elements using " << GREEN << "std::deque " << CYAN << ": " << PURPLE << UNDER << BOLD << static_cast<double>(end - start) / 1000 << " milliseconds" << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}