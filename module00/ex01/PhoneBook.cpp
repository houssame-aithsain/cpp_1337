#include "PhoneBook.hpp"

int PhoneBook::PhoneBook::numb = 0;

void PhoneBook::init(void){

    for (int i = 0; i < 8; i++)
        contacts[i].IndixInit(&contacts[i]);
}

void PhoneBook::Usage()
{
    std::cout << "Welcome to your PhoneBook." << std::endl;
    std::cout << "Please choose one of theas:" << std::endl;
    std::cout << "______________________________+" << std::endl;
    std::cout << "ADD: To ADD a contact.        |" << std::endl;
    std::cout << "SEARCH: To SEACRH for contact.|" << std::endl;
    std::cout << "EXIT: To EXIT PhoneBook :( .  |" << std::endl;
    std::cout << "______________________________|" << std::endl << std::endl;
}

void PhoneBook::AddContact()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    contacts[numb].SetFname(contacts[numb].GetInput("First Name: "));
    contacts[numb].SetLname(contacts[numb].GetInput("Last Name: "));
    contacts[numb].SetNname(contacts[numb].GetInput("Nick Name: "));
    contacts[numb].SetPnumber(contacts[numb].GetInput("Phone Number: "));
    contacts[numb].SetDsecret(contacts[numb].GetInput("Darkest Secret: "));
    contacts[numb].SetIndex(numb);
    numb++;
    if (numb > 7)
        numb = 0;
}

void PhoneBook::SearchForContact(){

    Contact ccontacts;
    int index = -1;

    std::cout << "==================================================" << std::endl;
    std::cout << "     Index |" << " First Name |" << " Last Name  |" << " Nick Name |" << std::endl;
    std::cout << "==================================================" << std::endl;
    for (int i = 0; i < 8; i++)
        ccontacts.Search(contacts[i]);
    while (index > 7 || index < 0){
        std::cout << "Enter index of the contact you want to display: ";
        std::cin >> index;
        if (std::cin.eof())
            exit(-9);
        if (std::cin.fail()){
            std::cin.clear();
            std::cout << "ERROR: wrong input!" << std::endl;
            return ;
        }
        if (index >= 0 && index < 8)
            ccontacts.SearchIndex(contacts[index]);
        else
            std::cout << "Out of range!" << std::endl;
    }
}
