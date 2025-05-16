/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-13 15:19:54 by meferraz          #+#    #+#             */
/*   Updated: 2025-05-13 15:19:54 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define MAX_GRADE 150
#define MIN_GRADE 1

#include "ansi.h"
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, size_t grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& rhs);
		Bureaucrat &operator=(const Bureaucrat& rhs);

		const std::string getName() const;
		size_t getGrade() const;

		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException: public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char *what() const throw();
		};

		void signForm(AForm &form);

		void executeForm(const AForm &form) const;

	private:
		const std::string _name;
		size_t _grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs);

#endif
