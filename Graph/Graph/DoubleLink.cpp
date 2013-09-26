//
//  DoubleLink.cpp
//  Graph
//
//  Created by nai7 on 13-9-16.
//  Copyright (c) 2013年 nai7. All rights reserved.
//
template <class T>
struct List_node {
    List_node* next;
    List_node* prev;
    T data;
};
//链表的迭代器
template<class T, class Ref, class Ptr>
class List_iterator
{
public:
    List_node<T> *node;
    void Incr() { node = node->next; }
    void Decr() { node = node->prev; }
public:
    typedef T value_type;
    typedef Ptr pointer;
    typedef Ref reference;
    
    typedef List_iterator<T, T&, T*>             iterator;        //迭代器
    typedef List_iterator<T, const T&, const T*> const_iterator;
    typedef List_iterator<T, Ref, Ptr>           self;
    
    List_iterator(List_node<T>* x): node(x) {}     //接受链表结点的构造函数，很管用
    List_iterator() {}
    reference operator*() const { return node->data; }                        //解引用重载
    pointer operator->() const { return &(operator*()); }                     //箭头重载
    self& operator++() { this->Incr(); return *this; }                        //前增重载
    self operator++(int) { self tmp = *this; this->Incr(); return tmp; }      //后增重载
    self& operator--() { this->Decr(); return *this; }                        //前减重载
    self operator--(int) { self tmp = *this; this->Decr(); return tmp; }      //后减重载
    bool operator==(const List_iterator& x) const { return node == x.node; }  //相等重载
    bool operator!=(const List_iterator& x) const { return node != x.node; }  //不相等重载
};