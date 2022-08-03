#include "cor.h"
#include <iostream>
COR::COR()
{

}

int main(void)
{

    Game game;
    Creature goblin{game, "Strong Goblin", 2, 2,};

    return 0;
}
