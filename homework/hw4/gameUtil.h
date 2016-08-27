#ifndef MONSOON_2016_GAMEUTIL_H
#define MONSOON_2016_GAMEUTIL_H

#include "game.h"
#include "player.h"
#include <vector>

class GameUtil{
  public:
    int compute(Square*, Player*);
    bool isValidPath(std::vector<int>&, Player*, Game*);
    int shortestPathDistance(Game*, Player*);
    int shortestPathDistance(int*, int);
    int max_distance(int,int*,int);

};

#endif
