/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-16 12:41:38 by meferraz          #+#    #+#             */
/*   Updated: 2025-05-16 12:41:38 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "ansi.h"
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const std::string name, size_t gradeToSign, size_t gradeToExecute);
		virtual ~AForm();
		AForm(const AForm& rhs);
		AForm &operator=(const AForm& rhs);

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
		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "Form is not signed!";
				}
		};

		void beSigned(const Bureaucrat &rhs);

		void execute(Bureaucrat const &executor) const;

	protected:
		virtual void executeAction(void) const = 0;

	private:
		const std::string _name;
		bool _isSigned;
		const size_t _gradeToSign;
		const size_t _gradeToExecute;
};

std::ostream& operator<<(std::ostream& out, const AForm& rhs);

#endif
