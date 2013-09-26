//
//  main.cpp
//  StructAndClass
//
//  Created by nai7 on 13-9-17.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

//class的默认方法和成员函数为 private 型
class CPoint{
    int x;
    int y;
    void print(){
        cout<<"x:"<<x<<" "<<"y:"<<y<<endl;
    }
public:
    CPoint(int x,int y){
        this->x = x;
        this->y = y;
    }
    void print1(){
        cout<<"x:"<<x<<" "<<"y:"<<y<<endl;
    }
    ~CPoint(){
        delete this;
    }

};

struct SPoint{
    int x;
    int y;
    void print(){
    cout<<"x:"<<x<<" "<<"y:"<<y<<endl;
    }
    
    SPoint(int x,int y){
        this->x = x;
        this->y = y;
    }
    ~SPoint(){
        delete this;
    }
    
private:
    void print1(){
        cout<<"x:"<<x<<" "<<"y:"<<y<<endl;
    }


};

class CBase
{
public:
    void print()                //public成员函数
    {
        cout << "CBase: print()..." << endl;
    }
};
class CDerived1 : CBase        //默认private继承
{
};

class CDerived2 : public CBase   //指定public继承
{
};

struct SDerived1 : CBase        //默认public继承
{
};

struct SDerived2 : private CBase  //指定public继承
{
};

int main(int argc, const char * argv[])
{

    // insert code here...
    //CPoint a(5,5);
    CPoint* a = new CPoint(5,5);
    a->print1();
    SPoint* b = new SPoint(5,5);
    b->print();
    CDerived1 cd1;
    CDerived2 cd2;
    SDerived1 sd1;
    SDerived2 sd2;
    
    cd2.print();
    sd1.print();
    
    char dest[20];
    const char* c ="kindom rush!";
    strcpy(dest, c);
    string dest2;
    const char*  src2 = "time is mana";
    int result = strcmp(c, src2);
    cout<< result<<endl;
    cout<<dest<<endl;
    
    
    
    

    return 0;
}

