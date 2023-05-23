#pragma once
#include "Point.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
namespace ariel
{
    class Character
    {
        Point _pos;
        string _name;
        int _hp;
        bool _hasteam=false;
    public:
        Character();
        Character(string name, Point pos , int hp);
        virtual bool isAlive()const;
        double distance(Character *charc)const;
        void hit(int damge);
        string getName()const;
        Point getLocation()const;
        string print()const;
        void setpos(Point newpos);
        bool hasteam()const;
        void sethasteam(bool flag);
    };
};