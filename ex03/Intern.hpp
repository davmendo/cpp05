/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 12:45:37 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/09 15:42:56 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>

# include "AForm.hpp"

/*
** O estagiário não tem nome, classificação nem qualquer outra característica
** própria. A única coisa que se espera dele é que saiba montar o formulário
** certo a partir do nome pedido.
*/
class Intern
{
	public:
		Intern(void);
		Intern(const Intern &other);
		~Intern(void);

		Intern	&operator=(const Intern &other);

		AForm	*makeForm(const std::string &formName,
			const std::string &target) const;
};

#endif
