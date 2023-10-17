#include "Contact.hpp"

void Contact::IndixInit(Contact *contacts){

    contacts->index = -1;
}


std::string Contact::StringResazer(std::string str){

    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

void Contact::Search(Contact contacts){

    if (contacts.index != -1){
        std::cout << contacts.index << " | ";
        std::cout << std::setw(10) << this->StringResazer(contacts.FirstName) << " | ";
        std::cout << std::setw(10) << this->StringResazer(contacts.LastName) << " | ";
        std::cout << std::setw(10) << this->StringResazer(contacts.NickName) << std::endl;
    }
}

void Contact::ContactInit(Contact *contact, int numb){

    int digit = true;

    std::cout << "First Name: ";
    std::cin >> contact->FirstName;

    std::cout << "Last Name: ";
    std::cin >> contact->LastName;

    std::cout << "Nick Name: ";
    std::cin >> contact->NickName;

    std::cout << "Phone Number: ";
    while (digit)
    {
        std::cin >> contact->PhoneNumber;
        if (std::cin.fail())
        {
            std::cout << "ERROR: THIS FAILED MUST BE ALL DIGITS!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Phone Number: ";
        }
        else
            digit = false;
    }
    std::cout << "Darkest Secret: ";
    std::cin >> contact->DarkestSecret;
    index = numb;
}