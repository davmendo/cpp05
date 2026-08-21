/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 10:31:09 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/21 21:33:58 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

const int	Bureaucrat::highestGrade = 1;
const int	Bureaucrat::lowestGrade = 150;

Bureaucrat::Bureaucrat(void) : _name("Anonymous"), _grade(lowestGrade)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	checkGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

const std::string	&Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	checkGrade(_grade - 1);
	_grade = _grade - 1;
}

void	Bureaucrat::decrementGrade(void)
{
	checkGrade(_grade + 1);
	_grade = _grade + 1;
}

void	Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << "." << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << "." << std::endl;
	}
}

void	Bureaucrat::checkGrade(int grade)
{
	if (grade < highestGrade)
		throw GradeTooHighException();
	if (grade > lowestGrade)
		throw GradeTooLowException();
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("grade is too high");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("grade is too low");
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (out);
}
