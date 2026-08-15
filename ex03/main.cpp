/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 13:24:48 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/10 11:58:40 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

static void	showTitle(const std::string &title)
{
	std::cout << std::endl << "===== " << title << " =====" << std::endl;
}

/*
** Pede um formulário ao estagiário e leva o trabalho até o fim. O ponteiro
** devolvido pertence a quem pediu, por isso é destruído aqui.
*/
static void	delegate(const Intern &intern, const std::string &formName,
	const std::string &target, const Bureaucrat &officer)
{
	AForm	*form = intern.makeForm(formName, target);

	if (form == NULL)
		return ;
	officer.signForm(*form);
	officer.executeForm(*form);
	delete form;
}

int	main(void)
{
	Intern		someRandomIntern;
	Bureaucrat	president("Amelia", 1);

	showTitle("The three forms in the catalog");
	delegate(someRandomIntern, "shrubbery creation", "porch", president);
	std::cout << std::endl;
	delegate(someRandomIntern, "robotomy request", "Bender", president);
	std::cout << std::endl;
	delegate(someRandomIntern, "presidential pardon", "Arthur Dent",
		president);

	showTitle("Names the intern does not know");
	delegate(someRandomIntern, "coffee request", "kitchen", president);
	delegate(someRandomIntern, "", "nowhere", president);
	delegate(someRandomIntern, "Robotomy Request", "Bender", president);

	showTitle("The example from the subject");
	{
		Intern	otherIntern;
		AForm	*rrf;

		rrf = otherIntern.makeForm("robotomy request", "Bender");
		if (rrf != NULL)
			std::cout << *rrf << std::endl;
		delete rrf;
	}

	showTitle("One intern is as good as another");
	Intern	copied(someRandomIntern);
	Intern	assigned;

	assigned = someRandomIntern;
	delegate(copied, "presidential pardon", "Ford Prefect", president);
	delegate(assigned, "presidential pardon", "Trillian", president);

	return (0);
}
