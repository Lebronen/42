/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:01:33 by rshay             #+#    #+#             */
/*   Updated: 2024/09/04 16:42:10 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constructors
BitcoinExchange::BitcoinExchange()
{
	std::cout << "\e[0;33mDefault Constructor called of BitcoinExchange\e[0m" << std::endl;

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of BitcoinExchange\e[0m" << std::endl;
}

BitcoinExchange::BitcoinExchange(const char *infile)
{
	std::cout << "\e[0;33mFile Constructor called of BitcoinExchange\e[0m" << std::endl;
	std::ifstream data(infile);
	if (!data || data.bad() || !data.is_open())
	{
		throw BitcoinExchange::WrongFileException();
	}
	std::string line;

	while (std::getline(data, line)) {
		//std::cout << line << std::endl;
		std::string sdate = line.substr(0, line.find(","));
		std::string svaleur = line.substr(line.find(",") + 1, line.length());
		time_t date = stringToDate(sdate);
		double valeur = atof(svaleur.c_str());
		dic[date] = valeur;
	}
}

// Destructor
BitcoinExchange::~BitcoinExchange()
{
	std::cout << "\e[0;31mDestructor called of BitcoinExchange\e[0m" << std::endl;
}

// Functions
time_t BitcoinExchange::stringToDate(std::string sdate)
{
	char delimiter;
	std::istringstream is(sdate);
	int d, m, y;
	is >> y >> delimiter >> m >> delimiter >> d;
	struct tm date;
	memset(&date, 0, sizeof(struct tm));
	date.tm_mday = d;
	date.tm_mon = m - 1;
	date.tm_year = y - 1900;
	date.tm_isdst = -1;
	time_t when = mktime(&date);
	return (when);
}

float BitcoinExchange::valueAtDate(time_t date)
{
	std::map<time_t,double>::iterator it;
	time_t min = date;
	time_t emin = date;
	for (it = dic.begin(); it != dic.end(); it++) {
		if (date - it->first >= 0) {
			if (date - it->first < min) {
				min = date - it->first;
				emin = it->first;
			}
		}
	}
	return dic[emin];
}

// Operators
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &assign)
{
	(void) assign;
	return *this;
}

// Exceptions
const char *BitcoinExchange::WrongFileException::what() const throw() { return "Failed to open data file.";}
