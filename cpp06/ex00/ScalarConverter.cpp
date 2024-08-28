/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:28:48 by rshay             #+#    #+#             */
/*   Updated: 2024/07/11 13:00:38 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>
#include <iomanip>
#include <math.h>

int search(std::string str, char c) {
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == c)
			return (1);
	}
	return (0);
}

int only_zero(std::string str) {
	int point = str.find('.');
	for (size_t i = point + 1; i < str.length(); i++) {
		if (str[i] != '0') {
			std::cout << "diff :" << str[i] << std::endl;
			return (0);
		}
	}
	return (1);
}

void ScalarConverter::convert(std::string value) {
	char type;
	std::stringstream ss(value);
	long double ld;
	ss >> ld;
	if (!search(value, '.') || only_zero(value))
		type = 'i';
	else if (!search(value, 'f'))
		type = 'd';
	else
		type = 'f';
	std::cout << "type : " << type << std::endl;
	if (ld < 32)
		std::cout << "undisplayable character" << std::endl;
	else {
		char c = static_cast<char>(ld);
		std::cout << "char : " << c << std::endl;
	}
	int i = static_cast<int>(ld);
	std::cout << "int : " << i << std::endl;
	float f = static_cast<float>(ld);
	if (type == 'i')
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "float : " << f << "f" << std::endl;
	double d = static_cast<double>(ld);
	std::cout << "double : " << d << std::endl;
}
