/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 08:20:26 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/20 21:01:37 by meferraz         ###   ########.fr       */
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

/**
 * @brief The main entry point of the program. Runs all the tests
 * implemented in the project.
 *
 * This function will call all the test functions and display a
 * separator between them. It will also print a message at the
 * beginning and end of the program.
 *
 * @return 0 if the program runs successfully.
 */
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

/**
 * @brief Test the Shrubbery Creation Form.
 *
 * This test function creates a Bureaucrat and a ShrubberyCreationForm,
 * signs the form, and executes the form to ensure proper functionality.
 * It prints the form details and catches any exceptions during signing
 * or execution, printing the exception message if necessary.
 */

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

/**
 * @brief Test the Robotomy Request Form.
 *
 * This test function creates a Bureaucrat and a RobotomyRequestForm,
 * signs the form, and executes the form multiple times to test the
 * random success or failure of the robotomy process. It prints the
 * form details and catches any exceptions during signing or execution,
 * printing the exception message if necessary.
 */
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

/**
 * @brief Test the Presidential Pardon Form.
 *
 * This test function creates a Bureaucrat (President) and a PresidentialPardonForm,
 * signs the form, and executes the form. It prints the form details and catches
 * any exceptions during signing or execution, printing the exception message
 * if necessary.
 */
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

/**
 * @brief Test scenarios where form execution fails.
 *
 * This function tests two scenarios of form execution failures:
 * 1. An unsigned form execution attempt, where a Bureaucrat tries to
 *    execute a ShrubberyCreationForm that has not been signed.
 * 2. Execution with insufficient grade, where a Bureaucrat with a low
 *    grade attempts to execute a PresidentialPardonForm.
 *
 * The function creates Bureaucrats and Forms, attempts to execute
 * the Forms, and catches any exceptions thrown, printing the
 * exception messages to the standard error stream.
 */
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
