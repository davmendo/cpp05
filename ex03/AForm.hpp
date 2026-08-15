/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 10:47:25 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/09 14:38:41 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <exception>
# include <iostream>
# include <string>

# include "Bureaucrat.hpp"

/*
** Base abstrata de todos os formulários. Ela guarda o nome, o estado da
** assinatura e as duas exigências constantes, e concentra as verificações de
** execução: quem chama execute() só passa adiante se o formulário estiver
** assinado e se o executor tiver classificação suficiente. A ação em si fica
** por conta de cada formulário concreto, em executeAction().
*/
class AForm
{
	public:
		static const int	highestGrade;
		static const int	lowestGrade;

		AForm(void);
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		virtual ~AForm(void);

		AForm	&operator=(const AForm &other);

		const std::string	&getName(void) const;
		bool				getIsSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;

		void	beSigned(const Bureaucrat &bureaucrat);
		void	execute(const Bureaucrat &executor) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

	protected:
		virtual void	executeAction(void) const = 0;

	private:
		static void	checkGrade(int grade);

		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream	&operator<<(std::ostream &out, const AForm &form);

#endif
