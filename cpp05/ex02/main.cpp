/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:46:54 by lebronen          #+#    #+#             */
/*   Updated: 2024/07/08 12:43:52 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

	std::cout << "======Default Constructor test=======" << std::endl;

	try {
		PresidentialPardonForm form_1;
		std::cout << form_1 << std::endl;
		RobotomyRequestForm	form_2;
		std::cout << form_2 << std::endl;
		ShrubberyCreationForm form_3;
		std::cout << form_3 << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "======String / Copy Constructor test=======" << std::endl;

	try {
		PresidentialPardonForm form_1a("target_form1a");
		PresidentialPardonForm form_1b(form_1a);
		std::cout << form_1a << std::endl;
		std::cout << form_1b << std::endl;

	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "======Assignation Operator test=======" << std::endl;

	try {
		RobotomyRequestForm	form_2a("target_form2a");
		RobotomyRequestForm	form_2b("target_form2b");
		std::cout << form_2a << std::endl;
		std::cout << form_2b << std::endl;
		form_2b = form_2a;
		std::cout << form_2a << std::endl;
		std::cout << form_2b << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "======Execution Not Signed Boss Level test=======" << std::endl;

	try {
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm form_1("target_form1");
		std::cout << form_1 << std::endl;
		boss.executeForm(form_1);

		RobotomyRequestForm	form_2("target_form2");
		std::cout << form_2 << std::endl;
		boss.executeForm(form_2);


		ShrubberyCreationForm form_3("target_form3");
		std::cout << form_3 << std::endl;
		boss.executeForm(form_3);

	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "======Execution Not Signed Morron Level test=======" << std::endl;

	try {
		Bureaucrat morron("Morron", 150);
		PresidentialPardonForm form_1("target_form1");
		std::cout << form_1 << std::endl;
		morron.executeForm(form_1);

		RobotomyRequestForm	form_2("target_form2");
		std::cout << form_2 << std::endl;
		morron.executeForm(form_2);


		ShrubberyCreationForm form_3("target_form3");
		std::cout << form_3 << std::endl;
		morron.executeForm(form_3);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "======Execution Signed Boss Level test=======" << std::endl;

	try {
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm form_1("target_form1");
		std::cout << form_1 << std::endl;
		boss.signForm(form_1);
		boss.executeForm(form_1);

		RobotomyRequestForm	form_2("target_form2");
		std::cout << form_2 << std::endl;
		boss.signForm(form_2);
		boss.executeForm(form_2);
		boss.executeForm(form_2); //To check if it fails 1/2 times

		ShrubberyCreationForm form_3("target_form3");
		std::cout << form_3 << std::endl;
		boss.signForm(form_3);
		boss.executeForm(form_3);

	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "======Execution Signed Morron Level test=======" << std::endl;

	try {
		Bureaucrat signer("Signer", 1);
		Bureaucrat morron("Morron", 150);
		PresidentialPardonForm form_1("target_form1");
		std::cout << form_1 << std::endl;
		signer.signForm(form_1);
		morron.executeForm(form_1);

		RobotomyRequestForm	form_2("target_form2");
		std::cout << form_2 << std::endl;
		signer.signForm(form_2);
		morron.executeForm(form_2);


		ShrubberyCreationForm form_3("target_form3");
		std::cout << form_3 << std::endl;
		signer.signForm(form_3);
		morron.executeForm(form_3);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
