#ifndef CSE250_FALL2015_GAME_H
#define CSE250_FALL2015_GAME_H

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
