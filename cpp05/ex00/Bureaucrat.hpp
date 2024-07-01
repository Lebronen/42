/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:23:05 by lebronen          #+#    #+#             */
/*   Updated: 2024/07/01 12:16:06 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
    
    // attributs
    private : std::string _name;
    private : int _grade;

    // constructeurs
    public :

    Bureaucrat(void);
    Bureaucrat(Bureaucrat const &cpy);
    Bureaucrat(std::string name, int grade);

    // fonctions
    public :

    std::string getName(void) const;
    int getGrade(void) const;
    Bureaucrat &operator=(Bureaucrat const & ref);
    void incrementGrade(void);
    void decrementGrade(void);

    // exceptions
    class Exception : public std::exception {
		public:
		virtual const char* what() const throw();
	};

    class GradeTooLowException : public Bureaucrat::Exception {
        public:
        virtual const char* what() const throw();
    };
    
    class GradeTooHighException : public Bureaucrat::Exception {
        public:
        virtual const char* what() const throw();
    };
    
    // destructeur
    ~Bureaucrat(void);

};

std::ostream &operator<<( std::ostream & o, Bureaucrat const & rhs);

#endif