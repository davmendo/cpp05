/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 09:26:51 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/21 20:02:09 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>

class Form;

class Bureaucrat
{
	public:
		static const int	highestGrade;
		static const int	lowestGrade;

		Bureaucrat(void);
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat(void);

		Bureaucrat	&operator=(const Bureaucrat &other);

		const std::string	&getName(void) const;
		int					getGrade(void) const;

		void	incrementGrade(void);
		void	decrementGrade(void);

		void	signForm(Form &form) const;

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
		int					_grade;
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
