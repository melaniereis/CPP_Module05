/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 07:55:23 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/20 17:37:08 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/**
 * @brief Construct a new Bureaucrat object with default name and grade.
 *
 * Default Bureaucrat constructor, sets the name to "default" and the grade to 75.
 */
Bureaucrat::Bureaucrat() : _name("default"), _grade(75)
{}

/**
 * @brief Construct a new Bureaucrat object with a name and grade.
 *
 * Parameterized Bureaucrat constructor, sets the name to the given name and
 * the grade to the given grade. If the given grade is too high or too low,
 * throws a GradeTooHighException or GradeTooLowException, respectively.
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
 * @brief Destroys a Bureaucrat object.
 *
 * Default destructor to properly clean up the object.
 */
Bureaucrat::~Bureaucrat()
{}

/**
 * @brief Copy constructor for Bureaucrat objects.
 *
 * Creates a new Bureaucrat object by copying the given Bureaucrat object.
 * Copies the name and grade of the given Bureaucrat object.
 *
 * @param rhs The Bureaucrat object to be copied.
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
 * Decrements the grade of the Bureaucrat by one. If the grade is already at the
 * highest possible value, throws a GradeTooHighException.
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
 * Increments the grade of the Bureaucrat by one. If the grade is already at the
 * lowest possible value, throws a GradeTooLowException.
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
