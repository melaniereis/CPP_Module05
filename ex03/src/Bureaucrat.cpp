/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 07:55:23 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/20 21:49:25 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/**
 * @brief Construct a new Bureaucrat object with default name and grade.
 *
 * The default name is "default" and the default grade is 75.
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
 * @brief Destructs a Bureaucrat object.
 *
 * Does nothing, since there are no dynamically allocated resources to
 * deallocate.
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
 * @brief Returns the name of the Bureaucrat.
 *
 * This function provides access to the Bureaucrat's name, allowing external
 * entities to retrieve the name associated with the Bureaucrat object.
 *
 * @return A constant string representing the Bureaucrat's name.
 */

const std::string Bureaucrat::getName() const
{
	return _name;
}

/**
 * @brief Returns the grade of the Bureaucrat.
 *
 * This function provides access to the Bureaucrat's grade, allowing external
 * entities to retrieve the grade associated with the Bureaucrat object.
 *
 * @return The grade of the Bureaucrat as an unsigned integer.
 */
size_t Bureaucrat::getGrade() const
{
	return _grade;
}

/**
 * @brief Increments the Bureaucrat's grade.
 *
 * Decreases the numerical value of the Bureaucrat's grade by one,
 * effectively increasing the Bureaucrat's rank. If the grade is
 * already at the highest possible rank (i.e., at or below MIN_GRADE),
 * this function throws a GradeTooHighException.
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
 * Increases the numerical value of the Bureaucrat's grade by one,
 * effectively decreasing the Bureaucrat's rank. If the grade is
 * already at the lowest possible rank (i.e., at or above MAX_GRADE),
 * this function throws a GradeTooLowException.
 */
void Bureaucrat::decrementGrade()
{
	if (_grade >= MAX_GRADE)
		throw GradeTooLowException();
	++_grade;
}

/**
 * @brief Returns a C-style string describing the GradeTooHighException.
 *
 * This function overrides the std::exception::what() method to provide
 * a specific message indicating that the Bureaucrat's grade is too high.
 *
 * @return A C-style string describing the exception.
 */

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

/**
 * @brief Returns a C-style string describing the GradeTooLowException.
 *
 * This function overrides the std::exception::what() method to provide
 * a specific message indicating that the Bureaucrat's grade is too low.
 *
 * @return A C-style string describing the exception.
 */
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

/**
 * @brief Attempts to sign the given AForm by invoking its beSigned method.
 *
 * This function tries to sign the AForm using the current Bureaucrat's credentials.
 * If the form is successfully signed, no output is generated. In the event of
 * a failure, such as when the Bureaucrat's grade is insufficient, an exception
 * is caught and the error message is printed to the standard error.
 *
 * @param form The AForm object to be signed by the Bureaucrat.
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
 * This function provides a convenient way to output the Bureaucrat's
 * name and grade to an output stream, such as std::cout or std::cerr.
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
