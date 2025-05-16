/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-16 12:52:19 by meferraz          #+#    #+#             */
/*   Updated: 2025-05-16 12:52:19 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false),
_gradeToSign(75), _gradeToExecute(90)
{}

Form::Form(const std::string name, size_t gradeToSign,
	size_t gradeToExecute)
	: _name(name), _isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	if (gradeToSign < MIN_GRADE || gradeToExecute < MIN_GRADE)
		throw GradeTooHighException();
	if (gradeToExecute > MAX_GRADE || gradeToExecute > MAX_GRADE)
		throw GradeTooLowException();
}

Form::~Form()
{}

Form::Form(const Form& rhs) : _name(rhs.getName()),
_gradeToSign(rhs.getGradeToSign()),
_gradeToExecute(rhs.getGradeToExecute())
{
	*this = rhs;
}

Form &Form::operator=(const Form& rhs)
{
	if (this != &rhs)
	{
		_isSigned = rhs.getIsSigned();
	}
	return *this;
}

const std::string &Form::getName() const
{
	return _name;
}

const size_t &Form::getGradeToSign() const
{
	return _gradeToSign;
}

const size_t &Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

void Form::beSigned(const Bureaucrat &rhs)
{
	std::cout << MAG << "Atempting to sign " << GRN << _name << " Form..." << RESET << std::endl;
	if (rhs.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& rhs)
{
	out << MAG << rhs.getName()
	<< GRN " Form, grade to sign is: "
	<< YEL << rhs.getGradeToSign()
	<< GRN ", grade to execute is: "
	<< YEL << rhs.getGradeToExecute()
	<< GRN " and has it been signed? "
	<< YEL << (rhs.getIsSigned() ? "signed" : "not signed")
	<< GRN << "."
	<< RESET << std::endl;
	return out;
}
