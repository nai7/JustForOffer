//
//  main.cpp
//  STLAlgorithms
//
//  Created by nai7 on 13-9-17.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(int argc, const char * argv[])
{
    vector<int> a;
    
    for(int i =0;i<10;i++)
        a.push_back(100-i);

    vector<int>::iterator iter = a.begin();
    
    //fill(a.begin(),a.end(),5);
    
    const int counts = count(a.begin(),a.end(),5);
    cout << counts<<endl;
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    random_shuffle(a.begin(),a.end());
    while(iter != a.end()){
        cout<<*iter<< " "<<endl;
        iter++;
    }
    cout<<endl;
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

