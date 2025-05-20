/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:49:44 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/20 21:43:15 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/**
 * @brief Constructor for ShrubberyCreationForm objects.
 *
 * Initializes a ShrubberyCreationForm object without a target.
 * The form is initialized with a name of "Shrubbery Creation",
 * a grade required to sign of 145, and a grade required to execute of 137.
 */
ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("Shrubbery Creation", 145, 137), _target("")
{}

/**
 * @brief Constructor for ShrubberyCreationForm objects.
 *
 * Initializes a ShrubberyCreationForm object with a given target.
 * The form is initialized with a name of "Shrubbery Creation",
 * a grade required to sign of 145, and a grade required to execute of 137.
 *
 * @param target The target of the shrubbery to be specified in the form.
 */
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("Shrubbery Creation", 145, 137),
	_target(target)
{}

/**
 * @brief Destructor for ShrubberyCreationForm objects.
 *
 * This destructor does not perform any specific actions because
 * ShrubberyCreationForm does not manage any dynamic memory or resources.
 */
ShrubberyCreationForm::~ShrubberyCreationForm()
{}

/**
 * @brief Copy constructor for ShrubberyCreationForm objects.
 *
 * Copies the target filename and name, grade to sign, and grade to execute from
 * the given ShrubberyCreationForm object, and calls the assignment operator to
 * copy the isSigned status.
 *
 * @param rhs The ShrubberyCreationForm object to be copied.
 */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs)
: AForm(rhs), _target(rhs._target)
{}
/**
 * @brief Assignment operator for ShrubberyCreationForm objects.
 *
 * Assigns the values of the given ShrubberyCreationForm object to the current
 * ShrubberyCreationForm object. Copies the target filename and name, grade to
 * sign, and grade to execute from the given object.
 *
 * @param rhs The ShrubberyCreationForm object to be assigned.
 * @return A reference to the current ShrubberyCreationForm object.
 */
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	(void)rhs;
	return *this;
}

/**
 * @brief Creates a file with the name of the target followed by "_shrubbery" and
 * writes a shrubbery ASCII art to it.
 *
 * If the file cannot be opened for writing, an error message is printed to the
 * standard error.
 */
void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file(_target + "_shrubbery");
	if (!file.is_open())
	{
		std::cerr << "Failed to open file for writing: " << _target + "_shrubbery" << std::endl;
		return;
	}
	file <<
	"       🌲\n"
	"      🌲🌲\n"
	"     🌲🌲🌲\n"
	"    🌲🌲🌲🌲\n"
	"       ||\n"
	"       ||\n";
	file.close();
}
