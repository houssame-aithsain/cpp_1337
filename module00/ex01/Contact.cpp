#include "Contact.hpp"

std::string Contact::StringResazer(std::string str){

    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

int Contact::SearchIndex(Contact contacts, int flag){

    if (contacts.index != -1){
        if (!flag)
            return (true);
        std::cout << std::endl;
        std::cout << "√ Fisrt Name:     " << contacts.FirstName << std::endl;
        std::cout << "√ Last Name:      " << contacts.LastName << std::endl;
        std::cout << "√ Nick Name:      " << contacts.NickName << std::endl;
        std::cout << "√ Phone Number:   " << contacts.PhoneNumber << std::endl;
        std::cout << "√ Darkest Secret: " << contacts.DarkestSecret << std::endl;
        return (true);
    }
    if (!flag)
        return (false);
    return (false);
}

void Contact::Search(Contact contacts){

    if (contacts.index != -1){
        std::cout << std::setw(10) << contacts.index << "|";
        std::cout << std::setw(10) << this->StringResazer(contacts.FirstName) << "|";
        std::cout << std::setw(10) << this->StringResazer(contacts.LastName) << "|";
        std::cout << std::setw(10) << this->StringResazer(contacts.NickName) << "|" << std::endl;
        std::cout << "============================================" << std::endl;
    }
}

std::string Contact::GetInput(std::string str){

    int empty = true;
    std::string input;

    while (empty){
        std::cout << str << std::flush;
        std::getline(std::cin, input);
        if (std::cin.eof())
            exit(-99);
        if (!input.empty())
            empty = false;
    }
    return (input);
}
