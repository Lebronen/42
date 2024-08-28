/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:33:43 by lebronen          #+#    #+#             */
/*   Updated: 2024/08/26 15:38:04 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <string>
# include <stdint.h>

struct Data
{
    std::string name;
    int         age;
};

class Serializer
{
    private :
    Serializer();
    Serializer(const Serializer &cpy);
    Serializer &operator=(const Serializer &src);

    public :
    ~Serializer();

    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};


#endif