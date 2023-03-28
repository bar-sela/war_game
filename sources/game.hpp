//
// Created by barse on 3/22/2023.
//

#include "card.hpp"
#include "player.hpp"

#ifndef WAR_GAME_GAME_HPP
#define WAR_GAME_GAME_HPP

#endif //WAR_GAME_GAME_HPP
class Game {
public:
    Player a;
    Player b{"senond"};
    int numberOfCards = 54;

    void playAll(); //playes the game untill the end
    void printWiner(); // prints the name of the winning player
    void printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())
    void printStats();

   Game(  Player& a , Player& b){
       this->a = a ;
       this->b = b ;
    };
    void playTurn();
    void printLastTurn();

};
