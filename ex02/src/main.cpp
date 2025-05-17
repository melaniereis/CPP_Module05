/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 08:20:26 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/17 14:27:17 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

#define SEPARATOR(txt) std::cout << "\n" \
<< WHT "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" \
<< "📄 " << txt << "\n" \
<< "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" RESET "\n" << std::endl;

void testShrubberyForm();
void testRobotomyForm();
void testPresidentialForm();
void testFormExecutionFailures();

int main()
{
	std::cout << BGRN "\n\n📋===== BUREAUCRACY SIMULATION =====📋\n\n" RESET;

	testShrubberyForm();
	testRobotomyForm();
	testPresidentialForm();
	testFormExecutionFailures();

	std::cout << BGRN "\n✅ All tests complete!\n\n" RESET;
	return 0;
}

void testShrubberyForm()
{
	SEPARATOR("🌳 Shrubbery Creation Form Test");
	try {
		Bureaucrat gardener("Gardener", 130);
		ShrubberyCreationForm shrubForm("HomeGarden");

		std::cout << shrubForm << std::endl;
		gardener.signForm(shrubForm);
		gardener.executeForm(shrubForm);
	}
	catch (const std::exception& e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
}

void testRobotomyForm()
{
	SEPARATOR("🤖 Robotomy Request Form Test");
	try {
		Bureaucrat surgeon("Surgeon", 40);
		RobotomyRequestForm robotForm("Bender");

		std::cout << robotForm << std::endl;
		surgeon.signForm(robotForm);
		surgeon.executeForm(robotForm);
		// Test multiple executions to see random success/failure
		surgeon.executeForm(robotForm);
		surgeon.executeForm(robotForm);
	}
	catch (const std::exception& e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
}

void testPresidentialForm()
{
	SEPARATOR("🦅 Presidential Pardon Form Test");
	try {
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardonForm("Snowden");

		std::cout << pardonForm << std::endl;
		president.signForm(pardonForm);
		president.executeForm(pardonForm);
	}
	catch (const std::exception& e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
}

void testFormExecutionFailures()
{
	SEPARATOR("🚫 Form Execution Failures");
	try {
		// Unsigned form test
		Bureaucrat clerk("Clerk", 20);
		ShrubberyCreationForm unsignedForm("OfficePark");
		std::cout << unsignedForm << std::endl;
		std::cout << clerk << std::endl;
		clerk.executeForm(unsignedForm);
		std::cout << std::endl;

		// Insufficient grade test

		Bureaucrat intern("Intern", 150);
		PresidentialPardonForm pardonForm("Intern");
		std::cout << pardonForm << std::endl;
		std::cout << intern << std::endl;
		intern.signForm(pardonForm);
		clerk.signForm(pardonForm);
		intern.executeForm(pardonForm);
		clerk.executeForm(pardonForm);
		std::cout << std::endl;
		Bureaucrat president("President", 1);
		president.executeForm(pardonForm);
	}
	catch (const std::exception& e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
}
