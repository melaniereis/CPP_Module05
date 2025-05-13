#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(75)
{}

Bureaucrat::Bureaucrat(const std::string _name, size_t grade) : _name(name), _grade(grade)
{
	if (grade > MAX_GRADE)
		throw GradeTooHighException();
	if (grade < MIN_GRADE)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs)
{
	this = rhs;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
	{

	}
}

const std::string Bureaucrat::getName() const
{
	return _name;
}

size_t Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade++ > MAX_GRADE)
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	if (_grade-- < MIN_GRADE)
		throw GradeTooLowException();
}

