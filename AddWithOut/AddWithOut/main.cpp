//
//  main.cpp
//  AddWithOut
//
//  Created by nai7 on 13-9-21.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>

int add(int num1, int num2)
{
    if(num2 == 0)
        return num1;
    
    int sum = num1 ^ num2;
    int carry = (num1 & num2) << 1;
    
    return add(sum, carry);
}

class A
{
public:
    virtual void Fun(int number = 10)
    {
        std::cout << "A::Fun with number " << number;
    }
};

class B: public A
{
public:
    virtual void Fun(int number = 20)
    {
        std::cout << "B::Fun with number " << number;
    }
};

int main()
{
    B b;
    A &a = b;
    a.Fun();
}



