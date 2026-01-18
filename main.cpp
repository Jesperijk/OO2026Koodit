#include <iostream>
#include "Game.h"
using namespace std;

int main() {

    int numb;
    cout<<"Give max number: " <<endl;
    cin>>numb;
    Game game(numb);
    game.play();

    return 0;
}
