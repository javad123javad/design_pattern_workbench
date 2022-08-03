#ifndef COR_H
#define COR_H

#include <boost/signals2.hpp>
#include <boost/signals2/signal.hpp>
#include <string>
using namespace boost::signals2;

class COR
{
public:
    COR();
};

struct Query
{
    std::string cresture_name;
    enum Argument{attack, defense} argument;
    int result;
};

struct Game
{
    signal<void(Query&)> queries;
};

class Creature
{
    Game& game;
    int attack, defense;

public:
    std::string name;
    Creature(Game& game, ...):
        game{game}

    {

    }
    int get_attack() const
    {
        Query q{name, Query::Argument::attack, attack};
        game.queries(q);
        return q.result;
    }
};

class CreatureModifier
{
    Game& game;
    Creature & creature;

public:
    CreatureModifier(Game& game, Creature& creature):
        game{game}, creature{creature}
    {}
};

class DoubleAttackModifier: public CreatureModifier
{
    connection conn;
public:
    DoubleAttackModifier(Game& game, Creature& creature):
        CreatureModifier(game, creature)
    {
        conn = game.queries.connect(
                    [&](Query& q)
        {
                if(q.cresture_name == creature.name
                   && q.argument == Query::Argument::attack)
            {
                q.result*=2;
            }
        }
                );
    }
    ~DoubleAttackModifier()
    {
        conn.disconnect();
    }
};


#endif // COR_H
