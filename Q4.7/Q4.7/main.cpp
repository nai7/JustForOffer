//
//  main.cpp
//  Q4.7
//
//  Created by nai7 on 13-9-19.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>

#include <string>

struct Node{
    int value;
    Node* left;
    Node* right;
};

bool match(Node* r1,Node* r2){
    if(r1==NULL&&r2 == NULL)
        return true;
    else if (r1==NULL||r2 == NULL)
        return false;
    else if(r1->value != r2->value)
        return false;
    else return (match(r1->left,r2->left)&&match(r1->right,r2->right));
}

bool subtree(Node* r1, Node* r2){
    if(r1 == NULL) return false;
    else if(r1->value == r2->value){
        if(match(r1, r2)) return true;
    }
    else return subtree(r1->left, r2) || subtree(r1->right, r2);
}


bool contain_tree(Node* r1, Node* r2){
    if(r2 == NULL) return true;
    else return subtree(r1, r2);
}



int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

