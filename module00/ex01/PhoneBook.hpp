#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cstdlib>
#include "Contact.hpp"

#define CHECK 0
#define SEARCH 1

class PhoneBook{
    private:
        static int numb;
        Contact contacts[8];
    public:
        void AddContact(void);
        void Usage(void);
        void SearchForContact(void);
        void init(void);
};

#endif /*PHONEBOOK_HPP*/
