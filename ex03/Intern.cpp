/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 13:01:04 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/21 21:43:21 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/*
** The catalog: each form name points to the member function that knows
** how to build it. Adding a new form costs just one more line.
*/
const Intern::FormBlueprint	Intern::_catalog[] = {
	{"shrubbery creation", &Intern::buildShrubbery},
	{"robotomy request", &Intern::buildRobotomy},
	{"presidential pardon", &Intern::buildPardon}
};

const int	Intern::_catalogSize = sizeof(Intern::_catalog) / sizeof(Intern::_catalog[0]);

Intern::Intern(void)
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern::~Intern(void)
{
}

Intern	&Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

AForm	*Intern::buildShrubbery(const std::string &target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::buildRobotomy(const std::string &target) const
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::buildPardon(const std::string &target) const
{
	return (new PresidentialPardonForm(target));
}

/*
** Returns a new form of the requested type, already pointing to the target. The
** caller is responsible for destroying it. If the name is not in the catalog,
** prints a warning and returns NULL.
*/
AForm	*Intern::makeForm(const std::string &formName,
	const std::string &target) const
{
	for (int i = 0; i < _catalogSize; i++)
	{
		if (formName == _catalog[i].name)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*_catalog[i].build)(target));
		}
	}
	std::cout << "Intern does not know any form called " << formName << "." << std::endl;
	return (NULL);
}
