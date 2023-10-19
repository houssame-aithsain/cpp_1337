#include "PhoneBook.hpp"

int PhoneBook::PhoneBook::numb = 0;

void PhoneBook::init(void){

    for (int i = 0; i < 8; i++)
        contacts[i].SetIndex(-1);
}

void PhoneBook::Usage()
{
    std::cout << std::endl  << "Welcome to your PhoneBook." << std::endl << std::endl ;
    std::cout << "______________USAGE_____________+" << std::endl;
    std::cout << "ADD:    To ADD a contact.       |" << std::endl;
    std::cout << "SEARCH: To SEACRH for a contact.|" << std::endl;
    std::cout << "EXIT:   To EXIT PhoneBook :( .  |" << std::endl;
    std::cout << "________________________________|" << std::endl << std::endl;
}

void PhoneBook::AddContact()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    contacts[numb].SetFname(contacts[numb].GetInput("+ First Name:       "));
    contacts[numb].SetLname(contacts[numb].GetInput("+ Last Name:        "));
    contacts[numb].SetNname(contacts[numb].GetInput("+ Nick Name:        "));
    contacts[numb].SetPnumber(contacts[numb].GetInput("+ Phone Number:     "));
    contacts[numb].SetDsecret(contacts[numb].GetInput("+ Darkest Secret:   "));
    contacts[numb].SetIndex(numb);
    numb++;
    if (numb > 7)
        numb = 0;
}

void PhoneBook::SearchForContact(){

    Contact ccontacts;
    int index = -1;
    int status = true;

    std::cout << "============================================" << std::endl;
    std::cout << "     Index|" << "First Name|" << "Last Name |" << "Nick Name |" << std::endl;
    std::cout << "============================================" << std::endl;
    for (int i = 0; i < 8; i++)
        ccontacts.Search(contacts[i]);
    if (!contacts[0].SearchIndex(contacts[0], CHECK))
        return ;
    while (index > 7 || index < 0 || !status){
        std::cout << "Please type the contact number to show: ";
        std::cin >> index;
        if (std::cin.eof())
            exit(-9);
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore();
            std::cout << "ERROR: wrong input!" << std::endl;
            return ;
        }
        if (index >= 0 && index < 8)
            status = contacts[index].SearchIndex(contacts[index], SEARCH);
        if (!status || index < 0 || index > 7)
            std::cout << "ERROR: Out of range!" << std::endl;
    }
}
