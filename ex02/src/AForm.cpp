/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:04:47 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/20 17:53:02 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/**
 * @brief Constructs a default AForm object.
 *
 * Initializes a default AForm object with a name of "default",
 * a grade to sign of 75, and a grade to execute of 90.
 * If the grade to sign or execute is out of range, throws a
 * GradeTooHighException or GradeTooLowException, respectively.
 */
AForm::AForm() : _name("default"), _isSigned(false),
_gradeToSign(75), _gradeToExecute(90)
{
	if (_gradeToSign < MIN_GRADE || _gradeToExecute < MIN_GRADE)
		throw GradeTooHighException();
	if (_gradeToSign > MAX_GRADE || _gradeToExecute > MAX_GRADE)
		throw GradeTooLowException();
}

/**
 * @brief Constructs an AForm object with the given name, grade to sign, and grade to execute.
 *
 * Initializes an AForm object with the given name, grade to sign, and grade to execute.
 * If the grade to sign or execute is out of range, throws a GradeTooHighException or
 * GradeTooLowException, respectively.
 *
 * @param name The name of the AForm.
 * @param gradeToSign The grade required to sign the AForm.
 * @param gradeToExecute The grade required to execute the AForm.
 */
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

/**
 * @brief Destructor for the AForm class.
 *
 * This destructor cleans up any resources used by the AForm object.
 * Since the AForm class does not manage any dynamic memory or resources,
 * the destructor does not perform any specific actions.
 */
AForm::~AForm()
{}

/**
 * @brief Copy constructor for AForm objects.
 *
 * Initializes an AForm object with a copy of the given AForm object.
 *
 * @param rhs The AForm object to be copied.
 */
AForm::AForm(const AForm& rhs) : _name(rhs.getName()),
_isSigned(rhs.getIsSigned()),
_gradeToSign(rhs.getGradeToSign()),
_gradeToExecute(rhs.getGradeToExecute())
{}

/**
 * @brief Assignment operator for AForm objects.
 *
 * Assigns the values of the given AForm object to the current AForm object.
 * Copies the isSigned status from the given AForm object.
 *
 * @param rhs The AForm object to be assigned.
 * @return A reference to the current AForm object.
 */
AForm &AForm::operator=(const AForm& rhs)
{
	if (this != &rhs)
	{
		_isSigned = rhs.getIsSigned();
	}
	return *this;
}

/**
 * @brief Returns the name of the AForm.
 *
 * @return The name of the AForm.
 */
const std::string &AForm::getName() const
{
	return _name;
}

/**
 * @brief Returns the grade required to sign the AForm.
 *
 * @return The grade required to sign the AForm.
 */
const size_t &AForm::getGradeToSign() const
{
	return _gradeToSign;
}

/**
 * @brief Returns the grade required to execute the AForm.
 *
 * @return The grade required to execute the AForm.
 */
const size_t &AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

/**
 * @brief Checks if the AForm is signed.
 *
 * @return true if the AForm is signed, false if the AForm is not signed.
 */
bool AForm::getIsSigned() const
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
const char *AForm::GradeTooHighException::what() const throw()
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
const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

/**
 * @brief Attempts to sign the AForm by a Bureaucrat.
 *
 * This function checks if the Bureaucrat's grade is sufficient to sign
 * the AForm. If the grade is too low, it throws a GradeTooLowException.
 * If the form is successfully signed, it updates the signed status
 * and prints a success message to the standard output.
 *
 * @param rhs The Bureaucrat attempting to sign the AForm.
 */
void AForm::beSigned(const Bureaucrat &rhs)
{
	std::cout << MAG << "Atempting to sign " << GRN << _name << " AForm..." << RESET << std::endl;
	if (rhs.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
	std::cout << GRN << "✅ Form has been successfully signed!" << RESET << std::endl;
}

/**
 * @brief Executes the AForm.
 *
 * This function checks if the AForm is signed and if the given Bureaucrat's
 * grade is sufficient to execute the AForm. If the form is not signed,
 * it throws a FormNotSignedException. If the grade is too low, it throws a
 * GradeTooLowException. If the execution is successful, it calls the
 * executeAction() function.
 *
 * @param executor The Bureaucrat attempting to execute the AForm.
 * @throws FormNotSignedException if the AForm is not signed.
 * @throws GradeTooLowException if the Bureaucrat's grade is too low.
 */
void AForm::execute(Bureaucrat const& executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}

/**
 * @brief Overloads the << operator to print a AForm object to an output
 * stream.
 *
 * This function prints the details of the AForm object, including its name,
 * grade to sign, grade to execute, and signed status.
 *
 * @param out The output stream to print to.
 * @param rhs The AForm object to print.
 * @return The output stream with the AForm object printed to it.
 */
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
