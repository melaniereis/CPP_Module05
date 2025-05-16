/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-16 15:38:02 by meferraz          #+#    #+#             */
/*   Updated: 2025-05-16 15:38:02 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <cstdlib> // For std::rand
#include <ctime>   // For std::time

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(const std::string &target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& rhs);

		void executeAction(void) const;

	private:
		const std::string _target;

		RobotomyRequestForm &operator=(const RobotomyRequestForm& rhs);
};
