/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:49:29 by lebronen          #+#    #+#             */
/*   Updated: 2024/07/04 11:49:31 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		const int _signGrade;
		const int _executeGrade;
		bool _isSigned;
	
	protected:
		const std::string _target;
		void checkRequirements(const Bureaucrat& bureaucrat) const;

	public:
		AForm();
		AForm(const AForm& form);
		AForm(std::string name, std::string target, int signGrade, int executeGrade);
		AForm& operator=(const AForm& form);
		virtual ~AForm();

		std::string getName() const;
		std::string getTarget() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		bool isSigned() const;
		
		void beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class NotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif