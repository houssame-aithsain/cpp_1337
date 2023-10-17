#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"


class PhoneBook{
    private:
        static int numb;
        Contact contacts[9];
    public:
        void Usage(void);
        void AddContact(void);
        void SearchForContact(void);
        void ContactsEraser(void);
};

#endif /*PHONEBOOK_HPP*/
