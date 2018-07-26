//
//  main.cpp
//  SimpleNethack
//
//  Created by MillionBenjamin on 2018/5/13.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#include"Map.h"
#include"Player.h"
#include "Monster.h"
#include "Apple.h"
#include "Equipment.h"
#include "Game.h"
#include <iostream>
int main()
{
    Game A;
    while(1)
    {
        system("cls");
        A.gameinterface();
        A.movearound();
    }
    return 0;
}
