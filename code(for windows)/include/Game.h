//
//  Game.h
//  SimpleNethack
//
//  Created by MillionBenjamin on 2018/5/13.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include "Map.h"
#include "Player.h"
#include "Monster.h"
#include "Apple.h"
#include "Equipment.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

//Xcode doesn't have
#include <conio.h>
//#include <window.h>

using namespace std;
class Game
{
public:
    Game();
    ~Game();
    void gameinterface();
    int hereisok(int x,int y);
    
    bool playertoequips();
    bool playertoapple();
    
    bool monstertoequips();
    bool monstertoapple();
    
    bool playertomonster();
    
    int  whichroom(int x, int y);
    
    void meetdoor(Player &P);
    void meetdoor(Monster &M);
    
    void moveplayer(int x, int y, Player &P);
    void movemonster(int x, int y, Monster &M);
    
    void howmonstergo();
    void movearound();
    void reset();
    
private:
    Map M;
    Player P;
    Equipment sword;
    Equipment shield;
    Monster mon;
    Apple  a;
    static int floor;
};

#endif /* Game_h */
