#ifndef CSE250_FALL2015_GAMEUTIL_H
#define CSE250_FALL2015_GAMEUTIL_H

#include "game.h"
#include "player.h"
#include <vector>

class GameUtil{
  public:
    int compute(Square*, Player*);
    bool isValidPath(std::vector<int>&, Player*, Game*);
    int shortestPathDistance(Game*, Player*);
};

#endif
