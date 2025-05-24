/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:49:44 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/24 08:06:30 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/**
 * @brief Default constructor for ShrubberyCreationForm objects.
 *
 * Initializes a ShrubberyCreationForm object with a name of "Shrubbery Creation",
 * a grade required to sign of 145, and a grade required to execute of 137.
 * The target filename is left empty.
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
 * Copies the target filename from the given ShrubberyCreationForm object,
 * and calls the assignment operator to copy the isSigned status.
 *
 * @param rhs The ShrubberyCreationForm object to be copied.
 */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs)
: AForm(rhs), _target(rhs._target)
{}

/**
 * @brief Assignment operator for ShrubberyCreationForm objects.
 *
 * This operator does not perform any specific action because
 * the target is not assignable.
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
 * @brief Executes the action for the ShrubberyCreationForm.
 *
 * This function creates a file with the name of the target followed by
 * "_shrubbery" and writes an ASCII art representation of a shrubbery into it.
 * If the file cannot be opened for writing, an error message is printed to
 * the standard error output.
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
