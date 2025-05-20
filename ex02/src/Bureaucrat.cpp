/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 07:55:23 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/20 17:55:15 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/**
 * @brief Default constructor for Bureaucrat objects.
 *
 * Creates a new Bureaucrat object with a default name of "default" and a grade of 75.
 * The default grade is not checked for validity.
 */
Bureaucrat::Bureaucrat() : _name("default"), _grade(75)
{}

/**
 * @brief Construct a new Bureaucrat object with the given name and grade.
 *
 * Throws GradeTooHighException if the given grade is below the minimum grade,
 * or GradeTooLowException if the given grade is above the maximum grade.
 *
 * @param name The name of the Bureaucrat.
 * @param grade The grade of the Bureaucrat.
 * @throws GradeTooHighException if the given grade is below the minimum grade.
 * @throws GradeTooLowException if the given grade is above the maximum grade.
 */
Bureaucrat::Bureaucrat(const std::string name, size_t grade) : _name(name), _grade(grade)
{
	if (grade < MIN_GRADE)
		throw GradeTooHighException();
	if (grade > MAX_GRADE)
		throw GradeTooLowException();
}

/**
 * @brief Destructor for Bureaucrat objects.
 *
 * No-op destructor; Bureaucrat objects do not manage any resources.
 */
Bureaucrat::~Bureaucrat()
{}

/**
 * @brief Copy constructor for Bureaucrat objects.
 *
 * Creates a new Bureaucrat object as a copy of the given Bureaucrat.
 * Initializes the name to be the same as the given Bureaucrat and assigns
 * the values of the given Bureaucrat to the current object using the
 * assignment operator.
 *
 * @param rhs The Bureaucrat object to copy.
 */
Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : _name(rhs.getName())
{
	*this = rhs;
}

/**
 * @brief Assignment operator for Bureaucrat objects.
 *
 * Assigns the given Bureaucrat object to the current Bureaucrat object.
 * Copies the grade of the given Bureaucrat object.
 *
 * @param rhs The Bureaucrat object to be assigned.
 * @return A reference to the current Bureaucrat object.
 */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
	{
		_grade = rhs.getGrade();
	}
	return *this;
}

/**
 * @brief Returns the Bureaucrat's name.
 *
 * @return The Bureaucrat's name.
 */
const std::string Bureaucrat::getName() const
{
	return _name;
}

/**
 * @brief Returns the grade of the Bureaucrat.
 *
 * This function provides the current grade of the Bureaucrat, which
 * determines the rank or level of the Bureaucrat within the system.
 *
 * @return The current grade of the Bureaucrat.
 */
size_t Bureaucrat::getGrade() const
{
	return _grade;
}

/**
 * @brief Increases the Bureaucrat's grade.
 *
 * This function decreases the numerical value of the Bureaucrat's grade
 * by one, effectively increasing the Bureaucrat's rank. If the grade
 * is already at the maximum rank (i.e., lowest numerical value), a
 * GradeTooHighException is thrown to prevent further increments.
 */
 void Bureaucrat::incrementGrade()
{
	if (_grade <= MIN_GRADE)
		throw GradeTooHighException();
	--_grade;
}

/**
 * @brief Decreases the Bureaucrat's grade.
 *
 * This function increases the numerical value of the Bureaucrat's grade
 * by one, effectively decreasing the Bureaucrat's rank. If the grade
 * is already at the minimum rank (i.e., highest numerical value), a
 * GradeTooLowException is thrown to prevent further decrements.
 */
void Bureaucrat::decrementGrade()
{
	if (_grade >= MAX_GRADE)
		throw GradeTooLowException();
	++_grade;
}

/**
 * @brief Returns a C-style string describing the exception.
 *
 * This function overrides the std::exception::what() function and returns a
 * string describing the GradeTooHighException.
 *
 * @return A C-style string describing the exception.
 */
const char *Bureaucrat::GradeTooHighException::what() const throw()
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

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

/**
 * @brief Attempts to sign the AForm by calling beSigned on the given AForm and catching any exceptions that may occur.
 *
 * If the AForm is successfully signed, a success message is printed to the standard output.
 * If an exception occurs during signing, the exception message is printed to the standard error.
 *
 * @param form The AForm to be signed.
 */
void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

/**
 * @brief Executes the given AForm using the current Bureaucrat.
 *
 * This function attempts to execute the provided AForm by calling its
 * execute method with the current Bureaucrat. If the execution is
 * successful, a success message is printed to the standard output.
 * If an exception occurs during execution, the exception message
 * is printed to the standard error.
 *
 * @param form The AForm to be executed.
 */
void Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << BLU << _name  << RESET << " executed "
		<< MAG << form.getName() << RESET<< std::endl;
	} catch (std::exception &e)
	{
		std::cerr << BLU << _name << RED << " couldn't execute "
		<< MAG << form.getName() << RED << ": " << e.what()
		<< RESET << std::endl;
	}
}

/**
 * @brief Overloads the << operator to print a Bureaucrat object to an output
 * stream.
 *
 * @param out The output stream to print to.
 * @param rhs The Bureaucrat object to print.
 * @return The output stream with the Bureaucrat object printed to it.
 */
std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs)
{
	out << MAG << rhs.getName()
	<< GRN ", bureaucrate grade "
	<< YEL << rhs.getGrade()
	<< GRN << "."
	<< RESET;
	return out;
}
