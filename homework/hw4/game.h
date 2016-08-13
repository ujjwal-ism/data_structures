#ifndef MONSOON_2016_GAME_H
#define MONSOON_2016_GAME_H

#include <vector>
#include "square.h"

class Game{
private:
  std::vector<Square*> board;

public:
  Game(std::vector<Square*>);

  const std::vector<Square*>& getBoard() const;
};

#endif
