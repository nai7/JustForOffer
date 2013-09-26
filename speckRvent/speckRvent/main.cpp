//
//  main.cpp
//  speckRvent
//
//  Created by nai7 on 13-9-20.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;


stack<string> Stack;

int main(int argc, const char * argv[])
{
//    string s = "asdsafda";
//    string b = s.substr(0,2);
//    cout<<b<<endl;
//    
//    
    string str;
    getline(cin,str);
    
    int size = str.length();
    int i = 0;
    int start = 0;
    int end = 0;
    for(;i<size+1;i++){
        if(str[i] == ' ' || str[i] == '\0'){
            end = i;
            string tep;
            tep = str.substr(start,end-start);
            Stack.push(tep);
            start =i;
            end ++;
        }
    }
    
    while (!Stack.empty()) {
        string temp = Stack.top();
        Stack.pop();
        cout<<temp<<" ";
    }
    
    return 0;
}

