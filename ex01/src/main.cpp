/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-16 08:20:26 by meferraz          #+#    #+#             */
/*   Updated: 2025-05-16 08:20:26 by meferraz         ###   ########.fr       */
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
