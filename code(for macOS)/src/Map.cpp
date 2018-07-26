//
//  Map.cpp
//  SimpleNethack
//
//  Created by MillionBenjamin on 2018/5/17.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#include "Map.h"

Map::Map()
{
    int i,k;
    for(i=0;i<30;i++)
        for(k=0;k<50;k++)
            maparray[i][k]=' ';
    for(i=0;i<50;i++)
    {
        if((i>=0&&i<=19)||(i>=30&&i<=49))
        {
            maparray[0][i]='-';
            maparray[9][i]='-';
            maparray[20][i]='-';
            maparray[29][i]='-';
        }
    }
    for(k=0;k<30;k++)
    {
        if((k>0&&k<9)||(k>20&&k<29))
        {
            maparray[k][0]='|';
            maparray[k][19]='|';
            maparray[k][30]='|';
            maparray[k][49]='|';
        }
    }
    for(i=19;i<=30;i++)
    {
        maparray[4][i]='#';
        maparray[24][i]='#';
    }
    for(k=9;k<=20;k++)
    {
        maparray[k][10]='#';
        maparray[k][40]='#';
    }
}
Map::~Map()
{
    
}
void Map::maperase()
{
    int i,k;
    for(i=1;i<=8;i++)
        for(k=1;k<=18;k++)
            maparray[i][k]=' ';
    for(i=1;i<=8;i++)
        for(k=31;k<=48;k++)
            maparray[i][k]=' ';
    for(i=21;i<=28;i++)
        for(k=1;k<=18;k++)
            maparray[i][k]=' ';
    for(i=21;i<=28;i++)
        for(k=31;k<=48;k++)
            maparray[i][k]=' ';
}
void Map::mapupdate(const int i,const int k,const char symbol)
{
    maparray[i][k]=symbol;
}
void Map::mapdelete(const int i,const int k,const char symbol)
{
    maparray[i][k]='\0';
}
void Map::showplayer(Player& p)
{
    mapupdate(p.getrow(),p.getcolumn(),p.getplayer());
}
void Map::deleteplayer(Player& p)
{
    mapdelete(p.getrow(),p.getcolumn(),p.getplayer());
}
void Map::showequips(Equipment& e)
{
    if(e.getrow_()!=-1&&e.getcolumn_()!=-1)
        mapupdate(e.getrow_(),e.getcolumn_(),e.getequipment());
}
void Map::deletequips(Equipment& e)
{
    mapdelete(e.getrow_(),e.getcolumn_(),e.getequipment());
}
void Map::showmonster(Monster& m)
{
    if(m.getrow()!=-1&&m.getcolumn()!=-1)
        mapupdate(m.getrow(),m.getcolumn(),m.getmonster());
}
void Map::deletemonster(Monster& m)
{
    mapdelete(m.getrow(),m.getcolumn(),m.getmonster());
}
void Map::showapple(Apple& a)
{
    if(a.getrow()!=-1&&a.getcolumn()!=-1)
        mapupdate(a.getrow(),a.getcolumn(),a.getapple());
}
void Map::deleteapple(Apple& a)
{
    mapdelete(a.getrow(),a.getcolumn(),a.getapple());
}
char Map::mapelement(int x, int y)
{
    return maparray[x][y];
}
void Map::showmap()
{
    int i,k;
    for(i=0;i<30;i++)
        for(k=0;k<50;k++)
        {
            cout<<maparray[i][k];
            if(k==49)
                cout<<'\n';
        }
    
}
