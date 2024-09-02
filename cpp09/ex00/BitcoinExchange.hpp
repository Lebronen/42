#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>

class BitcoinExchange
{
	public:
		// Constructors
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);

		// Destructor
		~BitcoinExchange();

		// Operators
		BitcoinExchange & operator=(const BitcoinExchange &assign);

	private:

};

#endif
