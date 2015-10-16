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
    teleporterCompute += sqrt(chi * i * teleporterEnergy);
  }
  teleporterCompute *= 1.0/(1.0 + chi);

  double cannonCompute = pow(pow(((int)cannonPowder),1.7)/pow((int)weight,1.5),2)/9.8;

  return std::max(cannonCompute > teleporterCompute ? cannonCompute : teleporterCompute, 1.0);
}

bool GameUtil::isValidPath(std::vector<int>& path, Player* player, Game* game){
	int squarejump=0;
	int actualjump=0;  
for(int i=0; i<path.size()-1; i++){
	int squarejump = compute(game->getBoard(path[i]));
	int actualjump = path[i+1]-path[i];	}

	if(squarejump==actualjump){
	return true;

}
  return false;
}

int GameUtil::shortestPathDistance(Game* game, Player* player){
  // TODO: Part 3
  return -1;
}
