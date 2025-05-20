/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-16 15:49:44 by meferraz          #+#    #+#             */
/*   Updated: 2025-05-16 15:49:44 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/**
 * @brief Constructor for RobotomyRequestForm objects without a target.
 *
 * This constructor creates a RobotomyRequestForm object without a target. The
 * grade required to sign the form is 72, and the grade required to execute the
 * form is 45.
 */
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request", 72, 45)
{}

/**
 * @brief Constructor for RobotomyRequestForm objects with a target.
 *
 * This constructor creates a RobotomyRequestForm object with the given target.
 * The grade required to sign the form is 72, and the grade required to execute
 * the form is 45. The seed for the pseudo-random number generator is set once
 * in the static storage duration.
 *
 * @param target The target for the robotomy request.
 */
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("Robotomy Request", 72, 45),
	_target(target)
{
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(std::time(0)); // Seed once
		seeded = true;
	}
}

/**
 * @brief Destructor for RobotomyRequestForm objects.
 *
 * This destructor cleans up any resources used by the RobotomyRequestForm object.
 * Since the RobotomyRequestForm class does not manage any dynamic memory or
 * resources, the destructor does not perform any specific actions.
 */
RobotomyRequestForm::~RobotomyRequestForm()
{}

/**
 * @brief Copy constructor for RobotomyRequestForm objects.
 *
 * Initializes a RobotomyRequestForm object with a copy of the given
 * RobotomyRequestForm object.
 *
 * @param rhs The RobotomyRequestForm object to be copied.
 */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs)
: AForm(rhs), _target(rhs._target)
{}
/**
 * @brief Assignment operator for RobotomyRequestForm objects.
 *
 * Assigns the values of the given RobotomyRequestForm object to the current
 * RobotomyRequestForm object.
 *
 * @param rhs The RobotomyRequestForm object to be assigned.
 * @return A reference to the current RobotomyRequestForm object.
 */
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	(void)rhs;
	return *this;
}

/**
 * @brief Executes the action of the RobotomyRequestForm.
 *
 * This function prints a message to the standard output indicating that
 * the target is being robotomized. The success of the robotomy is
 * determined randomly and the result is also printed to the standard output.
 */
void RobotomyRequestForm::executeAction() const
{
	std::cout << "🤖 " << YELHB << "Drilling noises..." << RESET << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << BLU << _target << GRN << " has been robotomized successfully!"
		<< RESET << std::endl;
	else
		std::cout << BLU << _target << RED << "'s robotomy failed!" << RESET << std::endl;
}
