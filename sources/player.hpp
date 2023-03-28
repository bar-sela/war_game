//
// Created by barse on 3/22/2023.
//
#include <iostream>
#include <utility>
#include <vector>

#ifndef WAR_GAME_PLAYER_HPP
#define WAR_GAME_PLAYER_HPP


class Player {
public:
    std::string str ;
    std::vector<int> v;
    explicit Player(std::string s) : v(){
        this->str = std::move(s);
    }
    Player() : v(){
        this->str = "";
    };
    Player(Player &other){
        this->str = other.str;
    }
    int stacksize(); //prints the amount of cards left. should be 21 but can be less if a draw was played
    int cardesTaken();// prints the amount of cards this player has won.

};








#endif //WAR_GAME_PLAYER_HPP
