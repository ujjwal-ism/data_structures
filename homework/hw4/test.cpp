#include <iostream>
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
	 game_board.push_back(new Square(15,15));
	 game_board.push_back(new Square(19,11));
  	game_board.push_back(new Square(24,11));
  	game_board.push_back(new Square(24,9));
  	game_board.push_back(new Square(25,7));
  	game_board.push_back(new Square(18,8));
  	game_board.push_back(new Square(26,15));
  	game_board.push_back(new Square(22,13));
  	game_board.push_back(new Square(26,14));
  	game_board.push_back(new Square(23,14));
  	game_board.push_back(new Square(24,5));
  	game_board.push_back(new Square(21,4));
  	game_board.push_back(new Square(25,6));
  	game_board.push_back(new Square(20,19));
  	game_board.push_back(new Square(28,3));

  	Game *game1 = new Game(game_board);

  	std::vector<int> path;
  	path.push_back(0);
  	path.push_back(3);
  	path.push_back(5);
  	path.push_back(7);
  	path.push_back(9);
  	path.push_back(14);

  	GameUtil* util=new GameUtil();
  	cout<<util->isValidPath(path,player1,game1)<<endl;

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
}
