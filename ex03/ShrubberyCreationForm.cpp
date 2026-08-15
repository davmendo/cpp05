/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 11:33:40 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/10 11:18:02 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>

#include "ShrubberyCreationForm.hpp"

static const char	*const	g_tree =
	"        /\\\n"
	"       /**\\\n"
	"      /****\\\n"
	"     /******\\\n"
	"    /********\\\n"
	"   /**********\\\n"
	"        ||\n"
	"        ||\n";

static const int	g_treeCount = 3;

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", 145, 137), _target("target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(
	const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

const std::string	&ShrubberyCreationForm::getTarget(void) const
{
	return (_target);
}

void	ShrubberyCreationForm::executeAction(void) const
{
	std::ofstream	file((_target + "_shrubbery").c_str());

	if (!file.is_open())
		throw FileOpenException();
	for (int i = 0; i < g_treeCount; i++)
		file << g_tree << std::endl;
	file.close();
	std::cout << "trees were planted in " << _target << "_shrubbery."
		<< std::endl;
}

const char	*ShrubberyCreationForm::FileOpenException::what(void) const throw()
{
	return ("the target file could not be opened");
}
