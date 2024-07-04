/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:42:53 by lebronen          #+#    #+#             */
/*   Updated: 2024/07/04 11:42:57 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", "Default", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &source)
	: AForm(source) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &source) {
	AForm::operator=(source);
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	AForm::checkRequirements(executor);

	std::cout << "BRRRRRR....KKRKRRKRKKRKRKRRRKR" << std::endl;

	srand(time(NULL));
	bool success = rand() & 1;
	
	std::cout << "Robotomy of " << _target << (success ? " was a success" : " has failed") << "." << std::endl;
}
