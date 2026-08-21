/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 11:07:53 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/21 13:22:29 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

static void	showTitle(const std::string &title)
{
	std::cout << std::endl << "===== " << title << " =====" << std::endl;
}

/*
** Percurso completo de um formulário: mostrar, assinar e executar.
*/
static void	handle(AForm &form, const Bureaucrat &signer, const Bureaucrat &executor)
{
	std::cout << form << std::endl;
	signer.signForm(form);
	executor.executeForm(form);
}

int	main(void)
{
	Bureaucrat	president("Amelia", 1);
	Bureaucrat	manager("Bento", 40);
	Bureaucrat	trainee("Celia", 148);

	showTitle("Each form handled by someone who can sign and execute it");
	ShrubberyCreationForm	garden("garden");
	RobotomyRequestForm		bender("Bender");
	PresidentialPardonForm	arthur("Arthur Dent");

	handle(garden, manager, manager);
	std::cout << std::endl;
	handle(bender, manager, manager);
	std::cout << std::endl;
	handle(arthur, president, president);

	showTitle("Grade too low to sign");
	ShrubberyCreationForm	backyard("backyard");

	trainee.signForm(backyard);

	showTitle("Executing a form nobody signed");
	RobotomyRequestForm	marvin("Marvin");

	president.executeForm(marvin);

	showTitle("Signed, but the executor's grade is not high enough");
	PresidentialPardonForm	ford("Ford Prefect");

	president.signForm(ford);
	manager.executeForm(ford);

	showTitle("Execution at the exact required grade");
	RobotomyRequestForm	zaphod("Zaphod");
	Bureaucrat			exact("Dinis", 45);

	president.signForm(zaphod);
	exact.executeForm(zaphod);

	showTitle("Polymorphism through pointers to the abstract base");
	AForm	*forms[3];

	forms[0] = new ShrubberyCreationForm("porch");
	forms[1] = new RobotomyRequestForm("Zorg");
	forms[2] = new PresidentialPardonForm("Trillian");
	for (int i = 0; i < 3; i++)
	{
		president.signForm(*forms[i]);
		president.executeForm(*forms[i]);
		delete forms[i];
	}

	return (0);
}
