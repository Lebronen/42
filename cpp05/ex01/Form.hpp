/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:26:37 by lebronen          #+#    #+#             */
/*   Updated: 2024/07/01 16:19:37 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP

# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form {

    // attributs
    private :
    
    const std::string _name;
    const int _grade_to_sign;
    const int _grade_to_execute;
    bool _signed;

    // constructeurs
    public :

    Form(void);
    Form(std::string name, int grade_to_sign, int grade_to_execute);
    Form(Form const &cpy);

    // fonctions
    public :
    
    Form & operator=(Form const & ref);
    const std::string	getName( void ) const;
	int	getGradeToSign( void ) const;
    int	getGradeToExecute( void ) const;
    bool getSigned( void ) const;
    void setSigned( const bool new_value);
    void be_signed(Bureaucrat & ref);
    
    // exceptions
    
    class Exception : public std::exception {
        public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public Form::Exception {
        public:
        virtual const char* what() const throw();
    };
    
    class GradeTooHighException : public Form::Exception {
        public:
        virtual const char* what() const throw();
    };

    // destructor

    ~Form(void);
    
};

// << overload
std::ostream & operator<<( std::ostream & o, Form const & rhs);

#endif