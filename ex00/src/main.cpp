/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 08:20:26 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/20 17:44:28 by meferraz         ###   ########.fr       */
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

	testValidBureaucrat();
	testGradeTooHigh();
	testGradeTooLow();
	testIncrementBeyondLimit();
	testDecrementBeyondLimit();

	std::cout << BGRN "\n✅ All tests complete!\n\n" RESET;
	return 0;
}

/**
 * @brief Test valid Bureaucrat creation and operations.
 *
 * This function tests the creation of a valid Bureaucrat object and
 * performs a few operations on it, such as incrementing and decrementing
 * the grade.
 *
 * A separator is printed before and after the test, and any exceptions
 * caught will be printed to the standard error stream.
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
 * @brief Test incrementing a Bureaucrat's grade beyond the maximum.
 *
 * This function tests the incrementGrade() method of the Bureaucrat class
 * by attempting to increment the grade of a Bureaucrat object that is
 * already at the highest possible grade (i.e. MIN_GRADE). It will print
 * a separator, attempt to increment the grade, print the Bureaucrat (if
 * successful), and catch any exceptions thrown.
 *
 * If an exception is caught, the message will be printed to the standard
 * error stream.
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
 * @brief Test decrementing a Bureaucrat's grade beyond the minimum.
 *
 * This function tests the decrementGrade() method of the Bureaucrat class
 * by attempting to decrement the grade of a Bureaucrat object that is
 * already at the lowest possible grade (i.e. MAX_GRADE). It will print
 * a separator, attempt to decrement the grade, print the Bureaucrat (if
 * successful), and catch any exceptions thrown.
 *
 * If an exception is caught, the message will be printed to the standard
 * error stream.
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
