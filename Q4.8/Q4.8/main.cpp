//
//  main.cpp
//  Q4.8
//
//  Created by nai7 on 13-9-20.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node* parent;
};

void print(Node* head, int level){
    vector<int> v;
    for(int i=0; i<level; ++i){
        v.push_back(head->value);
        head = head->parent;
    }
    while(!v.empty()){
        cout<<v.back()<<" ";
        v.pop_back();
    }
    cout<<endl;
}

void find_sum(Node* head,int sum)
{
    if(head == NULL)
        return;
    Node* node = head;  
    int tmp = 0;
    for(int i =1 ;node != NULL;++i)
    {
        tmp += node->value;
        if(tmp == sum){
            print(node, i);
        }
        node = node->parent;
    }

    find_sum(head->left, sum);
    find_sum(head->right,sum);
}

int foo(int x)
{
    
    return x&-x;
    
}

int main(int argc, const char * argv[])
{
    
    cout<< foo(2^31-3)<<endl;

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

    