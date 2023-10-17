#include "PhoneBook.hpp"

int PhoneBook::PhoneBook::numb = 0;

void Phonebook::ContactsEraser(void){

    
}

void PhoneBook::Usage()
{
    std::cout << "Welcome to your PhoneBook." << std::endl;
    std::cout << "Please choose one of theas:" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "ADD: To ADD a contact." << std::endl;
    std::cout << "SEARCH: To SEACRH for contact." << std::endl;
    std::cout << "EXIT: To EXIT PhoneBook :( ." << std::endl;
}

void PhoneBook::AddContact()
{
    contacts[numb].ContactInit(&contacts[numb], numb);
    numb++;
    if (numb > 8)
        numb = 0;
}

void PhoneBook::SearchForContact(){
    Contact ccontacts;

    for (int i = 0; i < 9; i++)
        ccontacts.Search(contacts[i]);
}
