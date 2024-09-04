/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:01:42 by rshay             #+#    #+#             */
/*   Updated: 2024/09/04 16:23:13 by rshay            ###   ########.fr       */
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
#include <cstring>

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
		time_t stringToDate(std::string sdate);
		float valueAtDate(time_t date);

		// Attributes
		std::map<time_t, double> dic;

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
