/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 07:55:23 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/20 17:46:23 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/**
 * @brief Default constructor for Bureaucrat objects.
 *
 * Creates a new Bureaucrat object with a default name and grade of 75.
 */
Bureaucrat::Bureaucrat() : _name("default"), _grade(75)
{}

/**
 * @brief Parameterized constructor for Bureaucrat objects.
 *
 * Creates a new Bureaucrat object with the given name and grade.
 * If the given grade is too high or too low, throws a GradeTooHighException
 * or GradeTooLowException, respectively.
 *
 * @param name The Bureaucrat's name.
 * @param grade The Bureaucrat's grade.
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
 * Does nothing.
 */
Bureaucrat::~Bureaucrat()
{}

/**
 * @brief Copy constructor for Bureaucrat objects.
 *
 * Creates a new Bureaucrat object as a copy of the given Bureaucrat.
 * Initializes the name to be the same as the given Bureaucrat and
 * assigns the values of the given Bureaucrat to the current object
 * using the assignment operator.
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
 * @brief Returns the Bureaucrat's grade.
 *
 * @return The Bureaucrat's grade.
 */
size_t Bureaucrat::getGrade() const
{
	return _grade;
}

/**
 * @brief Increments the Bureaucrat's grade.
 *
 * Decreases the numerical value of the Bureaucrat's grade by one.
 * If the grade is already at the highest possible value (i.e., equal to or less than MIN_GRADE),
 * throws a GradeTooHighException to indicate that the grade cannot be incremented further.
 */
void Bureaucrat::incrementGrade()
{
	if (_grade <= MIN_GRADE)
		throw GradeTooHighException();
	--_grade;
}

/**
 * @brief Decrements the Bureaucrat's grade.
 *
 * Increments the numerical value of the Bureaucrat's grade by one.
 * If the grade is already at the lowest possible value (i.e., equal to or greater than MAX_GRADE),
 * throws a GradeTooLowException to indicate that the grade cannot be decremented further.
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
 * @brief Signs a Form by calling beSigned on the given Form and catching any exceptions that may occur.
 *
 * If the Form is successfully signed, a success message is printed to the standard output.
 * If an exception occurs during signing, the exception message is printed to the standard error.
 */
void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << "✅ Form has been successfully signed!" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
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
	<< RESET << std::endl;
	return out;
}
