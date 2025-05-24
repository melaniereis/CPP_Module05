/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:07:35 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/24 08:01:50 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/**
 * Default constructor
 */
Intern::Intern(void)
{}

/**
 * Default destructor
 */
Intern::~Intern(void)
{}

/**
 * @brief Copy constructor for Intern.
 *
 * This constructor initializes a new Intern object by copying the data from
 * an existing Intern object.
 *
 * @param src The Intern object to copy from.
 */
Intern::Intern(Intern const &src)
{
	*this = src;
}

/**
 * @brief Assignment operator for Intern.
 *
 * This operator is used to assign the data of one Intern object to another.
 *
 * @param rhs The Intern object to assign from.
 * @return A reference to the assigned Intern object.
 */
Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return (*this);
}

// Helper to convert string to lowercase using std::locale and std::tolower (C++98)

/**
 * @brief Converts a given string to lowercase.
 *
 * This function takes a string as input and returns a new string
 * with all characters converted to lowercase using the specified locale.
 *
 * @param str The string to be converted to lowercase.
 * @return A new string with all characters in lowercase.
 */
std::string Intern::toLower(const std::string &str)
{
	std::string lowerStr = str;
	std::locale loc;
	for (std::string::size_type i = 0; i < lowerStr.length(); ++i)
	{
		lowerStr[i] = std::tolower(lowerStr[i], loc);
	}
	return lowerStr;
}

/**
 * @brief Creates a form given its name and target.
 *
 * This function takes the name of a form and a target, and creates the
 * corresponding form object. If the form name is not recognized,
 * an exception of type Intern::FormNotFoundException is thrown.
 *
 * @param formName The name of the form to create.
 * @param target The target of the form to create.
 * @return A pointer to the newly created form object.
 * @throws Intern::FormNotFoundException if the form name is not recognized.
 */
AForm *Intern::makeForm(std::string formName, std::string target)
{
	static const FormEntry forms[] = {
		{"shrubbery creation", createShrubbery},
		{"robotomy request", createRobotomy},
		{"presidential pardon", createPresidential}};

	std::string formNameLower = toLower(formName);

	for (int i = 0; i < 3; ++i)
	{
		if (formNameLower == forms[i].name)
		{
			std::cout << YEL << "Intern creates " << BLU << forms[i].name << RESET << std::endl;
			return forms[i].creator(target);
		}
	}
	throw Intern::FormNotFoundException();
}

/**
 * @brief Creates a new ShrubberyCreationForm.
 *
 * This function creates and returns a new instance of
 * ShrubberyCreationForm initialized with the specified target.
 *
 * @param target The target for the Shrubbery Creation Form.
 * @return A pointer to the newly created ShrubberyCreationForm object.
 */
AForm* Intern::createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

/**
 * @brief Creates a new RobotomyRequestForm.
 *
 * This function creates and returns a new instance of
 * RobotomyRequestForm initialized with the specified target.
 *
 * @param target The target for the Robotomy Request Form.
 * @return A pointer to the newly created RobotomyRequestForm object.
 */

AForm* Intern::createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

/**
 * @brief Creates a new PresidentialPardonForm.
 *
 * This function creates and returns a new instance of
 * PresidentialPardonForm initialized with the specified target.
 *
 * @param target The target for the Presidential Pardon Form.
 * @return A pointer to the newly created PresidentialPardonForm object.
 */
AForm* Intern::createPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

/**
 * @brief Returns a C-style string describing the exception.
 *
 * This method overrides the virtual function `what()` from the
 * std::exception class to provide a specific error message
 * indicating that the requested form could not be found.
 *
 * @return A constant character pointer to the error message.
 */
const char *Intern::FormNotFoundException::what() const throw()
{
	return "Form not found!";
}
