//
//  Apple.h
//  SimpleNethack
//
//  Created by MillionBenjamin on 2018/5/14.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#ifndef Apple_h
#define Apple_h

class Apple
{
public:
    Apple();
    ~Apple();
    
    char getapple();
    int getrow();
    int getcolumn();
    int gethp();
    
    void setrow(int x);
    void setcolumn(int y);
    void sethp(int h);
private:
    int hp;
    char apple;
    int row;
    int column;
};


#endif /* Apple_h */
