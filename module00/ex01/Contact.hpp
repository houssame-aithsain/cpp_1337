#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cstring>
#include <iomanip>
#include <limits>

class Contact{
    private:
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        int PhoneNumber;
        std::string DarkestSecret;
        int index;
        std::string StringResazer(std::string str);
        int IsDigit(int number);
    public:
        void ContactInit(Contact *contacts, int numb);
        void Search(Contact contacts);
        void IndixInit(Contact *contacts);
};

#endif /*CONTACT_HPP*/