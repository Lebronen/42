/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:34:28 by lebronen          #+#    #+#             */
/*   Updated: 2024/07/04 11:34:30 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b1("Fabrice", 1);
		std::cout << b1;
		b1.incrementGrade();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b2;
		std::cout << b2;
		b2.decrementGrade();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b3("Damien", 160);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b4("Emile", -5);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
