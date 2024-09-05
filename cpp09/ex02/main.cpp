/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:29:50 by lebronen          #+#    #+#             */
/*   Updated: 2024/09/05 14:47:10 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <vector>
#include <limits>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <iostream>
#include <sys/time.h>
#include "PmergeMe.hpp"

typedef unsigned long long u_ll;

static u_int32_t get_num(std::string str) {
	if (str.size() > 10)
		throw std::runtime_error("Error: " + str + " is not a valid positive integer");

	size_t i = 0;

	while (i < str.size()) {
		if (!isdigit(str[i]))
			throw std::runtime_error("Error: " + str + " is not a valid positive integer");
		i++;
	}

	u_int64_t res = std::strtoul(str.c_str(), NULL, 10);

	if (res > std::numeric_limits<u_int32_t>::max())
		throw std::runtime_error("Error: " + str + " is not a valid positive integer");

	return static_cast<u_int32_t>(res);
}

static u_ll current_time_micros() {
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000UL + tv.tv_usec;
}

int main(int argc, char** argv) {

	if (argc == 1) {
		std::cout << "Usage: ./PmergeMe <space separated numbers>" << std::endl;
		return 1;
	}

	std::deque<u_int32_t> deque;
	std::vector<u_int32_t> vector;

	try {
		for (int i = 1 ; i < argc ; i++) {
			u_int32_t parsed = get_num(argv[i]);

			deque.push_back(parsed);
			vector.push_back(parsed);
		}
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	std::cout << "Before:         ";
	for (size_t i = 0; i < vector.size(); i++) {
		if (i)
			std::cout << " ";
		std::cout << vector[i];
	}
	std::cout << std::endl;

	u_ll start_vector = current_time_micros();
	PmergeMe::sort(vector);
	u_ll elapsed_vector = current_time_micros() - start_vector;

	u_ll start_deque = current_time_micros();
	PmergeMe::sort(deque);
	u_ll elapsed_deque = current_time_micros() - start_deque;

	std::cout << "After (vector): ";
	for (size_t i = 0; i < vector.size(); i++) {
		if (i)
			std::cout << " ";
		std::cout << vector[i];
	}
	std::cout << std::endl;

	std::cout << "After (deque):  ";
	for (size_t i = 0; i < deque.size(); i++) {
		if (i)
			std::cout << " ";
		std::cout << deque[i];
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : "
			<< std::fixed << std::setprecision(3) << elapsed_vector << " us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : "
			<< std::fixed << std::setprecision(3) << elapsed_deque << " us" << std::endl;

	return 0;
}