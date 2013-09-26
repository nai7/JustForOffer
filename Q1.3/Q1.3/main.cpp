//
//  main.cpp
//  Q1.3
//
//  Created by nai7 on 13-9-14.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>
using namespace std;

void removeDuplicate(char* s){
    unsigned long len =strlen(s);
    if(len<2)
        return ;
    int p = 0;
    for(int i = 0;i<len ;i++){
        if (s[i] != '\0') {
            s[p++] = s[i];
            for(int j= i+1;j<len;++j)
            {
                if(s[i] == s[j])
                    s[j]='\0';
            }
        }
    }
    s[p] = '\0';

}


int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

