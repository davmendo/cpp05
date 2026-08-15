/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 10:02:35 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/07 11:47:22 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>
# include <string>

# include "Bureaucrat.hpp"

/*
** Um formulário nasce sem assinatura e guarda duas exigências constantes: a
** classificação mínima para ser assinado e a classificação mínima para ser
** executado. Ambas seguem a mesma escala do burocrata (1 é a mais alta).
*/
class Form
{
	public:
		static const int	highestGrade;
		static const int	lowestGrade;

		Form(void);
		Form(const std::string &name, int gradeToSign, int gradeToExecute);
		Form(const Form &other);
		~Form(void);

		Form	&operator=(const Form &other);

		const std::string	&getName(void) const;
		bool				getIsSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;

		void	beSigned(const Bureaucrat &bureaucrat);

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

	private:
		static void	checkGrade(int grade);

		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream	&operator<<(std::ostream &out, const Form &form);

#endif
