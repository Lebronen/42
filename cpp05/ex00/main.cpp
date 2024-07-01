/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:44:22 by lebronen          #+#    #+#             */
/*   Updated: 2024/07/01 13:31:18 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {

    // default Bureaucrat
    Bureaucrat def;
    std::cout << "default : " << def << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    // grade too high at construction
    std::cout << "grade too high" << std::endl;
    try {    
        Bureaucrat high("HighHopes", 265);
    }
    catch (Bureaucrat::Exception &e) {
        std::cout << e.what();
    }
    std::cout << std::endl << "------------------------------------------" << std::endl;
    
    // grade too low at construction
    std::cout << "grade too low" << std::endl;
    try {    
        Bureaucrat high("LowExpectations", 0);
    }
    catch (Bureaucrat::Exception &e) {
        std::cout << e.what();
    }
    std::cout << std::endl << "------------------------------------------" << std::endl;
    
    // grade decrementation
    Bureaucrat noob("noobie", 149);
    std::cout << noob << std::endl;
    std::cout << "grade decremented" << std::endl;
    noob.decrementGrade();
    std::cout << noob << std::endl;
    std::cout << "grade decremented" << std::endl;
    try {
        noob.decrementGrade();
    }
    catch (Bureaucrat::Exception &e) {
        std::cout << e.what();
    }
    std::cout << std::endl << "------------------------------------------" << std::endl;

    // grade incrementation
    Bureaucrat major("gerald", 2);
    std::cout << major << std::endl;
    std::cout << "grade incremented" << std::endl;
    major.incrementGrade();
    std::cout << major << std::endl;
    std::cout << "grade incremented" << std::endl;
    try {
        major.incrementGrade();
    }
    catch (Bureaucrat::Exception &e) {
        std::cout << e.what();
    }
    std::cout << std::endl << "------------------------------------------" << std::endl;
    
    // destruction

    std::cout << "DESTRUCTION" << std::endl;
}