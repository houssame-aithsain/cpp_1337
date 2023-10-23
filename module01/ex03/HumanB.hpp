#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB{

    private:
        std::string name;
        Weapon* Sclub;
    public:
        void attack();
        HumanB(const std::string& str);
        void setWeapon(Weapon& club);
};

#endif /*HUMANB_HPP*/
