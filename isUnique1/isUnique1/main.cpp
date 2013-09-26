//
//  main.cpp
//  isUnique1
//
//  Created by nai7 on 13-9-12.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;
bool isUnique1(string s){
    
    bool a[256];
    memset(a,0,sizeof a);
    int len = s.length();
    for(int i = 0;i<len;i++){
        int v = (int)s[i];
        if(a[v])
            return false;
        a[v] = true;
    }
    return true;
    
}

bool isUnique2(string s){
    int a[8];
    memset(a,0,sizeof a);
    int len = s.length();
    for(int i =0;i<len;i++){
        int v = (int)s[i];
        int vidx = v/32;
        int shift = v%32;
        if(a[vidx]&(1<<shift))
            return false;
        a[vidx] |= (1<<shift);
     }
    return true;
}

int main(int argc, const char * argv[])
{
    
    cout <<boolalpha<< isUnique1("abcsd")<<endl;
    cout <<boolalpha<< isUnique2("adfaskljflasjd")<<endl;
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

