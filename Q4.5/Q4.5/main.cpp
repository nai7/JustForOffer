//
//  main.cpp
//  Q4.5
//
//  Created by nai7 on 13-9-18.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* parent;
    Node* left;
    Node* right;
};

Node* FindNext(Node* node){
    if(node->right){
        node  = node->right;
        while(node->left){
            node = node->left;
        }
        return node;
    }
    else{
        Node* parent = node->parent;
        while(parent->left){
            parent = parent->left;
        }
        return parent;
    }
}


int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

