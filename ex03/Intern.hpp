/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 12:45:37 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/15 17:31:06 by davmendo         ###   ########.fr       */
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

	private:
		/*
		** Cada entrada do catálogo liga o nome de um formulário à função
		** membro que sabe construí-lo. Assim makeForm() é uma única busca
		** na tabela, e acrescentar um formulário novo custa apenas mais uma
		** linha no catálogo.
		*/
		typedef AForm	*(Intern::*FormBuilder)(const std::string &target) const;

		struct FormBlueprint
		{
			const char	*name;
			FormBuilder	build;
		};

		AForm	*buildShrubbery(const std::string &target) const;
		AForm	*buildRobotomy(const std::string &target) const;
		AForm	*buildPardon(const std::string &target) const;

		static const FormBlueprint	_catalog[];
		static const int			_catalogSize;
};

#endif
