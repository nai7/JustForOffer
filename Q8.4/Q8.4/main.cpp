//
//  main.cpp
//  Q8.4
//
//  Created by nai7 on 13-9-18.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;

vs premu(string s)
{
    vs result;
    if(s == "")
    {
        result.push_back("");
        return result;
    }
    string c = s.substr(0,1);
    vs res = premu(s.substr(1));
    for(int i = 0;i<res.size();++i){
        string t = res[i];
        for(int j =0;j<t.length();++j){
            string u = t;
            u.insert(j, c);
            result.push_back(u);
        }
    }
    return result;
}

vs preum1(string s){
    vs result;
    if (s == "") {
        result.push_back("");
        return result;
    }
    for(int i =0;i<s.length();++i){
        string c =s.substr(i,1);
        string t = s;
        vs res = preum1(t.erase(i,1));
        for(int j=0; j<res.size(); ++j){
            result.push_back(c + res[j]);
        }
    }
    return result;
}


int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

