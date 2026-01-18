#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Game::Game(int maxNumber) {
    this->maxNumber = maxNumber;
    numOfGuesses = 0;
    playerGuess = 0;
    srand(time(NULL));
    randomNumber = rand() % maxNumber + 1;

    cout<<"GAME CONSTRUCTOR: object initalized with "<<maxNumber<<" as a maximum number"<<endl;
}

Game::~Game() {
    cout<<"GAME DESTRUCTOR: object cleared from stack memory"<<endl;
}

void Game::play() {

    cout<<"Give your guess between 1-"<<maxNumber<<endl;
    cin>>playerGuess;
    numOfGuesses++;

    while (playerGuess != randomNumber) {
        if (playerGuess < randomNumber) {
            cout<<"Your guess is too small"<<endl;
}
        else {
            cout<<"Your guess is too big"<<endl;
}
        cout<<"Give your guess between 1-"<<maxNumber<<endl;
        cin>>playerGuess;
        numOfGuesses++;
}
    printGameResult();
}

void Game::printGameResult() {
    cout<<"Your guess is right = "<<randomNumber<<endl;
    cout<<"You guessed the right answer = "<<randomNumber<<" with "<<numOfGuesses<<" guesses "<<endl;
}

