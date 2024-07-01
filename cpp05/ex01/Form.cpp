/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:51:06 by lebronen          #+#    #+#             */
/*   Updated: 2024/07/01 16:29:13 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("default"), _grade_to_sign(150), _grade_to_execute(150), _signed(0) 
{
    std::cout << "default form created" << std::endl;
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute), _signed(0)
{
	if (_grade_to_sign > 150 || _grade_to_execute > 150)
		throw (Form::GradeTooLowException());
	else if (_grade_to_sign < 1 || _grade_to_execute < 1)
		throw (Form::GradeTooHighException());
	else
		std::cout << "form " << *this << " created" << std::endl;
}

Form::Form(Form const & cpy) : _name(cpy.getName()), _grade_to_sign(cpy.getGradeToSign()), _grade_to_execute(cpy.getGradeToExecute()), _signed(cpy.getSigned())
{
	std::cout << "form created with copy" << std::endl;
}

Form::~Form(void) {
    std::cout << "form " << *this << " destructed" << std::endl;
}

const std::string Form::getName(void) const {
    return this->_name;
}

int	Form::getGradeToSign(void) const {
    return this->_grade_to_sign;
}

int	Form::getGradeToExecute(void) const {
    return this->_grade_to_execute;
}

bool Form::getSigned(void) const {
    return this->_signed;
}

void Form::setSigned( const bool new_value) {
    this->_signed = new_value;
}

void Form::be_signed(Bureaucrat & ref) {
	int	grade = ref.getGrade();

	if (grade > _grade_to_sign)
	{
		throw (Form::GradeTooLowException());
		return ;
	}
	_signed = true;
	std::cout << *this << " was just signed by the bureaucrat " << ref.getName() << " with a grade " << ref.getGrade() << std::endl;
}

const char* Form::Exception::what() const throw() {
	return ("FormException");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("the grade is too low");
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("the grade is too high");
};

std::ostream & operator<<( std::ostream & o, Form const & rhs) {
	o << "Form " << rhs.getName() << " having a grade_to_sign " << rhs.getGradeToSign() << " and a grade_to_execute "
		<< rhs.getGradeToExecute() << " with signed equal to " << rhs.getSigned();
	return (o);
}
