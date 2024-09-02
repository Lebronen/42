/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:53:39 by lebronen          #+#    #+#             */
/*   Updated: 2024/09/02 13:18:42 by rshay            ###   ########.fr       */
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

    template <typename T>
    void addRange(T deb, T fin) {
        for (T it = deb; it != fin; it++) {
            addNumber(*it);
        }
    }

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
