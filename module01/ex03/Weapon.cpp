#include "Weapon.hpp"

const std::string& Weapon::getType( void ){

    return (this->type);
}

void Weapon::setType(const std::string &str){

    this->type = str;
}

Weapon::Weapon(const std::string str){
    
    this->type = str;
}

Weapon::Weapon( void ){};