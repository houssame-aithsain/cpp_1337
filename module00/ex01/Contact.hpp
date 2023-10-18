#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cstring>
#include <iomanip>
#include <limits>

class Contact{
    private:
        int index;
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string PhoneNumber;
        std::string DarkestSecret;
        std::string StringResazer(std::string str);
    public:
        void Search(Contact contacts);
        void IndixInit(Contact *contacts);
        int SearchIndex(Contact contacts, int flag);
        std::string GetInput(std::string str);
        void SetFname(std::string SfirstName){
            FirstName = SfirstName;
        }
        void SetLname(std::string SlastName){
            LastName = SlastName;
        }
        void SetNname(std::string SnickName){
            NickName = SnickName;
        }
        void SetPnumber(std::string SphoneNumber){
            PhoneNumber = SphoneNumber;
        }
        void SetDsecret(std::string SdarkestSecret){
            DarkestSecret = SdarkestSecret;
        }
        void SetIndex(int Sindex){
            index = Sindex;
        }
};

#endif /*CONTACT_HPP*/