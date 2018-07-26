//
//  Monster.h
//  SimpleNethack
//
//  Created by MillionBenjamin on 2018/5/13.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#ifndef Monster_h
#define Monster_h

#include<iostream>
using namespace std;
class Monster
{
public:
    Monster();
    ~Monster();
    
    char getmonster();
    int getrow();
    int getcolumn();
    int getatk();
    int gethp();
    
    void godown();
    void goup();
    void goright();
    void goleft();
    
    void sethp(int h);
    void setatk(int a);
    void setrow(int x);
    void setcolumn(int y);
    void setmonster(char m);
    
    void dechp(int h);
    void decatk(int a);
    
    friend ostream &operator<<( ostream &output,const Monster &M );
    
private:
    int hp;
    int atk;
    char monster;
    int row;
    int column;
};

#endif /* Monster_h */
