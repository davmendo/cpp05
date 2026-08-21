/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 10:01:18 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/21 21:28:58 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(void);
		explicit RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		virtual ~RobotomyRequestForm(void);

		RobotomyRequestForm	&operator=(const RobotomyRequestForm &other);

		const std::string	&getTarget(void) const;

	protected:
		virtual void	executeAction(void) const;

	private:
		std::string	_target;
};

#endif
