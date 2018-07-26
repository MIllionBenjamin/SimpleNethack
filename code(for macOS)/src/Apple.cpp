//
//  Apple.cpp
//  SimpleNethack
//
//  Created by MillionBenjamin on 2018/5/15.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#include "Apple.h"

Apple::Apple()
{
    hp=1;
    apple='O';
    row=28;
    column=48;
}
char Apple::getapple()
{
    return apple;
}
int Apple::getrow()
{
    return row;
}
int Apple::getcolumn()
{
    return column;
}
int Apple::gethp()
{
    return hp;
}
void Apple::setrow(int x)
{
    row=x;
}
void Apple::setcolumn(int y)
{
    column=y;
}
void Apple::sethp(int h)
{
    hp=h;
}
Apple::~Apple()
{
    
}
