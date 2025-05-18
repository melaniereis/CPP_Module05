/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:07:35 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/18 14:17:41 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{}

Intern::~Intern(void)
{}

Intern::Intern(Intern const &src)
{
	*this = src;
}

Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return (*this);
}

// Helper to convert string to lowercase using std::locale and std::tolower (C++98)
std::string Intern::toLower(const std::string &str)
{
	std::string lowerStr = str;
	std::locale loc;
	for (std::string::size_type i = 0; i < lowerStr.length(); ++i)
	{
		lowerStr[i] = std::tolower(lowerStr[i], loc);
	}
	return lowerStr;
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	static const FormEntry forms[] = {
		{"shrubbery creation", createShrubbery},
		{"robotomy request", createRobotomy},
		{"presidential pardon", createPresidential}};

	std::string formNameLower = toLower(formName);

	for (int i = 0; i < 3; ++i)
	{
		if (formNameLower == forms[i].name)
		{
			std::cout << YEL << "Intern creates " << BLU << forms[i].name << RESET << std::endl;
			return forms[i].creator(target);
		}
	}
	throw Intern::FormNotFoundException();
}

AForm* Intern::createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return "Form not found!";
}
