/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 08:20:26 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/24 08:02:52 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

#define SEPARATOR(txt) std::cout << "\n" \
<< WHT "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" \
<< "📄 " << txt << "\n" \
<< "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" RESET "\n" << std::endl;

void testIntern();

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

	testIntern();
	std::cout << BGRN "\n✅ All tests complete!\n\n" RESET;
	return 0;
}

/**
 * @brief Helper function to test the Intern's makeForm method.
 *
 * It takes an Intern, a form name and a target, tries to create the
 * corresponding form using Intern::makeForm, and if successful, prints
 * the form, has a Bureaucrat sign it and execute it.
 *
 * If the form creation fails, it catches the exception and prints the
 * error message to the standard error.
 *
 * @param intern The Intern object to use to create the form.
 * @param formName The name of the form to create.
 * @param target The target of the form to create.
 */
void tryMakeAndPrintForm(Intern& intern, const std::string& formName, const std::string& target)
{
	try {
		AForm* form = intern.makeForm(formName, target);
		std::cout << *form << std::endl;

		Bureaucrat executor("Alice", 1);
		form->beSigned(executor);
		form->execute(executor);

		delete form;
	}
	catch (const std::exception& e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

/**
 * @brief Tests the Intern's ability to create different forms.
 *
 * This function tests the creation of various forms using an Intern object.
 * It attempts to create a ShrubberyCreationForm, RobotomyRequestForm,
 * PresidentialPardonForm, and an unrecognized form type. For each form,
 * it tries to create the form, print its details, have it signed and executed
 * by a Bureaucrat.
 *
 * If a form creation fails due to an unrecognized form name, an exception is
 * caught, and the error message is printed to the standard error stream.
 */
void testIntern()
{
	SEPARATOR("👨‍🎓 Intern Form Creation Test");
	Intern intern;

	tryMakeAndPrintForm(intern, "shrubbery creation", "HomeGarden");
	tryMakeAndPrintForm(intern, "robotomy request", "Bender");
	tryMakeAndPrintForm(intern, "presidential pardon", "Snowden");
	tryMakeAndPrintForm(intern, "random form", "random target");
}
