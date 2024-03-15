/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:37:08 by lebronen          #+#    #+#             */
/*   Updated: 2024/03/15 11:41:29 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class AMateria {

    //Attributs
    protected :

    std::string type;
    

    //Fonctions
    AMateria(std::string const &type);
    ~AMateria();

    std::string const &getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
    
};

#endif