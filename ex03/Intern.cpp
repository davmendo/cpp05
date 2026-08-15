/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 13:01:04 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/15 17:33:49 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/*
** O catálogo: cada nome de formulário apontando para a função membro que sabe
** construí-lo. Acrescentar um formulário novo custa apenas mais uma linha.
*/
const Intern::FormBlueprint	Intern::_catalog[] = {
	{"shrubbery creation", &Intern::buildShrubbery},
	{"robotomy request", &Intern::buildRobotomy},
	{"presidential pardon", &Intern::buildPardon}
};

const int	Intern::_catalogSize =
	sizeof(Intern::_catalog) / sizeof(Intern::_catalog[0]);

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

/*
** Um estagiário é igual ao outro: não há estado nenhum para copiar.
*/
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
** Devolve um formulário novo do tipo pedido, já apontado para o alvo. Quem
** chamou fica responsável por destruí-lo. Se o nome não estiver no catálogo,
** avisa e devolve NULL.
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
	std::cout << "Intern does not know any form called " << formName << "."
		<< std::endl;
	return (NULL);
}
