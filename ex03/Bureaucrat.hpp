/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 10:18:44 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/21 21:34:11 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>

class AForm;

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

		void	signForm(AForm &form) const;
		void	executeForm(const AForm &form) const;

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
