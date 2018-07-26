//
//  Map.h
//  SimpleNethack
//
//  Created by MillionBenjamin on 2018/5/13.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#ifndef Map_h
#define Map_h

#include"Player.h"
#include"Equipment.h"
#include"Monster.h"
#include"Apple.h"
#include<iostream>
using namespace std;
class Map
{
public:
    Map();
    ~Map();
    void showmap();
    void maperase();
    
    void mapupdate(const int i,const int k,const char symbol);
    void mapdelete(const int i,const int k,const char symbol);
    
    void showplayer(Player& p);
    void deleteplayer(Player& p);
    
    void showequips(Equipment& e);
    void deletequips(Equipment& e);
    
    void showmonster(Monster& m);
    void deletemonster(Monster& m);
    
    void showapple(Apple& a);
    void deleteapple(Apple& a);
    
    char mapelement(int x,int y);
private:
    char maparray[30][50];
};

#endif /* Map_h */
