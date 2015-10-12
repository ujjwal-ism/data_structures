
#include <iostream>
#include <stack>
#include <queue>
#include <deque>

#include "player.h"

using namespace std;

void stackExample();
void printStack(stack<Player>);
string printPlayer(const Player&);
void printQueue(queue<Player> players);
void queueExample();


void stackExample(){
    stack<Player> playerStack;
    cout << "is the stack empty: " << playerStack.empty() << endl;
    //playerStack.pop();
    Player player1(1.1,1.4);
    playerStack.push(player1);
    cout << "is the stack empty: " << playerStack.empty() << endl;
    cout << "top: " << printPlayer(playerStack.top()) << endl;
    playerStack.push(*(new Player(5.4,6.6)));
    playerStack.push(Player(1.3,7.9));
    playerStack.push(Player(0.4,9.5));
    playerStack.push(Player(0.2,5.3));
    cout << "top: " << printPlayer(playerStack.top());
    playerStack.pop();
    cout << "top: " << printPlayer(playerStack.top());
    printStack(playerStack);
    cout << "is the stack empty: " << playerStack.empty() << endl;
    printStack(playerStack);
}

string printPlayer(const Player& player){
    cout << "weight: " << player.getWeight() << " | chi: " << player.getChi() << endl;
    return "";
}

void printStack(stack<Player> players){
    cout << endl << "stack: " << endl;
    while(!players.empty()){
        printPlayer(players.top());
        players.pop();
    }
    cout << endl;
}

void queueExample(){
    queue<Player> playerQueue;
    //cout << "is the queue empty: " << playerQueue.empty() << endl;
//    playerStack.pop();
    Player player1(1.1,1.4);
    playerQueue.push(player1);
    //cout << "is the queue empty: " << playerQueue.empty() << endl;
    //cout << "front: " << printPlayer(playerQueue.front()) << endl;
    playerQueue.push(Player(5.4,6.6));
    playerQueue.push(Player(1.3,7.9));
    playerQueue.push(Player(0.4,9.5));
    playerQueue.push(Player(0.2,5.3));
    cout << "front: " << printPlayer(playerQueue.front()) << endl;
    playerQueue.pop();
    //cout << "front: " << printPlayer(playerQueue.front()) << endl;
    //printQueue(playerQueue);

    //cout << "is the queue empty: " << playerQueue.empty() << endl;

    stack<Player> playerStack;
    playerStack.push(Player(5.4,6.6));
    playerStack.push(Player(1.3,7.9));
    playerStack.push(Player(0.4,9.5));
    playerStack.push(Player(0.2,5.3));
    //printStack(playerStack);



}

void printQueue(queue<Player> players){
    cout << endl << "queue: " << endl;
    while(!players.empty()){
        printPlayer(players.front());
        players.pop();
    }
    cout << endl;
}



int main(){
    stackExample();
    //queueExample();
    return 0;
}