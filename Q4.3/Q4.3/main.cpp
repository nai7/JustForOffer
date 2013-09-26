//
//  main.cpp
//  Q4.3
//
//  Created by nai7 on 13-9-13.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* create_min_higth_tree(Node* head,int a[],int start,int end){

    if(start<end)
    {
        int mid = (start+end)>>1;
        head->data = a[mid];
        Node* left = new Node();
        Node* right = new Node();
        head->left = left;
        head->right = right;
        create_min_higth_tree(head->left,a ,start,mid-1);
        create_min_higth_tree(head->right,a ,mid+1,end);
    }
    
    return head;
    
}



int main(int argc, const char * argv[])
{

    // insert code here...
    int a[] = {1,2,3,4,5,6,7,8,9};
    Node* head = new Node();
    Node* result = create_min_higth_tree(head, a, 0, 8);
    

    
    std::cout << "Hello, World!\n";
    return 0;
}

