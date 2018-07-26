//
//  Equipment.cpp
//  SimpleNethack
//
//  Created by MillionBenjamin on 2018/5/15.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#include "Equipment.h"

Equipment::Equipment()
{
    atk_=0;
    def_=0;
    equipment='\0';
    string equ="";
    row_=0;
    column_=0;
}
Equipment::~Equipment()
{
    
}
int Equipment::getatk_()
{
    return atk_;
}
int Equipment::getdef_()
{
    return def_;
}
int Equipment::getrow_()
{
    return row_;
}
int Equipment::getcolumn_()
{
    return column_;
}
char Equipment::getequipment()
{
    return equipment;
}
string Equipment::getequ()
{
    return equ;
}
void Equipment::setatk_(int a)
{
    atk_=a;
}
void Equipment::setdef_(int d)
{
    def_=d;
}
void Equipment::setequipment(char e)
{
    equipment=e;
}
void Equipment::setequ(string eq)
{
    equ=eq;
}
void Equipment::setrow_(int x)
{
    row_=x;
}
void Equipment::setcolumn_(int y)
{
    column_=y;
}
