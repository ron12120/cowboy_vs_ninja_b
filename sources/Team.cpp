#include "Team.hpp"

namespace ariel
{
    Team::Team(Character *leader) : _leader(leader)
    {
        if (leader == nullptr)
            throw runtime_error("the leader cnan't be null");
        if (leader->hasteam())
            throw runtime_error("the leader is alredy in team ");
        if (auto cowboy = dynamic_cast<Cowboy *>(leader))
            cowboys.push_back(cowboy);
        else if (auto ninja = dynamic_cast<Ninja *>(leader))
            ninjas.push_back(ninja);
        players.push_back(leader);
        leader->sethasteam(true);
    }

    void Team::add(Character *player)
    {
        if (player == nullptr)
            throw runtime_error("the player cnan't be null");
        if (player->hasteam())
            throw runtime_error("the player is alredy in team ");
        if (players.size() < 10)
        {
            if (auto cowboy = dynamic_cast<Cowboy *>(player))
                cowboys.push_back(cowboy);
            else if (auto ninja = dynamic_cast<Ninja *>(player))
                ninjas.push_back(ninja);
            players.push_back(player);
            player->sethasteam(true);
        }
        else
            throw runtime_error("the team contians max of players:10");
        
    }

    // get charcter and find the most close character from the team that alive
    Character* Team::findcloset(Character *charc)const  
    {
        double min = numeric_limits<double>::max();
        Character *ans =nullptr;
        Point temp = charc->getLocation();
        for (Character *member : players)
        {
            //check the member not die and is not the charcter taht we want to be close to him 
            if (member->isAlive())
            {
                if (min > member->getLocation().distance(temp))
                {
                    ans = member;
                    min = member->getLocation().distance(temp);
                }
            }
        }
        //if we dont find any player that means that all team is die
        if (ans == nullptr)
            throw runtime_error("all team is dead");
        return ans;
    }

    void Team::attack(Team *eny)
    {
        // if the enemy is null
        if (eny == nullptr)
            throw invalid_argument("the team you attack cnat't be null");
        // if the leader is die, choice other leader
        if (!_leader->isAlive())
            _leader = (this->findcloset(_leader));
           
        // find the closet character to the leader to victim
        Character *victim = eny->findcloset(_leader);
        // the cobowy attack
        for (Cowboy *cowboy : cowboys)
        {
            //check the cowboy not die
            if (cowboy->isAlive())
            {
                if(eny->stillAlive()==0)
                    return;
                if (!victim->isAlive()) // check the victim not die and if yes change victim
                    victim = eny->findcloset(_leader);
                if (!cowboy->hasboolets())
                    cowboy->reload();
                else
                    cowboy->shoot(victim);
            }
        }
        // the ninja attack
        for (Ninja *ninja : ninjas)
        {
            //check the ninja not die
            if (ninja->isAlive())
            {
                if(eny->stillAlive()==0)
                    return;
                if (!victim->isAlive())// check the victim not die and if yes change victim
                    victim = eny->findcloset(_leader);
                if (!(ninja->distance(victim) < 1))
                    ninja->move(victim);
                else
                    ninja->slash(victim);
            }
        }
    }

    int Team::stillAlive()const{
        int count=0;
        for(Character *player: players){
            if(player->isAlive())
                count++;
        }
        return count; 
    }

    void Team::print()const{
        for(Cowboy *cowboy: cowboys){
            cout<<cowboy->print()<<endl;
        }
        for(Ninja *ninja: ninjas){
            cout<<ninja->print()<<endl;
        }   
    }
     Team::~Team()
     {
        for(Cowboy *cowboy: cowboys){
            delete(cowboy);
        }
        for(Ninja *ninja: ninjas){
            delete(ninja);
        }
        players.clear();
        cowboys.clear();
        ninjas.clear();

     }
     Character Team::getleader()const{
        return *_leader;
     }

}