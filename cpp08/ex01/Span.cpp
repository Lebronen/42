/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshay <rshay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:53:36 by lebronen          #+#    #+#             */
/*   Updated: 2024/09/02 13:08:35 by rshay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Constructors
Span::Span()
{
    _n = 0;
    std::cout << "\e[0;33mDefault Constructor called of Span\e[0m" << std::endl;
}

Span::Span(const Span &copy)
{
    _n = copy._n;
    _numbers = copy._numbers;
    std::cout << "\e[0;33mCopy Constructor called of Span\e[0m" << std::endl;
}

Span::Span(unsigned int n)
{
    _n = n;
    std::cout << "\e[0;33mFields Constructor called of Span\e[0m" << std::endl;
}

// Destructor
Span::~Span()
{
    std::cout << "\e[0;31mDestructor called of Span\e[0m" << std::endl;
}

// Operators
Span & Span::operator=(const Span & assign)
{
    _n = assign._n;
    _numbers = assign._numbers;
    return *this;
}

void Span::addNumber(int x) {
    if (_numbers.size() == _n)
        throw Span::SpanFullException();
    else
        _numbers.push_back(x);
}

int min(std::list<int> l) {
    std::list<int>::iterator it;
    int i = l.front();
    for (it = l.begin(); it != l.end(); it++) {
        if (*it < i)
            i = *it;
    }
    return i;
}

int max(std::list<int> l) {
    std::list<int>::iterator it;
    int i = l.front();
    for (it = l.begin(); it != l.end(); it++) {
        if (*it > i)
            i = *it;
    }
    return i;
}

int Span::longestSpan() {
    if (_numbers.size() <= 1)
        throw Span::SpanEmptyException();
    else
        return max(_numbers) - min(_numbers);
}

int Span::shortestSpan() {
    if (_numbers.size() <= 1)
        throw Span::SpanEmptyException();
    else {
        std::list<int>::iterator it1;
        std::list<int>::iterator it2;
        std::list<int>::iterator temp;
        std::list<int>::iterator diff = _numbers.begin();
        diff++;
        int petit = abs(*_numbers.begin() - *diff);
        for (it1 = _numbers.begin(); it1 != _numbers.end(); it1++) {
            temp = it1;
            temp++;
            for (it2 = temp; it2 != _numbers.end(); it2++) {
                if (abs(*it1 - *it2) < petit)
                    petit = abs(*it1 - *it2);
            }
        }
        return (petit);
    }
}

const char *Span::SpanFullException::what() const throw() { return "Span is full! Can't add an extra number";}
const char *Span::SpanEmptyException::what() const throw() { return "Span doesn't contain enough elements";}
