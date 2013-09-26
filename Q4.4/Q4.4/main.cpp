//
//  main.cpp
//  Q4.4
//
//  Created by nai7 on 13-9-13.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <list>

using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
};

vector<list<Node*>> find_level_linked(Node* head){
    vector<list<Node*>> res;
    int level = 0;
    list<Node*> li;
    li.push_back(head);
    res.push_back(li);
    while(!res[level].empty()){
        list<Node*> l;
        list<Node*>::iterator iter;
        for(iter = res[level].begin();iter != res[level].end();++iter){
            Node* n = *iter;
            if(n->left) l.push_back(n->left);
            if(n->right) l.push_back(n->right);
        }
        ++level;
        res.push_back(l);
    }
    return res;
}

int main(int argc, const char * argv[])
{

    // insert code here...
    float a = 1.1;
    float b = 0.55*2;
    if(a == b)
        cout<<"equal!!"<<endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}

    