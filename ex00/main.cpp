/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 14:38:02 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/21 20:01:09 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void	showTitle(const std::string &title)
{
	std::cout << std::endl << "===== " << title << " =====" << std::endl;
}

static void	hire(const std::string &name, int grade)
{
	try
	{
		Bureaucrat	bureaucrat(name, grade);

		std::cout << "hired -> " << bureaucrat << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "refused -> " << name << ": " << e.what() << "." << std::endl;
	}
}

static void	promote(Bureaucrat &bureaucrat)
{
	try
	{
		bureaucrat.incrementGrade();
		std::cout << "promoted -> " << bureaucrat << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "promotion denied -> " << bureaucrat.getName() << ": " << e.what() << "." << std::endl;
	}
}

static void	demote(Bureaucrat &bureaucrat)
{
	try
	{
		bureaucrat.decrementGrade();
		std::cout << "demoted -> " << bureaucrat << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "demotion denied -> " << bureaucrat.getName() << ": " << e.what() << "." << std::endl;
	}
}

int	main(void)
{
	showTitle("Construction inside and outside the limits");
	hire("Amelia", Bureaucrat::highestGrade);
	hire("Bento", Bureaucrat::lowestGrade);
	hire("Celia", 42);
	hire("Dinis", 0);
	hire("Eunice", 151);
	hire("Fabio", -7);

	showTitle("Promotions and demotions");
	Bureaucrat	clerk("Celia", 3);

	std::cout << "initial -> " << clerk << std::endl;
	promote(clerk);
	promote(clerk);
	demote(clerk);

	showTitle("Hitting both ends of the range");
	Bureaucrat	director("Amelia", Bureaucrat::highestGrade);
	Bureaucrat	trainee("Bento", Bureaucrat::lowestGrade);

	promote(director);
	demote(trainee);

	showTitle("Orthodox canonical form");
	Bureaucrat	original("Gustavo", 77);
	Bureaucrat	copied(original);
	Bureaucrat	assigned;

	assigned = original;
	std::cout << "original -> " << original << std::endl;
	std::cout << "copy     -> " << copied << std::endl;
	std::cout << "assigned -> " << assigned << std::endl;
	std::cout << "the name is constant, so assignment only copies the grade" << std::endl;

	return (0);
}
