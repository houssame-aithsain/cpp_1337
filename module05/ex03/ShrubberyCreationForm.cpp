/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:45:42 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/27 15:10:55 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm( void ){}

ShrubberyCreationForm::ShrubberyCreationForm( void ) : name("Shrubbery reque"), isSigned(false), signGrade(25), executeGrade(5) {}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : name("Shrubbery reque"), isSigned(false), signGrade(25), executeGrade(5), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm& other ) : name(other.name), signGrade(other.signGrade), executeGrade(other.executeGrade) {

    *this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( ShrubberyCreationForm& other ) {

    if (this != &other)
        this->isSigned = other.isSigned;
    return (*this);
}

const char* ShrubberyCreationForm::GradeTooHighException::what() const throw() {
    
    return ("Grade Too High!");
}

const char* ShrubberyCreationForm::GradeTooLowException::what() const throw() {
    
    return ("Grade Too Low!");
}

std::string ShrubberyCreationForm::getName( void ) const {

    return (name);
}

int ShrubberyCreationForm::getSignGrade( void ) {

    return(signGrade);
}

int ShrubberyCreationForm::getExecutGrade( void ) {

    return (executeGrade);
}

void ShrubberyCreationForm::beSigned( Bureaucrat& b ) {

    if (b.getGrade() <= this->signGrade)
        this->isSigned = true;
    else
        throw ShrubberyCreationForm::GradeTooLowException();
}

void ShrubberyCreationForm::treeMaker( void ) const {

    std::ofstream fd(this->target + "_shrubbery");
    if (fd.is_open()) {
        fd << "                                                         .\n";
        fd << "                                              .         ;  \n";
        fd << "                 .              .              ;%     ;;   \n";
        fd << "                   ,           ,                :;%  %;   \n";
        fd << "                    :         ;                   :;%;'     .,   \n";
        fd << "           ,.        %;     %;            ;        %;'    ,;\n";
        fd << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
        fd << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n";
        fd << "               ;%;      %;        ;%;        % ;%;  ,%;'\n";
        fd << "                `%;.     ;%;     %;'         `;%%;.%;'\n";
        fd << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n";
        fd << "                    `:%;.  :;bd%;          %;@%;'\n";
        fd << "                      `@%:.  :;%.         ;@@%;'   \n";
        fd << "                        `@%.  `;@%.      ;@@%;         \n";
        fd << "                          `@%%. `@%%    ;@@%;        \n";
        fd << "                            ;@%. :@%%  %@@%;       \n";
        fd << "                              %@bd%%%bd%%:;     \n";
        fd << "                                #@%%%%%:;;\n";
        fd << "                                %@@%%%::;\n";
        fd << "                                %@@@%(o);  . '         \n";
        fd << "                                %@@@o%;:(.,'         \n";
        fd << "                            `.. %@@@o%::;         \n";
        fd << "                               `)@@@o%::;         \n";
        fd << "                                %@@(o)::;        \n";
        fd << "                               .%@@@@%::;         \n";
        fd << "                               ;%@@@@%::;.          \n";
        fd << "                              ;%@@@@%%:;;;. \n";
        fd << "                          ...;%@hait-hsa;.;,..\n";
        fd.close();
    }
    else
        std::cout << "error: Unable to open a file!" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    
    if (this->isSigned && (executor.getGrade() <= this->executeGrade))
        this->treeMaker();
    else {
        std::cout << executor.getName() << " didn't make it to execute form " << this->name << std::endl;
        throw ShrubberyCreationForm::GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, ShrubberyCreationForm& other) {

    os << "ShrubberyCreationForm Name: " << other.getName() << ", ShrubberyCreationForm sign Grade: " << other.getSignGrade() << ", ShrubberyCreationForm Execut Grade: " << other.getExecutGrade();
    return (os);
}
