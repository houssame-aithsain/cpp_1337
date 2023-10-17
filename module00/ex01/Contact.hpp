#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact{
    private:
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        int PhoneNumber;
        std::string DarkestSecret;
        int index;
    public:
        void ContactInit(Contact *contacts, int numb);
        void Search(Contact contacts);
};

#endif /*CONTACT_HPP*/