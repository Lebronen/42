/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:44:22 by lebronen          #+#    #+#             */
/*   Updated: 2024/07/01 16:28:36 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main(void) {

    // default form
    Form def;
    std::cout << def << std::endl;
    Bureaucrat bof;
    def.be_signed(bof);
    std::cout << "------------------------------------------" << std::endl;

    // grade too low to sign
    Form high("A38", 42, 21);
    try {
        high.be_signed(bof);
    }
    catch (Form::Exception &e) {
       std::cout << "Constructor failure: " << e.what() << std::endl;
    }
    std::cout << "------------------------------------------" << std::endl;
    //grade too low to execute
    Bureaucrat canSign("I_can_sign", 30);
    high.be_signed(canSign);
    std::cout << "------------------------------------------" << std::endl;
    // destruction

    std::cout << "DESTRUCTION" << std::endl;
}