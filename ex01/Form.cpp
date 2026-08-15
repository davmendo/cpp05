/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 10:18:49 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/15 17:22:52 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const int	Form::highestGrade = 1;
const int	Form::lowestGrade = 150;

Form::Form(void) : _name("untitled"), _isSigned(false), _gradeToSign(lowestGrade), _gradeToExecute(lowestGrade)
{
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	checkGrade(gradeToSign);
	checkGrade(gradeToExecute);
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

Form::~Form(void)
{
}

/*
** O nome e as duas exigências são constantes, portanto a atribuição só pode
** copiar o estado da assinatura.
*/
Form	&Form::operator=(const Form &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

const std::string	&Form::getName(void) const
{
	return (_name);
}

bool	Form::getIsSigned(void) const
{
	return (_isSigned);
}

int	Form::getGradeToSign(void) const
{
	return (_gradeToSign);
}

int	Form::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

/*
** Como 1 é a classificação mais alta, o burocrata só pode assinar quando o
** número da sua classificação é menor ou igual ao exigido.
*/
void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void	Form::checkGrade(int grade)
{
	if (grade < highestGrade)
		throw GradeTooHighException();
	if (grade > lowestGrade)
		throw GradeTooLowException();
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("the required grade is too high");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("grade is too low");
}

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	out << "form " << form.getName() << ", "
		<< (form.getIsSigned() ? "signed" : "unsigned")
		<< ", requires grade " << form.getGradeToSign() << " to sign and "
		<< form.getGradeToExecute() << " to execute.";
	return (out);
}
