/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:29:42 by lebronen          #+#    #+#             */
/*   Updated: 2024/09/05 14:29:43 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Constructors
RPN::RPN()
{
	final_value = 0;
	std::cout << "\e[0;33mDefault Constructor called of RPN\e[0m" << std::endl;
}

RPN::RPN(const RPN &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of RPN\e[0m" << std::endl;
}

RPN::RPN(std::string expr)
{
	std::stack<int> pile;
	final_value = 0;
	for (unsigned long i = 0; i < expr.length(); i++) {
		if ((expr[i] < 48 || expr[i] > 57) && expr[i] != '+' && expr[i] != '-' && expr[i] != '*' && expr[i] != '/' && expr[i] != ' ')
			throw RPN::InvalidSymbolException();
		else {
			if (expr[i] >= 48 && expr[i] <= 57)
				pile.push(expr[i] - 48);
			else {
				if (expr[i] != ' ' && pile.size() < 2)
					throw RPN::EmptyStackException();
				else {
					if (expr[i] == '+') {
						int x = pile.top();
						pile.pop();
						int y = pile.top();
						pile.pop();
						int res = x + y;
						pile.push(res);
					}
					else if (expr[i] == '*') {
						int x = pile.top();
						pile.pop();
						int y = pile.top();
						pile.pop();
						int res = x * y;
						pile.push(res);
					}
					else if (expr[i] == '-') {
						int x = pile.top();
						pile.pop();
						int y = pile.top();
						pile.pop();
						int res = y - x;
						pile.push(res);
					}
					else if (expr[i] == '/') {
						int x = pile.top();
						pile.pop();
						int y = pile.top();
						pile.pop();
						int res = y / x;
						pile.push(res);
					}
				}
			}
		}
	}
	if (pile.size() > 1)
		throw RPN::NotEnoughOperationsException();
	else
		final_value = pile.top();

}

// Destructor
RPN::~RPN()
{
	std::cout << "\e[0;31mDestructor called of RPN\e[0m" << std::endl;
}

// Operators
RPN & RPN::operator=(const RPN &assign)
{
	(void) assign;
	return *this;
}

// Getters / Setters
int RPN::getValue()
{
	return final_value;
}

// Exceptions
const char * RPN::EmptyStackException::what() const throw()
{
	return "not enough numbers for this operation";
}

const char * RPN::InvalidSymbolException::what() const throw ()
{
	return "invalid symbol in reversed polish notation";
}

const char * RPN::NotEnoughOperationsException::what() const throw ()
{
	return "not enough operations";
}
