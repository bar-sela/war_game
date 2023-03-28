#include <iostream>
#include "doctest.h"
#include "sources//card.hpp"
#include "sources/card.hpp"

#include "sources/game.hpp"

TEST_CASE("constructors"){

    Player p1 ;
    Player p2{"shon"};
    Player p3{p2};
    Game game(p1,p2);
    p3.str = "eli";
    /*
    for(int i =0 ; i < 20;i++){
        CHECK(1==0);
    }
     */
    // Player constructors


}

TEST_CASE("Game rules"){
    Player p1 ;Player p2;
    CHECK_THROWS(Game(p1,p1)); /// CANT PLAY WITH HIMSELF
    Game game(p1,p2);
    CHECK(p1.stacksize() == 26 );   // CORRECT INTITLE AMOUNT OF CARDS AT THE BEGINING
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() ==0 );
    CHECK(p2.cardesTaken()== 0);
    // THE GAME HAVENT STARTED YET SO THERE ARE NO OTS A LIGGILE TO PRINT THE INFO OF TURNS AND THE NAME OF THE FUTHER WINNER
    CHECK_THROWS(game.printWiner());
    CHECK_THROWS(game.printLastTurn());
    CHECK_THROWS(game.printLog());
    CHECK_THROWS(game.printStats());

    game.playTurn();     // ONE CARD DOWN AT A TIME TO EACH COMPETETOR
    CHECK(p1.stacksize() <= 25 );
    CHECK(p2.stacksize() <= 25);

    // after the game ends :
    game.playAll();
    CHECK(p1.cardesTaken() <= 26 );
    CHECK(p2.cardesTaken()<= 26);
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize()== 0);
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 52);


    /// you cant play another turn after game has finished
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.printWiner());
    CHECK_THROWS(game.playTurn());
    CHECK_THROWS(game.playAll());


}


