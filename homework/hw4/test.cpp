#include <bits/stdc++.h>
#include "gameUtil.h"
#include "square.h"
#include "player.h"
#include <cassert>

using namespace std;

int test_part1(){
	Square *square = new Square(15, 15);
	Player *player = new Player(11, 3);
	GameUtil game_util;
	cout << game_util.compute(square, player) << endl;
	int distance = game_util.compute(square, player);
	assert(distance  > 0);
}

int test_part2(){
	Player *player1 = new Player(10,3);
	std::vector<Square*> game_board;
	game_board.push_back(new Square(5,5));
	game_board.push_back(new Square(9,1));
  game_board.push_back(new Square(4,3));
  game_board.push_back(new Square(4,9));
  game_board.push_back(new Square(5,7));
  game_board.push_back(new Square(8,8));
  game_board.push_back(new Square(16,5));
  game_board.push_back(new Square(12,3));
  game_board.push_back(new Square(16,4));
  game_board.push_back(new Square(3,4));
  game_board.push_back(new Square(4,5));
  game_board.push_back(new Square(11,4));
  game_board.push_back(new Square(15,6));
  game_board.push_back(new Square(10,9));
  game_board.push_back(new Square(1,3));

  	Game *game1 = new Game(game_board);

  	std::vector<int> path;
  	path.push_back(0);
  	path.push_back(2);
  	path.push_back(4);
  	path.push_back(7);
  	path.push_back(9);
  	path.push_back(12);
    path.push_back(14);

  	GameUtil* util= new GameUtil();
  	cout<<util->isValidPath(path,player1,game1)<<endl;
    
}
void sudo_test_part3(){
  Player *player = new Player(10,3);
  std::vector<Square*> game_board;
 /* game_board.push_back(new Square(5,5));
  game_board.push_back(new Square(9,1));
  game_board.push_back(new Square(4,3));
  game_board.push_back(new Square(4,9));
  game_board.push_back(new Square(5,7));
  game_board.push_back(new Square(8,8));
  game_board.push_back(new Square(16,5));
  game_board.push_back(new Square(12,3));
  game_board.push_back(new Square(16,4));
  game_board.push_back(new Square(3,4));
  game_board.push_back(new Square(4,5));
  game_board.push_back(new Square(11,4));
  game_board.push_back(new Square(15,6));
  game_board.push_back(new Square(10,9));
  game_board.push_back(new Square(1,3));
*/

  std::srand(time(NULL));

  int rand_c_p,rand_t_e;
  for (int i = 0; i < 1000; ++i)
  {
    rand_c_p = std::rand()%10;
    rand_t_e = std::rand()%10;
    game_board.push_back(new Square(rand_c_p,rand_t_e));
  }

    Game *game = new Game(game_board);

    GameUtil *util = new GameUtil();
    util->shortestPathDistance(game,player); 
}
 	

int test_shortest_path() {
    int board[4] = {2,4,1,3};
    
    GameUtil *util = new GameUtil();
    int shortest_path_distance = util->shortestPathDistance(board, 4);

    if(shortest_path_distance == 2) {
        return 1;
    }

    return 0;
}

int main() {
	if (test_part1()) {
		cout << "Test 1 passed "<<endl;

	}else {
		cout <<"Test 1 Failed";
	}

	if(test_part2()){
		cout<<"Test 2 passed "<<endl;
	}else{
		cout<<"Test 2 failed"<<endl;
	}

    if(test_shortest_path()) {
        cout << "Test Shortest Path Passed" << endl;
    }else {
        cout << "Test Shotest Path Failed" << endl;
    }
    
    //sudo_test_part3();
}
