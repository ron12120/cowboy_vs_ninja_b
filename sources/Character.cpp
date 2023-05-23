#include "Character.hpp"

namespace ariel{

    Character::Character(string name,Point pos,int hp):_pos(pos),_name(name),_hp(hp){}
    bool Character::isAlive()const{
        if (_hp>0)
            return true;
        else 
            return false;
    }
    double Character::distance(Character *charc)const{
        return(_pos.distance(charc->getLocation()));
    }
    void Character::hit(int damge){
        if (damge<0)
            throw invalid_argument("the hit number cant be negative");
        if(_hp<damge)
            _hp=0;
        else
            _hp=_hp-damge;

    }
    string Character::getName()const{
        return _name; 
    }

    Point Character::getLocation()const{
        return _pos;
    }
    string Character::print()const{
        ostringstream os;
        if(isAlive())
            os<<_name<<" "<<_hp<<" "<<_pos<<endl;
        else
            os<<"("<<_name<<") "<< _pos<<endl;
        return os.str();
    }
    void Character::setpos(Point newpos){
        _pos=newpos;
    }
    bool Character::hasteam()const{
        return _hasteam;
    }
    void Character::sethasteam(bool flag){
        _hasteam=flag;
    }
}