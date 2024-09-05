/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:02:07 by rshay             #+#    #+#             */
/*   Updated: 2024/09/05 10:02:16 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <ctime>
#include <map>

bool formatDateValide(std::string sdate)
{
	if (sdate.length() != 10)
		return false;
	for (int i = 0; i < 4; i++) {
		if (sdate[i] < 48 || sdate[i] > 57) {
			return false;
		}
	}
	if (sdate[4] != '-') {
		return false;
	}
	for (int i = 5; i < 7; i++) {
		if (sdate[i] < 48 || sdate[i] > 57) {
			return false;
		}
	}
	if (sdate[7] != '-') {
		return false;
	}
	for (int i = 8; i < 10; i++) {
		if (sdate[i] < 48 || sdate[i] > 57) {
			return false;
		}
	}
	return true;
}

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
		std::string line;
		std::getline(input, line);
		while (std::getline(input, line))
		{
			if (line[10] != ' ' || line[11] != '|' || line[12] != ' ') {
				std::cerr << "Error: invalid line format" << std::endl;
			}
			else
			{
				std::string sdate = line.substr(0, line.find("|") - 1);
				//std::cout << sdate << std::endl;
				if (!formatDateValide(sdate))
					std::cerr << "Error: Date format not valide" << std::endl;
				std::string svaleur = line.substr(line.find("|") + 2, line.length());
				double valeur = atof(svaleur.c_str());
				if (valeur > 1000)
				{
					std::cerr << "Error: too large a number" << std::endl;
				}
				else if (valeur < 0) {
					std::cerr << "Error: not a positive number" << std::endl;
				}
				else
				{
					time_t date = btc.stringToDate(sdate);
					float price = btc.valueAtDate(date);
					std::cout << sdate << " => " << price * valeur << std::endl;
				}
			}
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 3;
	}


}
