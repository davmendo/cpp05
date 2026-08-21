/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 10:14:05 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/21 21:28:43 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>

#include "RobotomyRequestForm.hpp"

/*
** Randomly determines the outcome of the drilling, with a 50% chance for each
** outcome. The seed is prepared on the first call so that the form does not
** depend on any external preparation.
*/
static bool	drillSucceeds(void)
{
	static bool	seeded = false;

	if (!seeded)
	{
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		seeded = true;
	}
	return (std::rand() % 2 == 0);
}

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("target")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(
	const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

const std::string	&RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

void	RobotomyRequestForm::executeAction(void) const
{
	std::cout << "Vrrrum... vrrrum... the drill keeps spinning." << std::endl;
	if (drillSucceeds())
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "the robotomy of " << _target << " failed." << std::endl;
}
