//
//  main.cpp
//  Q8.1
//
//  Created by nai7 on 13-9-17.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>

using namespace std;
void mul(long long c[2][2],long long a[2][2],long long b[2][2])
{
    long long t[4];
    t[0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    t[1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    t[2] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    t[3] = a[1][0]*b[0][1] + a[1][1]*b[1][1];
    
    c[0][0] = t[0];
    c[0][1] = t[1];
    c[1][0] = t[2];
    c[1][1] = t[3];
}

void pow(long long s[2][2],long long a[2][2],long long n){  
    while (n>0) {
        if(n&1) mul(s,s,a);
        mul(a,a,a);
        n>>=1;
    }
}

long long fib2(long long  n){
    if(n < 1) return -1;
    if(n == 1 || n == 2) return 1;
    
    long long a[2][2] = { {1, 1}, {1, 0} };
    long long s[2][2] = { {1, 0}, {0, 1} };
    pow(s, a, n-2);
    return s[0][0] + s[0][1];
}

int main(int argc, const char * argv[])
{
    cout<<endl;
    for(int i=1; i<20; ++i)
        cout<<fib2(i)<<" ";
    cout<<endl;
    return 0;
    std::cout << "Hello, World!\n";
    return 0;
}

