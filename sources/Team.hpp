
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#pragma once


#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
namespace ariel
{
    class Team
    {
        Character *_leader;
        vector<Character*> players;
        vector<Ninja*> ninjas;
        vector<Cowboy*> cowboys;
      
        public: 
            Team(Character *leader);
            virtual void add(Character *player);
            void attack(Team *eny);
            Character* findcloset(Character* charc)const;
            int stillAlive()const;
            virtual void print()const;
            ~Team();
            Character getleader()const;
    };

    class Team2 : public Team
    {
        vector <Character*> players;
        public:
            Team2(Character *leader);
            //void add(Character *player)override;
            void print()const override;
            ~Team2();
    };

}