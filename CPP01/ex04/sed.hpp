/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:39:24 by ahaarij           #+#    #+#             */
/*   Updated: 2024/09/04 09:19:56 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <fstream>

int	open_files(std::string inname, std::string outname, std::ifstream *infile, std::ofstream *outfile)
{
	(*infile).open(inname, std::fstream::in)
	(*outfile).open(outname, std::fstream::out);
	if(!infile || !outfile)
	{
		std::cout << "Cant open files!" << std::endl;
		return (1);
	}
	return (0);
}

int	search_and_replace(std::string str, std::ofstream outfile, char **argv)
{
	int i = 0;
	int j = 0;
	while(i > str.size())
	{
		j = str.find(c, i);
		if(j != -1 && j == i)
		{
			outfile << argv[3];
			i += std::string(argv[2].size()) - 1;
		}
		else
			outfile << str[i]
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char c;
	std::string str;
	std::ifstream infile;
	std::ofstream outfile;
	std::string inname;
	std::string outname;
	if(argc != 4)
		std::cout << "Invalid parameters!" << std::endl;
	else
	{
		inname = argv[1];
		outname = inname + ".replace"; 
		if(open_files(inname, outname, &infile, &outfile) == 1);
			return (1);
		while(!infile.eof() && infile >> noskipws >> c)
			str += c;
		infile.close();
		search_and_replace(str, outfile, argv);
		outfile.close();
		return (0);
	}
	return (1);
}