#include <iostream>

#include "gameUtil.h"
#include "square.h"
#include "player.h"
#include <cassert>

using namespace std;

int test_part1(){
	Square *square = new Square(100, 10);
	Player *player = new Player(10, 10);
	GameUtil game_util;
	cout << game_util.compute(square, player) << endl;
	int distance = game_util.compute(square, player);
	assert(distance  > 0);
}

int main() {
	if (test_part1()) {
		cout << "Test 1 passed "<<endl;

	}else {
		cout <<"Test 1 Failed";
	}
}
