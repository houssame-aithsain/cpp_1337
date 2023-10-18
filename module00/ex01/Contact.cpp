#include "Contact.hpp"

void Contact::IndixInit(Contact *contacts){

    contacts->index = -1;
}

std::string Contact::StringResazer(std::string str){

    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}


void Contact::SearchIndex(Contact contacts){

    if (contacts.index != -1){
        std::cout << "Fisrt Name:     " << contacts.FirstName << std::endl;
        std::cout << "Last Name:      " << contacts.LastName << std::endl;
        std::cout << "Nick Name:      " << contacts.NickName << std::endl;
        std::cout << "Phone Number:   " << contacts.PhoneNumber << std::endl;
        std::cout << "Darkest Secret: " << contacts.DarkestSecret << std::endl;
    }
}

void Contact::Search(Contact contacts){

    if (contacts.index != -1){
        std::cout << std::setw(10) << contacts.index << " | ";
        std::cout << std::setw(10) << this->StringResazer(contacts.FirstName) << " | ";
        std::cout << std::setw(10) << this->StringResazer(contacts.LastName) << " | ";
        std::cout << std::setw(10) << this->StringResazer(contacts.NickName) << "|" << std::endl;
        std::cout << "==================================================" << std::endl;
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

int Contact::IsDigit(std::string str){

    for (int i = 0; str[i]; i++){
        if (!std::isdigit(str[i]))
            return (false);
    }
    return (true);
}

void Contact::ContactInit(Contact *contact, int numb){

    int IsDigit = true;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    contact->FirstName = GetInput("First Name: ");
    contact->LastName = GetInput("Last Name: ");
    contact->NickName = GetInput("Nick Name: ");
    contact->PhoneNumber = GetInput("Phone Number: ");
    while (IsDigit){
        if (!this->IsDigit(contact->PhoneNumber)){
        std::cout << "ERROR: THIS FIELD MUST CONTAIN ONLY DIGITS!" << std::endl;
        contact->PhoneNumber = GetInput("Phone Number: ");
        }
        else
            IsDigit = false;
    }
    contact->DarkestSecret = GetInput("Darkest Secret: ");
    index = numb;
}