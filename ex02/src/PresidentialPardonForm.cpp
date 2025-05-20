/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-16 15:49:44 by meferraz          #+#    #+#             */
/*   Updated: 2025-05-16 15:49:44 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/**
 * @brief Default constructor for PresidentialPardonForm.
 *
 * Initializes the PresidentialPardonForm with a name of "Presidential Pardon",
 * a grade to sign of 25, and a grade to execute of 5.
 */
PresidentialPardonForm::PresidentialPardonForm()
: AForm("Presidential Pardon", 25, 5) {}

/**
 * @brief Constructs a PresidentialPardonForm with a specified target.
 *
 * This constructor initializes a PresidentialPardonForm object with
 * a given target. The form is initialized with a name of "Presidential Pardon",
 * a grade required to sign of 25, and a grade required to execute of 5.
 *
 * @param target The target of the pardon to be specified in the form.
 */
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("Presidential Pardon", 25, 5),
	_target(target)
{}

/**
 * @brief Destructor for PresidentialPardonForm.
 *
 * This destructor does not perform any specific actions because
 * PresidentialPardonForm does not manage any dynamic memory or resources.
 */
PresidentialPardonForm::~PresidentialPardonForm()
{}

/**
 * @brief Copy constructor for PresidentialPardonForm.
 *
 * Initializes a PresidentialPardonForm object with a copy of the given
 * PresidentialPardonForm object.
 *
 * @param rhs The PresidentialPardonForm object to be copied.
 */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs)
: AForm(rhs), _target(rhs._target)
{}

/**
 * @brief Assignment operator for PresidentialPardonForm.
 *
 * Assigns the values of the given PresidentialPardonForm object to the current object.
 *
 * @param rhs The PresidentialPardonForm object to be assigned.
 * @return A reference to the current object.
 */
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	(void)rhs;
	return *this;
}

/**
 * @brief Executes the action of pardoning the target.
 *
 * This function prints a message to the standard output indicating that
 * the target has been pardoned by Zaphod Beeblebrox.
 */
void PresidentialPardonForm::executeAction() const
{
	std::cout << BLU << _target << RESET << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}
