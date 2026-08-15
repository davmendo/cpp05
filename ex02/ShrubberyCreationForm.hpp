/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 09:32:11 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/08 12:40:09 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <exception>
# include <string>

# include "AForm.hpp"

/*
** Ao ser executado, cria o arquivo <alvo>_shrubbery no diretório de trabalho
** e desenha algumas árvores em ASCII dentro dele.
*/
class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(void);
		explicit ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		virtual ~ShrubberyCreationForm(void);

		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);

		const std::string	&getTarget(void) const;

		class FileOpenException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

	protected:
		virtual void	executeAction(void) const;

	private:
		std::string	_target;
};

#endif
