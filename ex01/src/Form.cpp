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

/**
 * @brief Default constructor for Form, sets the name to "default",
 * the grade to sign to 75, and the grade to execute to 90.
 */
Form::Form() : _name("default"), _isSigned(false),
_gradeToSign(75), _gradeToExecute(90)
{}

/**
 * @brief Constructs a Form with a specified name, grade to sign, and grade to execute.
 *
 * Initializes the Form with the provided name, grade to sign, and grade to execute.
 * If the grade to sign or grade to execute is below the minimum grade, a GradeTooHighException
 * is thrown. If the grade to sign or grade to execute is above the maximum grade,
 * a GradeTooLowException is thrown.
 *
 * @param name The name of the Form.
 * @param gradeToSign The grade required to sign the Form.
 * @param gradeToExecute The grade required to execute the Form.
 * @throws GradeTooHighException if the grade to sign or execute is less than the minimum grade.
 * @throws GradeTooLowException if the grade to sign or execute is greater than the maximum grade.
 */
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

/**
 * @brief Destructor for the Form class.
 *
 * This destructor cleans up any resources used by the Form object.
 * Since the Form class does not manage any dynamic memory or resources,
 * the destructor does not perform any specific actions.
 */
Form::~Form()
{}

/**
 * @brief Copy constructor for Form objects.
 *
 * Copies the name, grade to sign, and grade to execute from the given Form object,
 * and calls the assignment operator to copy the isSigned status.
 *
 * @param rhs The Form object to be copied.
 */
Form::Form(const Form& rhs) : _name(rhs.getName()),
_gradeToSign(rhs.getGradeToSign()),
_gradeToExecute(rhs.getGradeToExecute())
{
	*this = rhs;
}

/**
 * @brief Assignment operator for Form objects.
 *
 * Assigns the given Form object to the current Form object.
 * Copies the isSigned status from the given Form object.
 *
 * @param rhs The Form object to be assigned.
 * @return A reference to the current Form object.
 */
Form &Form::operator=(const Form& rhs)
{
	if (this != &rhs)
	{
		_isSigned = rhs.getIsSigned();
	}
	return *this;
}

/**
 * @brief Returns the name of the Form.
 *
 * @return The name of the Form.
 */
const std::string &Form::getName() const
{
	return _name;
}

/**
 * @brief Returns the grade required to sign the Form.
 *
 * @return The grade required to sign the Form.
 */
const size_t &Form::getGradeToSign() const
{
	return _gradeToSign;
}

/**
 * @brief Returns the grade required to execute the Form.
 *
 * @return The grade required to execute the Form.
 */
const size_t &Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

/**
 * @brief Checks if the Form is signed.
 *
 * @return true if the Form is signed, false if the Form is not signed.
 */
bool Form::getIsSigned() const
{
	return _isSigned;
}

/**
 * @brief Returns a C-style string describing the exception.
 *
 * This function overrides the std::exception::what() function and returns a
 * string describing the GradeTooHighException.
 *
 * @return A C-style string describing the exception.
 */
const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

/**
 * @brief Returns a C-style string describing the exception.
 *
 * This function overrides the std::exception::what() function and returns a
 * string describing the GradeTooLowException.
 *
 * @return A C-style string describing the exception.
 */
const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

/**
 * @brief Attempts to sign the Form by a Bureaucrat.
 *
 * If the grade of the Bureaucrat is too low, a GradeTooLowException is thrown.
 * If the Form is successfully signed, a success message is printed to the standard output.
 *
 * @param rhs The Bureaucrat attempting to sign the Form.
 */
void Form::beSigned(const Bureaucrat &rhs)
{
	std::cout << MAG << "Atempting to sign " << GRN << _name << " Form..." << RESET << std::endl;
	if (rhs.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

/**
 * @brief Overloads the << operator to print a Form object to an output stream.
 *
 * @param out The output stream to print to.
 * @param rhs The Form object to print.
 * @return The output stream with the Form object printed to it.
 */
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
