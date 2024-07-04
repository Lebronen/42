/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:50:22 by lebronen          #+#    #+#             */
/*   Updated: 2024/07/04 11:50:24 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat samuel("Samuel", 1);
	Intern vincent;
	AForm* form;

	form = vincent.makeForm("robotomy request", "Bender");
	form->beSigned(samuel);
	form->execute(samuel);
	delete form;

	try {
		form = vincent.makeForm("burger king", "Steve");
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
