//
//  main.cpp
//  scanfTest
//
//  Created by nai7 on 13-9-14.
//  Copyright (c) 2013年 nai7. All rights reserved.
//
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[])
{

    // insert code here...
    int n ,m= 0;
    int flag=false,first=true;
    while(cin>>n>>m){
        if(first&&n*m)
        {
            cout<<n*m<<" "<<m-1;
            flag=true;
        }
        else if(n*m)
        {
            cout<<" "<<n*m<<" "<<m-1;
            flag=true;
        }
        first=false;
    }
    if(!flag)
    {
        cout<<"0 0";
    }

    return 0;
}

