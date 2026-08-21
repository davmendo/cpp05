/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 12:45:37 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/21 21:41:52 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>

# include "AForm.hpp"

/*
** The intern has no name, rank, or any other defining characteristic.
** The only thing expected is that they can assemble the correct form
** based on the requested name.
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
		** Each entry in the catalog maps a form name to the member function
		** that knows how to build it. Thus, makeForm() is a single lookup
		** in the table, and adding a new form costs only one more line in the
		** catalog.
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
