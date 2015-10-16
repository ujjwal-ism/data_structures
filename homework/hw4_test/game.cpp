#include "game.h"
#include "square.h"
#include <vector>

Game::Game(std::vector<Square*> squares) : board(squares) {}

const std::vector<Square*>& Game::getBoard() const { return board; }
