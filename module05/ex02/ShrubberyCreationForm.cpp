/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:45:42 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/11/27 19:19:56 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm( void ){}

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("Shrubbery reque", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("Shrubbery reque", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm& other ) {

    *this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( ShrubberyCreationForm& other ) {

    if (this != &other)
        AForm::operator=(other);
    return (*this);
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
        std::cout << "Unable to open the file!" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    
    if (this->getSign() && (executor.getGrade() <= this->getExecutGrade()))
        this->treeMaker();
    else
        throw ShrubberyCreationForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, ShrubberyCreationForm& other) {

    os << "Form Name: " << other.getName() << ", Form sign Grade: " << other.getSignGrade() << ", Form Execut Grade: " << other.getExecutGrade() << ", Form status: ";
    if (other.getSign())
        os << "signed!";
    else
        os << "not signed!";
    return (os);
}
