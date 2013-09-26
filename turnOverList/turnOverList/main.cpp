//
//  main.cpp
//  turnOverList
//
//  Created by nai7 on 13-9-13.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
};

Node* createList(int i){
    Node* head = new Node();
    Node* temp = head;
    temp->value = i;
    while(--i){
        Node* next = new Node();
        next->value = i;
        temp->next = next;
        temp = temp->next;
    }
    return head;
}


void printList(Node* head){
    while(head){
        cout<<head->value<<" ";
        head = head->next;
    }
}

Node* reverseList(Node* head){
    if(head->next == NULL)
        return head;
    if(head== NULL)
        return NULL;
    Node* headNode = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return headNode;
}

int main(int argc, const char * argv[])
{
    Node* head = createList(100);
    printList(head);
    cout<<endl;
    Node* tail = reverseList(head);
    printList(tail);
    return 0;
}

