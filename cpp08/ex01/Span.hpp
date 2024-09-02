/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:53:39 by lebronen          #+#    #+#             */
/*   Updated: 2024/08/31 21:10:47 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <list>
#include <stdexcept>
#include <cmath>

class Span
{
public:
    // Constructors
    Span();
    Span(const Span &copy);
    Span(unsigned int n);

    // Destructor
    ~Span();

    // Operators
    Span &operator=(const Span &assign);

    // Functions
    void addNumber(int x);
    int shortestSpan();
    int longestSpan();

    // Exceptions
    class SpanFullException: public std::exception {
        public:
            virtual const char *what() const throw();
    };

    class SpanEmptyException: public std::exception {
        public:
            virtual const char *what() const throw();
    };

private:
    unsigned int _n;
    std::list<int> _numbers;

};

#endif