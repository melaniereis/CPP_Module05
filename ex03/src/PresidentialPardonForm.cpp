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
 * This constructor initializes a PresidentialPardonForm with a name of "Presidential Pardon",
 * a grade required to sign of 25, and a grade required to execute of 5.
 */
PresidentialPardonForm::PresidentialPardonForm()
: AForm("Presidential Pardon", 25, 5) {}

/**
 * @brief Constructs a PresidentialPardonForm with a specific target.
 *
 * Initializes a PresidentialPardonForm object that requires a grade of 25 to sign
 * and a grade of 5 to execute. This form is associated with the specified target,
 * which is the entity to be pardoned.
 *
 * @param target The name of the target to be pardoned.
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
 * @brief Copy constructor for PresidentialPardonForm objects.
 *
 * Initializes a new PresidentialPardonForm object as a copy of the given
 * PresidentialPardonForm object. Copies the name, signed status, grade to sign,
 * grade to execute, and target from the given PresidentialPardonForm object.
 *
 * @param rhs The PresidentialPardonForm object to copy.
 */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs)
: AForm(rhs), _target(rhs._target)
{}

/**
 * @brief Assignment operator for PresidentialPardonForm objects.
 *
 * Effectively does nothing in this case, as the target is not assignable.
 *
 * @param rhs The PresidentialPardonForm object to be assigned.
 * @return A reference to the current PresidentialPardonForm object.
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
