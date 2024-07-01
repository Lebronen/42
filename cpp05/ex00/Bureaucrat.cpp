/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:41:16 by lebronen          #+#    #+#             */
/*   Updated: 2024/07/01 12:16:11 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("noName"), _grade(150)
{
    std::cout << "Default bureaucrat created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade > 150)
        throw (Bureaucrat::GradeTooLowException());
    else if (grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    else {
        this->_grade = grade;
        std::cout << "Bureaucrat " << _name << " with grade " << _grade << " created" << std::endl;
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const &cpy) {
    *this = cpy;
    std::cout << "Bureaucrat created from copy" << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
    std::cout << "Bureaucrat " << _name << " with grade " << _grade << " destroyed" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & ref)
{
	this->_grade = ref.getGrade();
	return (*this);
}


void Bureaucrat::incrementGrade(void) {
    if (this->_grade - 1 < 1)
        throw (Bureaucrat::GradeTooHighException());
    else
        this->_grade -= 1;
}

void Bureaucrat::decrementGrade(void) {
    if (this->_grade + 1 > 150)
        throw (Bureaucrat::GradeTooLowException());
    else
        this->_grade += 1;
}

std::string Bureaucrat::getName(void) const {
    return this->_name;
}

int Bureaucrat::getGrade(void) const {
    return this->_grade;
}

const char* Bureaucrat::Exception::what() const throw()
{
	return ("BureaucratException");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Cannot get a grade > 150!");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Cannot get a grade < 1!");
};

std::ostream &operator<<( std::ostream & o, Bureaucrat const & rhs)
{
    o << "Bureaucrat " << rhs.getName() << " has a grade " << rhs.getGrade();
	return (o);
}
