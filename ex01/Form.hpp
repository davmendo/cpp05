/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 10:02:35 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/21 20:03:16 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>
# include <string>

# include "Bureaucrat.hpp"

/*
** A form is created unsigned and stores two constant requirements: the
** minimum grade required to sign it and the minimum grade required to
** execute it. Both follow the same scale as the bureaucrat (1 is the
** highest).
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
