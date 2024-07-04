/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:50:12 by lebronen          #+#    #+#             */
/*   Updated: 2024/07/04 11:50:14 by lebronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <string>
# include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern &source);
		~Intern();
		Intern &operator=(const Intern &source);

		AForm* makeForm(std::string name, std::string target);

		class UnknownFormException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif