#pragma once
#include "Character.hpp"
#include <iostream>
using namespace std;
namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int _bul;
    public:
        Cowboy(string name, Point pos);
        void shoot(Character *enemy);
        bool hasboolets ()const;
        void reload();
    };
};