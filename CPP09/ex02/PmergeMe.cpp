#include "PmergeMe.hpp"

void    print_before(char **argv)
{
    int i = 1;
    int error = 0;

    std::cout << "Before: ";
    while(argv[i])
    {
        std::string input = argv[i];
        std::cout << input << " ";
        if(input.size() > 10 || std::atol(input.c_str()) > INT_MAX || std::atol(input.c_str()) < INT_MIN)
            error = 1;
        for (size_t j = 0; j < input.size(); j++)
        {
            if(!isdigit(input[j]))
                error = 1;
        }
        i++;
    }
    std::cout << "\n";
    if(error == 1)
        throw std::runtime_error("Error: invalid input");
}

void create_pairs(std::list<std::pair<int, int> > *listy, char **argv, int *additional_value)
{
    int i = 1;

    while(argv[i])
    {
        if(argv[i] && argv[i + 1])
        {
            std::pair<int, int> pair_temp(std::atoi(argv[i]), std::atoi(argv[i + 1]));
            listy->push_back(pair_temp);
            i += 2;
        }
        else
        {
            *additional_value = std::atoi(argv[i]);
            i++;
        }
    }
}
void sort_pairs(std::list<std::pair<int, int> > *listy)
{
    for(std::list<std::pair<int, int> >::iterator it=listy->begin(); it != listy->end(); ++it)
    {
        if (it->first > it->second)
        {
            int temp = it->first;
            it->first = it->second;
            it->second = temp;
        }
    }
}

bool    custom_cmp(std::pair<int, int> a, std::pair<int, int> b)
{
    if(a.second < b.second)
        return (1);
    return (0);
}

void    mergeSort(std::list<std::pair<int, int> >::iterator start, std::list<std::pair<int, int> >::iterator end, size_t size)
{
    if(size == 0 && start != end)
        size = std::distance(start, end);
    if(size <= 1)
        return ;

    size_t firstHalf = size / 2;   // this and next line dividing into two halves
    size_t secondHalf = size - firstHalf; 
    std::list<std::pair<int, int> >::iterator center = start;

    std::advance(center, firstHalf); // send iter to middle

    mergeSort(start, center, firstHalf); // recursively sorts entire left half
    mergeSort(center, end, secondHalf); // recursively sorts entire right half
    std::inplace_merge(start, center, end, &custom_cmp); // sorts two sorted ranges into 1 sorted range, cmp is used for comparing seconds for two ranges
}

void    init_main_chain(std::list<int> *main_chain, std::list<std::pair<int, int> > listy)
{
    for(std::list<std::pair<int, int> >::iterator it = listy.begin(); it != listy.end(); ++it)
        main_chain->push_back(it->second); // so now that its sorted by seconds, its gonna push all the seconds into the main chain so the main chain is sortedd
                                            // in seconds
    
    if(!listy.empty())
        main_chain->push_front(listy.begin()->first);  // insert first of first pair here, so all that needs to be done is inserting the correct firsts, to their corresponding seconds.
}

void    insert_into_main_chain(std::list<std::pair<int, int> > listy, std::list<int> *main_chain, int additional_value)
{
    // 5 + (3 * 2) = 11 | 11 + (5 * 2) = 21 | 21 + (11 * 2) = 43
    // jacobsthal numbers used to determine what pairs to process first for efficiency
	size_t jacob[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765};
    int jacob_idx = 1;

    std::list<int>::iterator slice_delim_it;
    std::list<std::pair<int, int> >::iterator pair_it;
    std::list<std::pair<int, int> >::iterator last_jacob_it = listy.begin();

    while(jacob[jacob_idx] <= listy.size())
    {
        pair_it = listy.begin();
        std::advance(pair_it, jacob[jacob_idx] - 1); // iterate to the pair at pos of jacob - 1
        last_jacob_it = pair_it; // for keeping track

        int insertion_counter = 0;
        while(jacob[jacob_idx] - insertion_counter > jacob[jacob_idx - 1])
        {
            slice_delim_it = std::find(main_chain->begin(), main_chain->end(), pair_it->second);  // finds where the pair's second element is in the main chain
            binary_search_insertion(main_chain, slice_delim_it, pair_it->first);
            pair_it--;
            insertion_counter++; // ensures we stop at correct prev jacob number
        }
        jacob_idx++;
    }

    if(jacob[jacob_idx] != listy.size()) // if this is true theres still pairs at the end
    {
        pair_it = listy.end();
        if(pair_it != listy.begin())
            pair_it--;
        while(pair_it != last_jacob_it) // now wew working backwards inserting any pairs that mightve been skipped
        {
            slice_delim_it = std::find(main_chain->begin(), main_chain->end(), pair_it->second);
            binary_search_insertion(main_chain, slice_delim_it, pair_it->first);
            pair_it--;
        }
    }

    if(additional_value != - 1)
        binary_search_insertion(main_chain, main_chain->end(), additional_value);
}

void    binary_search_insertion(std::list<int> *main_chain, std::list<int>::iterator end, int val)
{
    std::list<int>::iterator place_to_insert = std::lower_bound(main_chain->begin(), end, val); // finds pos in chain where value is just under an element
    main_chain->insert(place_to_insert, val);
}

void    print_after(std::list<int> main_chain)
{
    std::cout << "After :";
    for(std::list<int>::iterator it = main_chain.begin(); it != main_chain.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void create_pairs2(std::deque<std::pair<int, int> > *deque, char **argv, int *additional_value)
{
	int i = 1;

	while (argv[i])
	{
		if (argv[i] && argv[i + 1])
		{
			std::pair<int, int> pair_temp(std::atoi(argv[i]), std::atoi(argv[i + 1]));
			deque->push_back(pair_temp);
			i += 2;
		}
		else
		{
			*additional_value = std::atoi(argv[i]);
			i++;
		}
	}
}

void sort_pairs2(std::deque<std::pair<int, int> > *deque)
{
	for (std::deque<std::pair<int, int> >::iterator it = deque->begin(); it != deque->end(); ++it)
	{
		if (it->first > it->second)
		{
			int temp = it->first;
			it->first = it->second;
			it->second = temp;
		}
	}
}

void mergeSort2(std::deque<std::pair<int, int> >::iterator start, std::deque<std::pair<int, int> >::iterator end, size_t size)
{
	if (size == 0 && start != end)
		size = std::distance(start, end);
	if (size <= 1)
		return;

	size_t firstHalf = size / 2;
	size_t secondHalf = size - firstHalf;
	std::deque<std::pair<int, int> >::iterator center = start + firstHalf;

	mergeSort2(start, center, firstHalf);
	mergeSort2(center, end, secondHalf);
	std::inplace_merge(start, center, end, &custom_cmp);
}

void init_main_chain2(std::deque<int> *main_chain, std::deque<std::pair<int, int> > dequey)
{
	for (std::deque<std::pair<int, int> >::iterator it = dequey.begin(); it != dequey.end(); ++it)
		main_chain->push_back(it->second);
	if (!dequey.empty())
		main_chain->push_front(dequey.begin()->first);
}

void binary_search_insertion2(std::deque<int> *main_chain, std::deque<int>::iterator end, int val)
{
	std::deque<int>::iterator place_to_insert = std::lower_bound(main_chain->begin(), end, val);
	main_chain->insert(place_to_insert, val);
}

void insert_into_main_chain2(std::deque<std::pair<int, int> > dequey, std::deque<int> *main_chain, int additional_value)
{
	size_t Jacobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765};
	int jacobsthal_idx = 1;

	std::deque<int>::iterator slice_delim_it;
	std::deque<std::pair<int, int> >::iterator pair_it;
	std::deque<std::pair<int, int> >::iterator last_jacob_it = dequey.begin();

	while (Jacobsthal[jacobsthal_idx] <= dequey.size())
	{
		pair_it = dequey.begin() + (Jacobsthal[jacobsthal_idx] - 1);
		last_jacob_it = pair_it;

		int insertion_counter = 0;
		while (Jacobsthal[jacobsthal_idx] - insertion_counter > Jacobsthal[jacobsthal_idx - 1])
		{
			slice_delim_it = std::find(main_chain->begin(), main_chain->end(), pair_it->second);
			binary_search_insertion2(main_chain, slice_delim_it, pair_it->first);
			pair_it--;
			insertion_counter++;
		}
		jacobsthal_idx++;
	}

	if (Jacobsthal[jacobsthal_idx] != dequey.size())
	{
		pair_it = dequey.end();
		if (pair_it != dequey.begin())
			pair_it--;
		while (pair_it != last_jacob_it)
		{
			slice_delim_it = std::find(main_chain->begin(), main_chain->end(), pair_it->second);
			binary_search_insertion2(main_chain, slice_delim_it, pair_it->first);
			pair_it--;
		}
	}

	if (additional_value != -1)
	{
		binary_search_insertion2(main_chain, main_chain->end(), additional_value);
	}
}

void print_after2(std::deque<int> main_chain)
{
	std::cout << "After: ";
	for (std::deque<int>::iterator it = main_chain.begin(); it != main_chain.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << '\n';
}

