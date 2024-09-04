#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
#include <stack>
#include <stdio.h>
#include <stdlib.h>

class RPN
{
	public:
		// Constructors
		RPN();
		RPN(const RPN &copy);
		RPN(std::string expr);

		// Destructor
		~RPN();

		// Operators
		RPN & operator=(const RPN &assign);

		// Getters / Setters
		int getValue();

		// Exceptions
		class EmptyStackException : public std::exception {
			virtual const char* what() const throw();
		};
		class InvalidSymbolException : public std::exception {
			virtual const char*what() const throw();
		};
		class NotEnoughOperationsException : public std::exception {
			virtual const char* what() const throw();
		};

	private:
		int final_value;

};

#endif
