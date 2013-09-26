//
//  main.cpp
//  Q4.6
//
//  Created by nai7 on 13-9-18.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>

struct Node{
    int value;
    Node* parent;
    Node* left;
    Node* right;
};

bool father(Node* n1, Node* n2){
    if(n1 == NULL) return false;
    else if(n1 == n2) return true;
    else return father(n1->left, n2) || father(n1->right, n2);
}

void first_ancestor2(Node* head, Node* n1, Node* n2, Node* &ans){
    if(head==NULL || n1==NULL || n2==NULL) return;
    if(head && father(head, n1) && father(head, n2)){
        ans = head;
        first_ancestor2(head->left, n1, n2, ans);
        first_ancestor2(head->right, n1, n2, ans);
    }
}
int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

