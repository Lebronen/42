/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:00:54 by rshay             #+#    #+#             */
/*   Updated: 2024/02/19 11:07:21 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl {

    // Constructeur
    public: 
    
    Harl(void);

    // Fonctions
    private :

    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    
    public :

    void complain(std::string level);
    
    // Destructeur
    public :

    ~Harl(void);
};

#endif
