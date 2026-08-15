/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 13:01:04 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/10 11:43:15 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/*
** Cada entrada do catálogo liga um nome de formulário à função que sabe
** construí-lo. Assim makeForm() é uma única busca na tabela, e acrescentar um
** formulário novo custa apenas mais uma linha aqui embaixo.
*/
struct FormBlueprint
{
	const char	*name;
	AForm		*(*build)(const std::string &target);
};

static AForm	*buildShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*buildRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*buildPardon(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

static const FormBlueprint	g_catalog[] = {
	{"shrubbery creation", &buildShrubbery},
	{"robotomy request", &buildRobotomy},
	{"presidential pardon", &buildPardon}
};

static const int	g_catalogSize = sizeof(g_catalog) / sizeof(g_catalog[0]);

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

/*
** Devolve um formulário novo do tipo pedido, já apontado para o alvo. Quem
** chamou fica responsável por destruí-lo. Se o nome não estiver no catálogo,
** avisa e devolve NULL.
*/
AForm	*Intern::makeForm(const std::string &formName,
	const std::string &target) const
{
	for (int i = 0; i < g_catalogSize; i++)
	{
		if (formName == g_catalog[i].name)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (g_catalog[i].build(target));
		}
	}
	std::cout << "Intern does not know any form called " << formName << "."
		<< std::endl;
	return (NULL);
}
