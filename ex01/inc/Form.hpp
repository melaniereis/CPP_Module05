/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-16 12:41:38 by meferraz          #+#    #+#             */
/*   Updated: 2025-05-16 12:41:38 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "ansi.h"
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const std::string name, size_t gradeToSign, size_t gradeToExecute);
		~Form();
		Form(const Form& rhs);
		Form &operator=(const Form& rhs);

		const std::string &getName() const;
		const size_t &getGradeToSign() const;
		const size_t &getGradeToExecute() const;
		bool getIsSigned() const;


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

		void beSigned(const Bureaucrat &rhs);

	private:
		const std::string _name;
		bool _isSigned;
		const size_t _gradeToSign;
		const size_t _gradeToExecute;
};

std::ostream& operator<<(std::ostream& out, const Form& rhs);

#endif
