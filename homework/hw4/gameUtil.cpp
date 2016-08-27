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
    for (int i = 1; i < path.size(); ++i) {
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
int GameUtil::max_distance(int index,int board_passed[],int size){
    int prev = -1;
    int loc;
    for (int i = index+1; i <=index+board_passed[index]; ++i)
    {
        if(index+board_passed[i] > prev){
            if(index+board_passed[i] >= size-1){
                return i;
            }
            prev = index+board_passed[i];
            loc = i;
        }
    }
    return loc;
}

int GameUtil::shortestPathDistance(Game* game, Player* player){
    std::vector<Square*> board = game->getBoard();
    int board_array[board.size()];
    //std::vector<int> board_array(board.size());
    for (int i = 0; i < board.size(); ++i){
        board_array[i] = compute(board[i],player);
    }
    return shortestPathDistance(board_array, board.size());
}

int GameUtil::shortestPathDistance(int board_array[], int board_size) {
    
    for (int i = 0; i < board_size; ++i) {
        std::cout<<board_array[i]<<" ";
    }

    std::cout<<"\n\n\n";
    // declare path vector
    std::vector<int> path;
    // path should start from first postion on board
    path.push_back(0);
    // store the local maximas
    int path_index[board_size];
    path_index[0] = 0;
    // initialize loop
    int i=1;
    while(1){
        if((path_index[i-1]+board_array[path_index[i-1]]) >= board_size-1)
         break;

        path_index[i] = max_distance(path_index[i-1],board_array,board_size);
        path.push_back(path_index[i]);
        i++;
    }
    // why are you doing this ??
    path.push_back(board_size-1);

    std::cout<<path.size()<<"\n\n";

    for (int i = 0; i < path.size(); ++i){
        std::cout<<path[i]<<" ";  
    }
    std::cout<<"\n";

    return path.size();
}

