/*#include "square.h"
#include "game.h"
#include "player.h"
#include "gameUtil.h"
#include <iostream>
#include <vector>

int main(){
  std::vector<Square*> game_board;

  game_board.push_back(new Square(15,15));
  game_board.push_back(new Square(17,13));
  game_board.push_back(new Square(19,11));
  game_board.push_back(new Square(24,11));
  game_board.push_back(new Square(24,30));
  game_board.push_back(new Square(25,7));
  game_board.push_back(new Square(18,12));
  game_board.push_back(new Square(20,4));
  game_board.push_back(new Square(20,3));

  Game* game1 = new Game(game_board);
  Player* player1 = new Player(11, 3);

  std::vector<Square*> board = game1->getBoard();

  GameUtil* util = new GameUtil();

  int maxTravelDistance = util->compute(game_board.at(0), player1);
  std::cout << "max distance: " << maxTravelDistance << std::endl;

  int length = util->shortestPathDistance(game1, player1);
  std::cout << "Length of shortest path: " << length << std::endl;

  std::vector<int> path;
  path.push_back(0);
  path.push_back(3);
  path.push_back(6);
  path.push_back(8); 

  bool valid = util->isValidPath(path, player1, game1);
  std::cout << "Example path is valid (0/1): " << valid << std::endl;

  return 0;
}*/
