#include "gameUtil.h" 
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

int GameUtil::compute(Square* square, Player* player){
  
  double chi = player->getChi();
  double weight = player->getWeight();
  double teleporterEnergy = square->getTeleporterEnergy();
  double cannonPowder = square->getCannonPowder();

  double teleporterCompute = 0;
  for(int i = 0; i <= ((int)chi);i++){
    teleporterCompute += sqrt(chi * i * teleporterEnergy);
  }
  teleporterCompute *= 1.0/(1.0 + chi);

  double a= pow(cannonPowder,1.7);
  double b= pow(weight,1.5);
  double t=a/b;
  double cannonCompute = pow(t,2)/9.8;

  return std::max(cannonCompute > teleporterCompute ? cannonCompute : teleporterCompute, 1.0);
}

bool GameUtil::isValidPath(std::vector<int>& path, Player* player, Game* game){
  std::vector<Square*> board;
  board=game->getBoard();

  if(path[0] !=0)
    return false;
  if(path[path.size()-1] !=board.size()-1)
    return false;

  int prev=0;
  int totaldist = board.size()-1;
  for (int i = 1; i < path.size(); ++i)
  {
      int p=path[i];
      if(p<prev)
        return false;
      if(p>totaldist)
        return false;

      int distance = p-prev;
      if(distance > compute(board[prev],player))
        return false;
      prev = p;
  }

    return true; 
}

int GameUtil::shortestPathDistance(Game* game, Player* player){
  // TODO: Part 3
  return -1;
}
