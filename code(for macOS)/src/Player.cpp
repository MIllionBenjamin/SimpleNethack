//
//  Player.cpp
//  SimpleNethack
//
//  Created by MillionBenjamin on 2018/5/15.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#include "Player.h"
#include<iostream>

Player::Player()
{
    hp=3;
    atk=1;
    def=0;
    keys=0;
    equsword=0;
    equshield=0;
    player='@';
    row=1;
    column=1;
}
Player::~Player()
{
    
}
int Player::gethp()
{
    return hp;
}
int Player::getatk()
{
    return atk;
}
int Player::getdef()
{
    return def;
}
char Player::getplayer()
{
    return player;
}
int Player::getsword()
{
    return equsword;
}
int Player::getshield()
{
    return equshield;
}
int Player::getrow()
{
    return row;
}
int Player::getcolumn()
{
    return column;
}
void Player::godown()
{
    row++;
}
void Player::goup()
{
    row--;
}
void Player::goright()
{
    column++;
}
void Player::goleft()
{
    column--;
}
void Player::addhp(int h)
{
    hp+=h;
}
void Player::addatk(int a)
{
    atk+=a;
}
void Player::adddef(int d)
{
    def+=d;
}
void Player::addkeys(int k)
{
    keys+=k;
}
void Player::dechp(int h)
{
    if(h>0)
       hp-=h;
}
void Player::decatk(int a)
{
    atk-=a;
}
void Player::decdef(int d)
{
    def-=d;
}
void Player::deckeys(int k)
{
    keys-=k;
}
void Player::setrow(int x)
{
    row=x;
}
void Player::setcolumn(int y)
{
    column=y;
}
void Player::setsword(int sw)
{
    equsword=sw;
}
void Player::setshield(int sh)
{
    equshield=sh;
}
void Player::showplayerlocation()
{
    cout<<"("<<row<<","<<column<<")"<<endl;
}
ostream &operator<<( ostream &output,const Player &P )
{
    output<<"Player is "<<P.player<<endl;
    output<<"Current ATK: "<<P.atk<<endl;
    output<<"Current DEF: "<<P.def<<endl;
    output<<"Current HP : "<<P.hp<<endl;
    output<<"Equipment  : "<<"Sword*"<<P.equsword<<" Shield*"<<P.equshield<<endl;
    output<<"Location   : "<<"("<<P.row<<","<<P.column<<")"<<endl;
    return output;
}
