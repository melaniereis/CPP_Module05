/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 08:20:26 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/20 17:50:25 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

#define SEPARATOR(txt) std::cout << "\n" \
<< WHT "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" \
<< "📄 " << txt << "\n" \
<< "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" RESET "\n" << std::endl;

void testValidBureaucrat();
void testGradeTooHigh();
void testGradeTooLow();
void testIncrementBeyondLimit();
void testDecrementBeyondLimit();
void testValidFormCreation();
void testFormSigningSuccess();
void testFormSigningFailure();

/**
 * @brief The main entry point of the program. Executes all test cases to verify
 * the functionality and robustness of the Bureaucrat and Form classes.
 *
 * This function orchestrates the execution of various tests including creating
 * valid and invalid Bureaucrats, incrementing and decrementing grades beyond limits,
 * and handling form creation, signing, and execution scenarios. It displays
 * separators between tests and confirms completion of all tests.
 *
 * @return 0 if the program runs successfully.
 */
int main()
{
	std::cout << BGRN "\n\n📋===== BUREAUCRACY SIMULATION =====📋\n\n" RESET;

	testValidBureaucrat();
	testGradeTooHigh();
	testGradeTooLow();
	testIncrementBeyondLimit();
	testDecrementBeyondLimit();

	testValidFormCreation();
	testFormSigningSuccess();
	testFormSigningFailure();

	std::cout << BGRN "\n✅ All tests complete!\n\n" RESET;
	return 0;
}

/**
 * @brief Test creating a valid Bureaucrat and performing operations on it.
 *
 * This test case creates a Bureaucrat object with a valid grade, prints its
 * state to the standard output, increments and decrements its grade, and
 * prints the resulting state. It also handles any exceptions that may be
 * thrown during the process.
 */
void testValidBureaucrat()
{
	SEPARATOR("✅ Valid Bureaucrat Creation and Operations");
	try {
		Bureaucrat alice("Alice", 75);
		std::cout << alice << std::endl;

		std::cout << BLUB "Incrementing grade..." NC << std::endl;
		alice.incrementGrade();
		std::cout << alice << std::endl;

		std::cout << BLUB "Decrementing grade..." NC << std::endl;
		alice.decrementGrade();
		std::cout << alice << std::endl;
	} catch (const std::exception &e) {
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
}

/**
 * @brief Test creating a Bureaucrat with a grade too high.
 *
 * This function tests the creation of a Bureaucrat object with a grade
 * that is too high (i.e. lower than MIN_GRADE). It will print a separator,
 * attempt to create the Bureaucrat, print the Bureaucrat (if successful),
 * and catch any exceptions thrown.
 *
 * If an exception is caught, the message will be printed to the standard
 * error stream.
 */
void testGradeTooHigh()
{
	SEPARATOR("🚫 Creating Bureaucrat with Grade Too High");
	try {
		Bureaucrat overachiever("Overachiever", 0);
		std::cout << overachiever << std::endl;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << RED "Caught High Exception: " << e.what() << RESET << std::endl;
	}
}

/**
 * @brief Test creating a Bureaucrat with a grade too low.
 *
 * This function tests the creation of a Bureaucrat object with a grade
 * that is too low (i.e. higher than MAX_GRADE). It will print a separator,
 * attempt to create the Bureaucrat, print the Bureaucrat (if successful),
 * and catch any exceptions thrown.
 *
 * If an exception is caught, the message will be printed to the standard
 * error stream.
 */
void testGradeTooLow()
{
	SEPARATOR("🚫 Creating Bureaucrat with Grade Too Low");
	try {
		Bureaucrat slacker("Slacker", 151);
		std::cout << slacker << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << RED "Caught Low Exception: " << e.what() << RESET << std::endl;
	}
}

/**
 * @brief Test incrementing a Bureaucrat's grade beyond the maximum limit.
 *
 * This function tests the incrementGrade() method of the Bureaucrat class
 * by attempting to increment the grade of a Bureaucrat object that is
 * already at the highest possible grade (i.e., MIN_GRADE). It prints
 * a separator, attempts to increment the grade, and catches any exceptions
 * thrown.
 *
 * If a GradeTooHighException is caught, the exception message is printed
 * to the standard error stream.
 */
void testIncrementBeyondLimit()
{
	SEPARATOR("🚫 Incrementing Grade Beyond Limit");
	try {
		Bureaucrat top("Top", MIN_GRADE);
		std::cout << top << std::endl;
		std::cout << BLUB "Attempting to increment grade..." NC << std::endl;
		top.incrementGrade();
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << RED "Caught High Exception: " << e.what() << RESET << std::endl;
	}
}

/**
 * @brief Test decrementing a Bureaucrat's grade beyond the minimum limit.
 *
 * This function tests the decrementGrade() method of the Bureaucrat class
 * by attempting to decrement the grade of a Bureaucrat object that is
 * already at the lowest possible grade (i.e. MAX_GRADE). It prints
 * a separator, attempts to decrement the grade, and catches any exceptions
 * thrown.
 *
 * If a GradeTooLowException is caught, the exception message is printed
 * to the standard error stream.
 */
void testDecrementBeyondLimit()
{
	SEPARATOR("🚫 Decrementing Grade Beyond Limit");
	try {
		Bureaucrat bottom("Bottom", MAX_GRADE);
		std::cout << bottom << std::endl;
		std::cout << BLUB "Attempting to decrement grade..." NC << std::endl;
		bottom.decrementGrade();
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << RED "Caught Low Exception: " << e.what() << RESET << std::endl;
	}
}

/**
 * @brief Test valid Form creation.
 *
 * This function tests the creation of a valid Form object with the
 * specified name and grade requirements for signing and execution.
 * It prints the Form details if creation is successful and catches
 * any exceptions that may occur during the process, printing the
 * exception message to the standard error stream.
 */
void testValidFormCreation()
{
	SEPARATOR("✅ Valid Form Creation");
	try {
		Form form("Presidential Pardon", 1, 1);
		std::cout << form << std::endl;
	} catch (const std::exception &e) {
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
}

/**
 * @brief Test successful Form signing by a Bureaucrat.
 *
 * This function tests the signing of a Form by a Bureaucrat with a
 * grade that is high enough to sign the Form. It prints a separator,
 * creates a Bureaucrat and a Form, signs the Form using the Bureaucrat,
 * and prints the updated Form details. It also catches any exceptions
 * that may occur during the process and prints the exception message
 * to the standard error stream.
 */
void testFormSigningSuccess()
{
	SEPARATOR("✅ Successful Form Signing");
	try {
		Bureaucrat bureaucrat("Alice", 50);
		Form form("Shrubbery Request", 60, 70);
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	} catch (const std::exception &e) {
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
}

/**
 * @brief Test failed Form signing by a Bureaucrat.
 *
 * This function tests the signing of a Form by a Bureaucrat with a
 * grade that is too low to sign the Form. It prints a separator,
 * creates a Bureaucrat and a Form, attempts to sign the Form using
 * the Bureaucrat, and catches any exceptions that may occur during
 * the process, printing the exception message to the standard
 * error stream.
 */
void testFormSigningFailure()
{
	SEPARATOR("🚫 Failed Form Signing");
	try {
		Bureaucrat bureaucrat("Bob", 100);
		Form form("Presidential Pardon", 1, 1);
		bureaucrat.signForm(form);
	} catch (const std::exception &e) {
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
}
