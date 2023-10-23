#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA{

    private:
        std::string name;
        Weapon *Sclub;
    public:
        void attack();
        HumanA(const std::string& str, Weapon& club);
};

#endif /*HUMANA_HPP*/
