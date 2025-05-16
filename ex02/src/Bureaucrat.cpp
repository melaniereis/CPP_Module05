/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-16 07:55:23 by meferraz          #+#    #+#             */
/*   Updated: 2025-05-16 07:55:23 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(75)
{}

Bureaucrat::Bureaucrat(const std::string name, size_t grade) : _name(name), _grade(grade)
{
	if (grade < MIN_GRADE)
		throw GradeTooHighException();
	if (grade > MAX_GRADE)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : _name(rhs.getName())
{
	*this = rhs;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
	{
		_grade = rhs.getGrade();
	}
	return *this;
}

const std::string Bureaucrat::getName() const
{
	return _name;
}

size_t Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= MIN_GRADE)
		throw GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= MAX_GRADE)
		throw GradeTooLowException();
	++_grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << GRN << "✅ Form has been successfully signed!" << RESET << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	} catch (std::exception &e)
	{
		std::cerr << RED << _name << " couldn't execute " << form.getName() << ": " << e.what() << RESET << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs)
{
	out << MAG << rhs.getName()
	<< GRN ", bureaucrate grade "
	<< YEL << rhs.getGrade()
	<< GRN << "."
	<< RESET << std::endl;
	return out;
}
