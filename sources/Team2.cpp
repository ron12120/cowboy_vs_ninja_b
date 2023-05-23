#include "Team.hpp"

namespace ariel
{
    Team2::Team2(Character *leader) : Team(leader)
    {
    }

    // void Team2::add(Character *player)
    // {
    //     if (player == nullptr)
    //         throw runtime_error("the leader cnan't be null");
    //     if (player->hasteam())
    //         throw runtime_error("the leader is alredy in team ");
    //     if (players.size() < 10)
    //     {
    //         players.push_back(player);
    //         player->sethasteam(true);
    //     }
    //     else
    //         throw runtime_error("the team contians max of players:10");
    // }

    void Team2::print() const
    {
        for (Character *player : players)
            cout << player->print() << endl;
    }
    Team2::~Team2()
    {
        for (auto player : players)
            delete (player);
        players.clear();
    }
}
