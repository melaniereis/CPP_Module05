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
	: AForm("Robotomy Request", 72, 45)
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

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	(void)rhs;
	return *this;
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "🤖 " << YELHB << "Drilling noises..." << RESET << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << BLU << _target << GRN << " has been robotomized successfully!"
		<< RESET << std::endl;
	else
		std::cout << BLU << _target << RED << "'s robotomy failed!" << RESET << std::endl;
}
