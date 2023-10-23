#include "HumanA.hpp"

void HumanA::attack(){

    std::cout << this->name << " attacks with their " << Sclub->getType() << std::endl;
}

HumanA::HumanA(const std::string& str, Weapon& club) : name(str), Sclub(&club){}
