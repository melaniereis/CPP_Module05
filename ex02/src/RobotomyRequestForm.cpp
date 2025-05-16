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

RobotomyRequestForm::RobotomyRequestForm()
{}

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

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs)
: AForm(rhs), _target(rhs._target)
{}

hrubberyCreationForm::operator=(const RobotomyRequestForm &rhs)
{
	(void)rhs;
	return *this;
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "Drilling noises..." << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed!" << std::endl;
}
