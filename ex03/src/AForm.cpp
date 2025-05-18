/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:04:47 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/18 13:16:58 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false),
_gradeToSign(75), _gradeToExecute(90)
{
	if (_gradeToSign < MIN_GRADE || _gradeToExecute < MIN_GRADE)
		throw GradeTooHighException();
	if (_gradeToSign > MAX_GRADE || _gradeToExecute > MAX_GRADE)
		throw GradeTooLowException();
}

AForm::AForm(const std::string name, size_t gradeToSign,
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

AForm::~AForm()
{}

AForm::AForm(const AForm& rhs) : _name(rhs.getName()),
_isSigned(rhs.getIsSigned()),
_gradeToSign(rhs.getGradeToSign()),
_gradeToExecute(rhs.getGradeToExecute())
{}

AForm &AForm::operator=(const AForm& rhs)
{
	if (this != &rhs)
	{
		_isSigned = rhs.getIsSigned();
	}
	return *this;
}

const std::string &AForm::getName() const
{
	return _name;
}

const size_t &AForm::getGradeToSign() const
{
	return _gradeToSign;
}

const size_t &AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

void AForm::beSigned(const Bureaucrat &rhs)
{
	std::cout << MAG << "Atempting to sign " << GRN << _name << " AForm..." << RESET << std::endl;
	if (rhs.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
	std::cout << GRN << "✅ Form has been successfully signed!" << RESET << std::endl;
}

void AForm::execute(Bureaucrat const& executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}

std::ostream& operator<<(std::ostream& out, const AForm& rhs)
{
	out << MAG << rhs.getName()
		<< GRN " Form, grade to sign is: "
		<< YEL << rhs.getGradeToSign()
		<< GRN ", grade to execute is: "
		<< YEL << rhs.getGradeToExecute()
		<< GRN " and has it been signed? "
		<< YEL << (rhs.getIsSigned() ? "signed" : "not signed")
		<< GRN << "."
		<< RESET;
	return out;
}
