
//
//  Equipment.h
//  SimpleNethack
//
//  Created by MillionBenjamin on 2018/5/14.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#ifndef Equipment_h
#define Equipment_h

#include<string>
using namespace std;
class Equipment
{
public:
    Equipment();
    ~Equipment();
    
    int getatk_();
    int getdef_();
    int getrow_();
    int getcolumn_();
    char getequipment();
    string getequ();
    
    void setatk_(int a);
    void setdef_(int d);
    void setequipment(char e);
    void setequ(string eq);
    void setrow_(int x);
    void setcolumn_(int y);
    
private:
    char equipment;
    string equ;
    int atk_;
    int def_;
    int row_;
    int column_;
};

#endif /* Equipment_h */
