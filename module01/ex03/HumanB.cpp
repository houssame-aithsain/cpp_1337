#include "HumanB.hpp"

void HumanB::attack(){

    std::cout << this->name << " attacks with their " << Sclub->getType() << std::endl;
}

HumanB::HumanB(const std::string& str){

    this->name = str;
}

void HumanB::setWeapon(Weapon& club){

    Sclub = &club;
}