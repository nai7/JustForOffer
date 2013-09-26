//
//  main.cpp
//  Q1.2
//
//  Created by nai7 on 13-9-12.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>

using namespace std;


void swap(char &a,char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

void turnOver1(char* str){
    unsigned int n = strlen(str);
    char* start = str;
    char* end = str+n-1;
    while(start<=end)
    {
        swap(*start,*end);
        start++;
        end--;
    }
}


int main(int argc, const char * argv[])
{

    // insert code here...
    char a = 'L';
    char b = 'K';
    swap(a,b);
    cout<<a<<endl;
    cout<<b<<endl;
    char str[] = "1234567";
    turnOver1(str);
    cout<<str<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}

