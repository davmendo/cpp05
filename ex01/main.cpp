/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 10:44:12 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/21 21:21:11 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

static void	showTitle(const std::string &title)
{
	std::cout << std::endl << "===== " << title << " =====" << std::endl;
}

static void	draftForm(const std::string &name, int gradeToSign,
	int gradeToExecute)
{
	try
	{
		Form	form(name, gradeToSign, gradeToExecute);

		std::cout << "created -> " << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "refused -> " << name << ": " << e.what() << "." << std::endl;
	}
}

int	main(void)
{
	showTitle("Creation inside and outside the limits");
	draftForm("CoffeeRequest", 100, 120);
	draftForm("LeaveAuthorization", Form::highestGrade, Form::lowestGrade);
	draftForm("ImpossibleRequest", 0, 50);
	draftForm("ForgottenRequest", 50, 151);

	showTitle("Signature refused and accepted");
	Form		leave("LeaveAuthorization", 40, 20);
	Bureaucrat	junior("Bento", 90);
	Bureaucrat	senior("Amelia", 15);

	std::cout << leave << std::endl;
	junior.signForm(leave);
	senior.signForm(leave);
	std::cout << leave << std::endl;

	showTitle("Signing again breaks nothing");
	senior.signForm(leave);

	showTitle("Signing at the exact required grade");
	Form		budget("BudgetApproval", 30, 10);
	Bureaucrat	exact("Celia", 30);

	exact.signForm(budget);
	std::cout << budget << std::endl;

	showTitle("A promotion can unlock the signature");
	Form		audit("AuditRequest", 20, 5);
	Bureaucrat	climber("Dinis", 21);

	climber.signForm(audit);
	climber.incrementGrade();
	std::cout << "after the promotion -> " << climber << std::endl;
	climber.signForm(audit);

	showTitle("Orthodox canonical form");
	Form		original("Contract", 60, 45);
	Bureaucrat	chief("Eunice", 10);

	chief.signForm(original);

	Form	copied(original);
	Form	assigned;

	assigned = original;
	std::cout << "original -> " << original << std::endl;
	std::cout << "copy     -> " << copied << std::endl;
	std::cout << "assigned -> " << assigned << std::endl;
	std::cout << "the name and both requirements are constant, so assignment "
		"only copies the signature" << std::endl;

	return (0);
}
