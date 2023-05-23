#include "Cowboy.hpp"

namespace ariel{
    Cowboy::Cowboy(string name, Point pos):Character(name,pos,110),_bul(6){}

    void Cowboy::shoot(Character *enemy) {
        if(!this->isAlive())
            throw runtime_error("the atacker dead");
        if(!enemy->isAlive())
            throw runtime_error("the victim dead");
        if(this==enemy)
            throw runtime_error("cant attack himself");
        if(this->hasboolets()&&this!=enemy){ 
            enemy->hit(10);
            _bul--;
        }
    }

    bool Cowboy::hasboolets()const{
        if(_bul>0)
            return true;
        else
            return false;
    }

    void Cowboy::reload(){
        if (!this->isAlive())
            throw runtime_error("the cowboy is dead");
        _bul=6;
    }

}