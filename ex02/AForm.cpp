/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 09:16:47 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/15 17:23:42 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const int	AForm::highestGrade = 1;
const int	AForm::lowestGrade = 150;

AForm::AForm(void)
	: _name("untitled"), _isSigned(false), _gradeToSign(lowestGrade),
	  _gradeToExecute(lowestGrade)
{
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	checkGrade(gradeToSign);
	checkGrade(gradeToExecute);
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

AForm::~AForm(void)
{
}

/*
** O nome e as duas exigências são constantes, portanto a atribuição só pode
** copiar o estado da assinatura.
*/
AForm	&AForm::operator=(const AForm &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

const std::string	&AForm::getName(void) const
{
	return (_name);
}

bool	AForm::getIsSigned(void) const
{
	return (_isSigned);
}

int	AForm::getGradeToSign(void) const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

/*
** Como 1 é a classificação mais alta, o burocrata só pode assinar quando o
** número da sua classificação é menor ou igual ao exigido.
*/
void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

/*
** As duas condições valem para qualquer formulário, por isso são verificadas
** aqui uma única vez antes de delegar a ação à classe concreta.
*/
void	AForm::execute(const Bureaucrat &executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}

void	AForm::checkGrade(int grade)
{
	if (grade < highestGrade)
		throw GradeTooHighException();
	if (grade > lowestGrade)
		throw GradeTooLowException();
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("the required grade is too high");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("grade is too low");
}

const char	*AForm::FormNotSignedException::what(void) const throw()
{
	return ("the form is not signed");
}

std::ostream	&operator<<(std::ostream &out, const AForm &form)
{
	out << "form " << form.getName() << ", "
		<< (form.getIsSigned() ? "signed" : "unsigned")
		<< ", requires grade " << form.getGradeToSign() << " to sign and "
		<< form.getGradeToExecute() << " to execute.";
	return (out);
}
