//
//  main.cpp
//  BSTbalance
//
//  Created by nai7 on 13-9-21.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>

using namespace std;

struct Node{
    int value ;
    Node* left;
    Node* right;
};

bool isBalanced(Node* head,int& depth){
    if(head == NULL)
    {
        depth = 0;
        return true;
    }
    
    int leftDept = 0;
    int rightDept = 0;
    if(isBalanced(head->left, leftDept) && isBalanced(head->right, rightDept))
    {
        int diff = leftDept - rightDept;
        if(diff <= 1 && diff >= -1)
        {
            depth = 1 + (leftDept > rightDept ? leftDept : rightDept);
            return true;
        }
    }
    return false;
}


int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

