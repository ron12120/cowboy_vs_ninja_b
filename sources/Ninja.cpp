#include "Ninja.hpp"

namespace ariel{
    Ninja::Ninja(string name, Point pos, int hp,int speed):
    Character(name,pos,hp),_speed(speed) {}

    void Ninja::move(Character *enemy){
        Point newpos= Point::moveTowards(this->getLocation(),enemy->getLocation(),_speed);
        this->setpos(newpos);
    }

    void Ninja::slash(Character *enemy){
        if(!this->isAlive())
            throw runtime_error("the atacker dead");
        if(!enemy->isAlive())
            throw runtime_error("the atacker dead");
        if(this==enemy)
            throw runtime_error("cant attack himself");
        if(this->distance(enemy)<1)
            enemy->hit(40);
    }


}