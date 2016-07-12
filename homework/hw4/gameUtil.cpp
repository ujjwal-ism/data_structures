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
  // TODO: Part 2
  return false;
}

int GameUtil::shortestPathDistance(Game* game, Player* player){
  // TODO: Part 3
  return -1;
}
