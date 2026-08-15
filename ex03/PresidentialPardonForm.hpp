/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 12:16:52 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/09 15:26:38 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>

# include "AForm.hpp"

/*
** Ao ser executado, anuncia que o alvo foi perdoado por Zaphod Beeblebrox.
*/
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
