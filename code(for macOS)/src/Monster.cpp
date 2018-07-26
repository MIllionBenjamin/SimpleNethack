//
//  Monster.cpp
//  SimpleNethack
//
//  Created by MillionBenjamin on 2018/5/15.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#include "Monster.h"

Monster::Monster()
{
    hp=0;
    atk=0;
    monster='\0';
    row=0;
    column=0;
}
char Monster::getmonster()
{
    return monster;
}
int Monster::getrow()
{
    return row;
}
int Monster::getcolumn()
{
    return column;
}
int Monster::getatk()
{
    return atk;
}
int Monster::gethp()
{
    return hp;
}
void Monster::godown()
{
    row++;
}
void Monster::goup()
{
    row--;
}
void Monster::goright()
{
    Monster::column++;
};
void Monster::goleft()
{
    column--;
}
void Monster::sethp(int h)
{
    hp=h;
}
void Monster::setatk(int a)
{
    atk=a;
}
void Monster::setrow(int x)
{
    row=x;
}
void Monster::setcolumn(int y)
{
    column=y;
}
void Monster::setmonster(char m)
{
    monster=m;
}
void Monster::dechp(int h)
{
    hp-=h;
}
void Monster::decatk(int a)
{
    atk-=a;
}
Monster::~Monster()
{
    
}
ostream &operator<<( ostream &output,const Monster &M )
{
    output<<"Monster ATK: "<<M.atk<<endl;
    if(M.column!=-1)
        output<<"Monster HP : "<<M.hp<<endl;
    else
        output<<"Monster HP : "<<"0"<<endl;
    return output;
}
