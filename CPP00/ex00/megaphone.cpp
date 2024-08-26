/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:12:25 by ahaarij           #+#    #+#             */
/*   Updated: 2024/08/20 18:58:32 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if(argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else if(argc > 1)
		for(int i = 1; argv[i]; i++)
			for(int j = 0; argv[i][j]; j++)
				std::cout << (char)toupper(argv[i][j]);
	std::cout <<"\n";
}
