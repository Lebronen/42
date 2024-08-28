/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:40:50 by rshay             #+#    #+#             */
/*   Updated: 2024/07/11 13:13:13 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void science(std::string str) {
	std::cout << "char : undisplayable character" << std::endl;
	std::cout << "int : undisplayable character" << std::endl;
	if (!str.compare("inf")) {
		std::cout << "float : inff" << std::endl;
		std::cout << "double : inf" << std::endl;
	}
	else if (!str.compare("inff")) {
		std::cout << "float : inff" << std::endl;
		std::cout << "double : inff" << std::endl;
	}
	else if (!str.compare("+inf")) {
		std::cout << "float : +inff" << std::endl;
		std::cout << "double : +inf" << std::endl;
	}
	else if (!str.compare("+inff")) {
		std::cout << "float : +inff" << std::endl;
		std::cout << "double : +inff" << std::endl;
	}
	else if (!str.compare("-inf")) {
		std::cout << "float : -inff" << std::endl;
		std::cout << "double : -inf" << std::endl;
	}
	else if (!str.compare("-inff")) {
		std::cout << "float : -inff" << std::endl;
		std::cout << "double : -inff" << std::endl;
	}
	else if (!str.compare("nan")) {
		std::cout << "float : nanf" << std::endl;
		std::cout << "double : nan" << std::endl;
	}
	else if (!str.compare("nanf")) {
		std::cout << "float : nanf" << std::endl;
		std::cout << "double : nanf" << std::endl;
	}

}

int is_nbr(std::string str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] < 48 || str[i] > 57) {
			if (str[i] != '.' && str[i] != '-')
				return (0);
		}
	}
	return (1);
}

int is_science(std::string str) {
	if (!str.compare("inf") || !str.compare("+inf")
	|| !str.compare("-inf") || !str.compare("inff")
	|| !str.compare("+inff") || !str.compare("-inff")
	|| !str.compare("nan") || !str.compare("nanf")) {
		science(str);
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "invalid input" << std::endl;
		return (1);
	}
	if (is_science(argv[1]))
		return (0);
	else if (!is_nbr(argv[1])) {
		std::cout << "invalid input" << std::endl;
		return (1);
	}

	ScalarConverter::convert(argv[1]);

}
