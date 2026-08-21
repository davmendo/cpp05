/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 14:03:17 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/21 20:00:06 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>

/*
** A bureaucrat has an immutable name and a grade that ranges from 1 (the
** highest) to 150 (the lowest). Promoting a bureaucrat decreases the grade
** number, while demoting increases it.
*/
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
