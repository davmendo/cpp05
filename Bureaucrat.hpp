/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 14:29:20 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/06 15:01:15 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <ostream>
# include <stdexcept>
# include <string>
# include <exception>

class Bureaucrat 
{
    /* 
    **  A bureaucrat should have:
    **  A constant name
    **  A ranking ranging from 1 to 150 
    */
    private:
        const std::string   _name;
        int                 _grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        std::string getName() const;
        int     getGrade() const;
        void    incrementGrade();
        void    decrementGrade();

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
    };

    std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif