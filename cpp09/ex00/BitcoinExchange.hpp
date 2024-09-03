/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:01:42 by rshay             #+#    #+#             */
/*   Updated: 2024/09/03 15:10:46 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <map>
#include <stdbool.h>
#include <math.h>

class BitcoinExchange
{
	public:
		// Constructors
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange(const char *infile);

		// Destructor
		~BitcoinExchange();

		// Functions
		float valueAtDate(struct tm date);
		bool compareDate(struct tm date1, struct tm date2);
		struct tm stringToDate(std::string sdate);

		// Attributes
		std::map<struct tm, double> dic;

		// Operators
		BitcoinExchange & operator=(const BitcoinExchange &assign);

		// Exceptions
		class WrongFileException : public std::exception {
			public:
            virtual const char *what() const throw();
		};

	private:

};

#endif
