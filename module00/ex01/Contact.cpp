#include "Contact.hpp"

void Contact::Search(Contact contacts){

    std::cout << contacts.index << " | " << contacts.FirstName << " | " << contacts.LastName << " | " << contacts.NickName << std::endl;
}

void Contact::ContactInit(Contact *contact, int numb){

    std::cout << "First Name: ";
    std::cin >> contact->FirstName;

    std::cout << "Last Name: ";
    std::cin >> contact->LastName;

    std::cout << "Nick Name: ";
    std::cin >> contact->NickName;

    std::cout << "Phone Number: ";
    std::cin >> contact->PhoneNumber;

    std::cout << "Darkest Secret: ";
    std::cin >> contact->DarkestSecret;
    index = numb;
}