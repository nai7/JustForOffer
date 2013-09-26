//
//  main.cpp
//  stringCombination
//
//  Created by nai7 on 13-9-21.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
    string str= "abcdefg";
    unsigned long N = str.size();
    int num  = pow(2.,N) ;
    for(int i=1;i<num;i++)
    {
        for(int j=0;j<N;j++)
        {
            if((i>>j)&1)
                cout<<str[j];
        }
        cout<<endl;
    }
    return 0;  
}
