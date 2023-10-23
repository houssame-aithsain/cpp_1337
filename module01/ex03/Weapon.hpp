#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <cstring>

class Weapon{
    private:
        std::string type;
    public:
        Weapon( void );
        Weapon(const std::string str);
        const std::string& getType( void );
        void setType(const std::string &str);
};

#endif /*WEAPON_H*/