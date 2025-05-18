/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 08:20:26 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/18 14:39:32 by meferraz         ###   ########.fr       */
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

int main()
{
	std::cout << BGRN "\n\n📋===== BUREAUCRACY SIMULATION =====📋\n\n" RESET;

	testIntern();
	std::cout << BGRN "\n✅ All tests complete!\n\n" RESET;
	return 0;
}

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


void testIntern()
{
	SEPARATOR("👨‍🎓 Intern Form Creation Test");
	Intern intern;

	tryMakeAndPrintForm(intern, "shrubbery creation", "HomeGarden");
	tryMakeAndPrintForm(intern, "robotomy request", "Bender");
	tryMakeAndPrintForm(intern, "presidential pardon", "Snowden");
	tryMakeAndPrintForm(intern, "random form", "random target");
}
