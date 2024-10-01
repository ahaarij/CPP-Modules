/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:39:10 by ahaarij           #+#    #+#             */
/*   Updated: 2024/09/30 17:29:38 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <fstream>

int	open_files(std::string inname, std::string outname, std::ifstream *infile, std::ofstream *outfile)
{
	(*infile).open(inname.c_str(), std::fstream::in);
	(*outfile).open(outname.c_str(), std::fstream::out);
	if(!(*infile).is_open() || !(*outfile).is_open())
	{
		if(!(*infile).is_open())
			(*infile).close();
		if(!(*outfile).is_open())
			(*outfile).close();
		std::cout << "Cant open files!" << std::endl;
		return (1);
	}
	return (0);
}

int	search_and_replace(std::string str, std::ofstream& outfile, char **argv)
{
	int i = 0;
	int j = 0;
	while(i < (int)str.size())
	{
		j = str.find(argv[2], i);
		if(j != -1 && j == i)
		{
			outfile << argv[3];
			i += std::string(argv[2]).size() - 1;
		}
		else
			outfile << str[i];
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char c;
	std::string str;
	std::ifstream infile;
	std::ofstream outpfile;
	std::string inname;
	std::string outname;
	if(argc != 4)
		std::cout << "Invalid parameters!" << std::endl;
	else
	{
		if(std::string(argv[2]).empty())
		{
			std::cout << "Invalid parameters!" << std::endl;
			return (1);
		}
		inname = argv[1];
		outname = inname + ".replace";
		if(open_files(inname, outname, &infile, &outpfile) == 1)
			return (1);
		while(!infile.eof() && infile >> std::noskipws >> c)
			str += c;
		infile.close();
		search_and_replace(str, outpfile, argv);
		outpfile.close();
		std::cout << "Operation Successful!" << std::endl;
		return (0);
	}
	return (1);
}
