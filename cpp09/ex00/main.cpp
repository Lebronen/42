/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:02:07 by rshay             #+#    #+#             */
/*   Updated: 2024/09/03 15:33:45 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <ctime>
#include <map>

int main(int argc, char const *argv[])
{
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}
	std::ifstream input(argv[1]);
	if (!input || input.bad() || !input.is_open())
	{
		std::cout << "Failed to open input file." << std::endl;
		return 2;
	}
	std::string datafile = "./data.csv";
	try
	{
		BitcoinExchange btc(datafile.c_str());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 3;
	}
	


}
