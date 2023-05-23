#pragma once
#include "Character.hpp"
#include <iostream>
using namespace std;
namespace ariel
{
    class Ninja : public Character
    {
       int _speed;
    public:
        Ninja(string name, Point pos, int hp,int speed);
        void move(Character *enemy);
        void slash(Character *enemy);
    };

    
    class YoungNinja : public Ninja
    {
        public:
            YoungNinja (string name,Point pos):Ninja(name,pos,100,14){;}; 
    };

    class TrainedNinja : public Ninja
    {
        public:
            TrainedNinja (string name,Point pos): Ninja(name,pos,120,12){;}
    
    };

    class OldNinja : public Ninja
    {
        public:
        OldNinja (string name,Point pos):Ninja(name,pos,150,8){;}
    };


};