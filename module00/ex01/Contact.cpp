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

std::string trim(std::string line)
{
    std::string newString;

    for (char ch : line)
    {
        if (ch == '\n' || ch == '\r')
            continue;
        newString += ch;
    }

    return newString;
}

std::string Contact::GetInput(std::string str){

    int empty = true;
    std::string input;

    while (empty){
        std::cout << str << std::flush;
        std::getline(std::cin, input);
        input = trim(input);
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