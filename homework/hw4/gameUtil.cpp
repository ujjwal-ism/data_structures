#include "gameUtil.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

int GameUtil::compute(Square* square, Player* player){
  // TODO: Part 1 debug
  double chi = player->getChi();
  double weight = player->getWeight();
  double teleporterEnergy = square->getTeleporterEnergy();
  double cannonPowder = square->getCannonPowder();

  double teleporterCompute = 0;
  for(double i = 0.0; i < chi; i=i+1.0){
    teleporterCompute += sqrt(2.0 * ++i * teleporterEnergy);
  }
  teleporterCompute *= 1.0/(1.0 + chi);

  double cannonCompute = pow((((int)cannonPowder)^17)/weight*1.5,2)/9.8;

  return std::max(cannonCompute < teleporterCompute ? cannonCompute : teleporterCompute, 1.0);
}

bool GameUtil::isValidPath(std::vector<int>& path, Player* player, Game* game){
  // TODO: Part 2
  return false;
}

int GameUtil::shortestPathDistance(Game* game, Player* player){
  // TODO: Part 3
  return -1;
}
