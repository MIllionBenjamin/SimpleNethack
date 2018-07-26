//
//  Player.h
//  SimpleNethack
//
//  Created by MillionBenjamin on 2018/5/13.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include<iostream>
using namespace std;
class Player
{
public:
    Player();
    ~Player();
    
    int gethp();
    int getatk();
    int getdef();
    int getsword();
    int getshield();
    char getplayer();
    int getrow();
    int getcolumn();
    
    void godown();
    void goup();
    void goright();
    void goleft();
    
    void addhp(int h);
    void addatk(int a);
    void adddef(int d);
    void addkeys(int k);
    
    void dechp(int h);
    void decatk(int a);
    void decdef(int d);
    void deckeys(int k);
    
    void setrow(int x);
    void setcolumn(int y);
    void setsword(int sw);
    void setshield(int sh);
    
    void addequips(string s);
    
    void showplayerlocation();
    
    friend ostream &operator<<( ostream &output,const Player &P );
    
private:
    char player;
    int hp;
    int atk;
    int def;
    int keys;
    int equsword;
    int equshield;
    int row;
    int column;
};

#endif /* Player_h */
