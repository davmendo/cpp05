/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 14:40:22 by davmendo          #+#    #+#             */
/*   Updated: 2026/08/06 15:02:46 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try
    {
        Bureaucrat bureaucrat1("Alice", 1);
        std::cout << bureaucrat1 << std::endl;

        Bureaucrat bureaucrat2("Bob", 150);
        std::cout << bureaucrat2 << std::endl;

        // This will throw a GradeTooHighException
        Bureaucrat bureaucrat3("Charlie", 0);
    } 
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try
    {
        // This will throw a GradeTooLowException
        Bureaucrat bureaucrat4("David", 151);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat bureaucrat5("Eve", 75);
        std::cout << bureaucrat5 << std::endl;

        bureaucrat5.incrementGrade();
        std::cout << "After increment: " << bureaucrat5 << std::endl;

        bureaucrat5.decrementGrade();
        std::cout << "After decrement: " << bureaucrat5 << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}