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
#include <termios.h>

//Xcode doesn't have
//#include <conio.h>
//#include <window.h>

char _getch()
{
    struct termios stored_settings;
    struct termios new_settings;
    tcgetattr(0, &stored_settings);
    new_settings = stored_settings;
    new_settings.c_lflag &= (~ICANON);
    new_settings.c_cc[VTIME] = 0;
    new_settings.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &new_settings);
    
    char c;
    
    c = getchar();
    
    tcsetattr(0, TCSANOW, &stored_settings);
    
    return c;
}
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
int Game::floor=1;
Game::Game()
{
    sword.setatk_(1);
    sword.setdef_(0);
    sword.setequipment('!');
    sword.setequ("sword");
    shield.setatk_(0);
    shield.setdef_(1);
    shield.setequipment('&');
    shield.setequ("shield");
    mon.setmonster('W');
    mon.sethp(1);
    mon.setatk(2);
    srand(time(NULL));
    int i=rand()%3+2;
    int x=0,y=0;
    switch (i)
    {
        case 2:
            x=rand()%8+1;
            y=rand()%18+31;
            break;
        case 3:
            x=rand()%8+21;
            y=rand()%18+1;
            break;
        case 4:
            x=rand()%8+21;
            y=rand()%18+31;
            break;
        default:
            break;
    }
    mon.setrow(x);
    mon.setcolumn(y);
    int i_=rand()%4+1;
    int x_=0,y_=0;
    do{
        switch(i_)
        {
            case 1:
                x_=rand()%8+1;
                y_=rand()%18+1;
                break;
            case 2:
                x_=rand()%8+1;
                y_=rand()%18+31;
                break;
            case 3:
                x_=rand()%8+21;
                y_=rand()%18+1;
                break;
            case 4:
                x_=rand()%8+21;
                y_=rand()%18+31;
                break;
            default:
                break;
        }
    }while((x_==x)&&(y_==y));
    sword.setrow_(x_);
    sword.setcolumn_(y_);
    int i__=rand()%4+1;
    int x__=0,y__=0;
    do{
        switch(i__)
        {
            case 1:
                x__=rand()%8+1;
                y__=rand()%18+1;
                break;
            case 2:
                x__=rand()%8+1;
                y__=rand()%18+31;
                break;
            case 3:
                x__=rand()%8+21;
                y__=rand()%18+1;
                break;
            case 4:
                x__=rand()%8+21;
                y__=rand()%18+31;
                break;
            default:
                break;
        }
    }while((x__==x)&&(y__==y)&&(x__=x_)&&(y__=y_));
    shield.setrow_(x__);
    shield.setcolumn_(y__);
}
Game::~Game()
{
    
}
void Game::gameinterface()
{
    M.maperase();
    if(a.getrow()==-1)
    {
        reset();
    }
    cout<<P;
    cout<<mon;
    cout<<"Floor      : "<<floor<<endl;
    M.showplayer(P);
    M.showmonster(mon);
    M.showequips(sword);
    M.showequips(shield);
    M.showapple(a);
    M.showmap();
}
int Game::hereisok(int x, int y)
{
    if(M.mapelement(x, y)=='-')
        return 0;
    if(M.mapelement(x, y)=='|')
        return 0;
    if(M.mapelement(x, y)=='W')
        return 4;
    if(M.mapelement(x, y)=='&')
        return 3;
    if(M.mapelement(x, y)=='!')
        return 3;
    if(M.mapelement(x, y)=='#')
        return 2;
    if(M.mapelement(x, y)==' ')
        return 1;
    return 1;
}
bool Game::playertoequips()
{
    if(P.getrow()==sword.getrow_()&&P.getcolumn()==sword.getcolumn_())
    {
        P.setsword(P.getsword()+1);
        P.addatk(sword.getatk_());
        P.adddef(sword.getdef_());
        sword.setrow_(-1);
        sword.setcolumn_(-1);
        return true;
    }
    if(P.getrow()==shield.getrow_()&&P.getcolumn()==shield.getcolumn_())
    {
        P.setshield(P.getsword()+1);
        P.addatk(shield.getatk_());
        P.adddef(shield.getdef_());
        shield.setrow_(-1);
        shield.setcolumn_(-1);
        return true;
    }
    return false;
}
bool Game::playertoapple()
{
    if(P.getrow()==a.getrow()&&P.getcolumn()==a.getcolumn())
    {
        P.addhp(a.gethp());
        a.setrow(-1);
        a.setcolumn(-1);
        floor++;
        return true;
    }
    return false;
}
bool Game::monstertoequips()
{
    if(mon.getrow()==sword.getrow_()&&mon.getcolumn()==sword.getcolumn_())
    {
        sword.setrow_(-1);
        sword.setcolumn_(-1);
        return true;
    }
    if(mon.getrow()==shield.getrow_()&&mon.getcolumn()==shield.getcolumn_())
    {
        shield.setrow_(-1);
        shield.setcolumn_(-1);
        return true;
    }
    return false;
}
bool Game::playertomonster()
{
    int monHPnow=mon.gethp();
    if(!(P.getrow()==mon.getrow()&&P.getcolumn()==mon.getcolumn()))
        return false;
    else
    {
        P.dechp(mon.getatk()-P.getdef());
        mon.dechp(P.getatk());
    }
    if(P.gethp()<=0||mon.gethp()>0)
    {
        P.setrow(-1);
        P.setcolumn(-1);
        system("clear");
        cout<<"You Die!"<<endl;
        cout<<"You Have Reached Floor "<<floor<<endl;
        exit(0);
        return true;
    }
    if(mon.gethp()<=0)
    {
        mon.setrow(-1);
        mon.setcolumn(-1);
        mon.sethp(monHPnow);
        return true;
    }
    return false;
}
void Game::meetdoor(Player &P)
{
    int x=P.getrow();
    int y=P.getcolumn();
    if((x==4&&y==19)||(x==24&&y==19))
        P.setcolumn(y+12);
    if((x==4&&y==30)||(x==24&&y==30))
        P.setcolumn(y-12);
    if((x==9&&y==10)||(x==9&&y==40))
        P.setrow(x+12);
    if((x==20&&y==10)||(x==20&&y==40))
        P.setrow(x-12);
}
void Game::meetdoor(Monster &M)
{
    int x=M.getrow();
    int y=M.getcolumn();
    if((x==4&&y==19)||(x==24&&y==19))
        M.setcolumn(y+12);
    if((x==4&&y==30)||(x==24&&y==30))
        M.setcolumn(y-12);
    if((x==9&&y==10)||(x==9&&y==40))
        M.setrow(x+12);
    if((x==20&&y==10)||(x==20&&y==40))
        M.setrow(x-12);
}
void Game::moveplayer(int i, int k, Player &P)
{
    if(hereisok(i, k)!=0)
    {
        P.setrow(i);
        P.setcolumn(k);
        meetdoor(P);
        playertoequips();
        playertomonster();
        playertoapple();
    }
}
void Game::movemonster(int i, int k, Monster &M)
{
    M.setrow(i);
    M.setcolumn(k);
    meetdoor(M);
    monstertoequips();
    playertomonster();
}
int Game::whichroom(int x, int y)
{
    if((x>=1&&x<=8)&&(y>=1&&y<=18))
        return 1;
    if((x>=1&&x<=8)&&(y>=31&&y<=48))
        return 2;
    if((x>=21&&x<=29)&&(y>=31)&&(y<=48))
        return 3;
    if((x>=21&&x<=29)&&(y>=1&&y<=18))
        return 4;
    return 0;
}
void Game::howmonstergo()
{
    int px=P.getrow();
    int py=P.getcolumn();
    int mx=mon.getrow();
    int my=mon.getcolumn();
    
    int proom=whichroom(px, py);
    int mroom=whichroom(mx, my);
    int xdiff=px-mx;
    int ydiff=py-my;
    int rdiff=mroom-proom;
    
    if(rdiff==0)
    {
        if((xdiff>0)&&(ydiff>0))
        {
            mx++;
            my++;
        }
        if((xdiff>0)&&(ydiff==0))
        {
            mx++;
        }
        if((xdiff>0)&&(ydiff<0))
        {
            mx++;
            my--;
        }
        if(xdiff<0&&ydiff>0)
        {
            mx--;
            my++;
        }
        if(xdiff<0&&ydiff==0)
        {
            mx--;
        }
        if(xdiff<0&&ydiff<0)
        {
            mx--;
            my--;
        }
        if(xdiff==0&&ydiff>0)
        {
            my++;
        }
        if(xdiff==0&&ydiff==0)
        {
            
        }
        if(xdiff==0&&ydiff<0)
        {
            my--;
        }
    }
    if(rdiff==1)
    {
        switch (proom)
        {
            case 1:
                if(mx>4)
                    mx--;
                if(mx<4)
                    mx++;
                if(my>31)
                    my--;
                if(my==31&&mx==4)
                    my--;
                break;
            case 2:
                if(mx>21)
                    mx--;
                if(my>40)
                    my--;
                if(my<40)
                    my++;
                if(mx==21&&my==40)
                    mx--;
                break;
            case 3:
                if(mx>24)
                    mx--;
                if(mx<24)
                    mx++;
                if(my<18)
                    my++;
                if(my==18&&mx==24)
                    my++;
                break;
            default:
                break;
        }
    }
    if(rdiff==3)
    {
        if(mx>21)
            mx--;
        if(my>10)
            my--;
        if(my<10)
            my++;
        if(mx==21&&my==10)
            mx--;
    }
    if(rdiff==-1)
    {
        switch (proom)
        {
            case 2:
                if(mx>4)
                    mx--;
                if(mx<4)
                    mx++;
                if(my<18)
                    my++;
                if(my==18&&mx==4)
                    my++;
                break;
            case 3:
                if(my<40)
                    my++;
                if(my>40)
                    my--;
                if(mx<8)
                    mx++;
                if(mx==8&&my==40)
                    mx++;
                break;
            case 4:
                if(mx>24)
                    mx--;
                if(mx<24)
                    mx++;
                if(my>31)
                    my--;
                if(my==31&mx==24)
                    my--;
                break;
            default:
                break;
        }
    }
    if(rdiff==-3)
    {
        if(mx<8)
            mx++;
        if(my>10)
            my--;
        if(my<10)
            my++;
        if(mx==8&&my==10)
            mx++;
    }
    if(rdiff==2)
    {
        switch (mroom)
        {
            case 3:
                if(mx>21)
                    mx--;
                if(my>40)
                    my--;
                if(my<40)
                    my++;
                if(mx==21&&my==40)
                    mx--;
                break;
            case 4:
                if(mx>24)
                    mx--;
                if(mx<24)
                    mx--;
                if(my<18)
                    my++;
                if(my==18&&mx==24)
                    my++;
                break;
            default:
                break;
        }
    }
    if(rdiff==-2)
    {
        switch (mroom)
        {
            case 1:
                if(mx>4)
                    mx--;
                if(mx<4)
                    mx++;
                if(my<18)
                    my++;
                if(my==18&&mx==4)
                    my++;
                break;
            case 2:
                if(my<40)
                    my++;
                if(my>40)
                    my--;
                if(mx<8)
                    mx++;
                if(mx==8&&my==40)
                    mx++;
                break;
            default:
                break;
        }
    }
    movemonster(mx, my, mon);
}
void Game::movearound()
{
    
    int i=P.getrow();
    int k=P.getcolumn();
    char order=_getch();
    int whethershop=0;
    switch (order)
    {
        case 'q':
            i--;
            k--;
            moveplayer(i, k, P);
            break;
        case 'w':
            i--;
            moveplayer(i, k, P);
            break;
        case 'e':
            i--;
            k++;
            moveplayer(i, k, P);
            break;
        case 'a':
            k--;
            moveplayer(i, k, P);
            break;
        case 's':
            break;
        case 'd':
            k++;
            moveplayer(i, k, P);
            break;
        case 'z':
            i++;
            k--;
            moveplayer(i, k, P);
            break;
        case 'x':
            i++;
            moveplayer(i, k, P);
            break;
        case 'c':
            i++;
            k++;
            moveplayer(i, k, P);
            break;
        default:
            break;
    }
    if(mon.getrow()!=-1)
        howmonstergo();
}
void Game::reset()
{
    sword.setatk_(1);
    sword.setdef_(0);
    sword.setequipment('!');
    sword.setequ("sword");
    
    shield.setatk_(0);
    shield.setdef_(1);
    shield.setequipment('&');
    shield.setequ("shield");
    
    mon.setmonster('W');
    if(floor%5==0)
    {
        mon.setatk(mon.getatk()+6);
        mon.sethp(mon.gethp()+3);
    }
    
    a.sethp(1);
    if(floor%5==0)
        a.sethp(5);
    if(floor%10==0)
        a.sethp(10);
    a.setrow(28);
    a.setcolumn(48);
    
    P.setrow(1);
    P.setcolumn(1);
    
    srand(time(NULL));
    int i=rand()%3+2;
    int x=0,y=0;
    switch (i)
    {
        case 2:
            x=rand()%8+1;
            y=rand()%18+31;
            break;
        case 3:
            x=rand()%8+21;
            y=rand()%18+1;
            break;
        case 4:
            x=rand()%8+21;
            y=rand()%18+31;
            break;
        default:
            break;
    }
    mon.setrow(x);
    mon.setcolumn(y);
    
    int i_=rand()%4+1;
    int x_=0,y_=0;
    do{
        switch(i_)
        {
            case 1:
                x_=rand()%8+1;
                y_=rand()%18+1;
                break;
            case 2:
                x_=rand()%8+1;
                y_=rand()%18+31;
                break;
            case 3:
                x_=rand()%8+21;
                y_=rand()%18+1;
                break;
            case 4:
                x_=rand()%8+21;
                y_=rand()%18+31;
                break;
            default:
                break;
        }
    }while((x_==x)&&(y_==y));
    sword.setrow_(x_);
    sword.setcolumn_(y_);
    
    int i__=rand()%4+1;
    int x__=0,y__=0;
    do{
        switch(i__)
        {
            case 1:
                x__=rand()%8+1;
                y__=rand()%18+1;
                break;
            case 2:
                x__=rand()%8+1;
                y__=rand()%18+31;
                break;
            case 3:
                x__=rand()%8+21;
                y__=rand()%18+1;
                break;
            case 4:
                x__=rand()%8+21;
                y__=rand()%18+31;
                break;
            default:
                break;
        }
    }while((x__==x)&&(y__==y)&&(x__=x_)&&(y__=y_));
    shield.setrow_(x__);
    shield.setcolumn_(y__);
}

#endif /* Game_h */
