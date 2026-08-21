/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 10:29:47 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/21 21:28:12 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(void);
		explicit PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		virtual ~PresidentialPardonForm(void);

		PresidentialPardonForm	&operator=(const PresidentialPardonForm &other);

		const std::string	&getTarget(void) const;

	protected:
		virtual void	executeAction(void) const;

	private:
		std::string	_target;
};

#endif
