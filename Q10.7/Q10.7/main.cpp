//
//  main.cpp
//  Q10.7
//
//  Created by nai7 on 13-9-13.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>

#include <queue>
using namespace std;

struct cmp1{
    bool operator ()(int &a,int &b){
        return a>b;//最小值优先
    }
};

int getMin(int a,int b,int c){
    int min = a;
    if(a>b)
        min = b;
    if(b>c)
        min = c;
    return min;
    
}

void print(int n){
    for(int k = 300;k<n;k++)
    {
        queue<int> q3;
        queue<int> q5;
        queue<int> q7;
        
        q3.push(3);
        q5.push(5);
        q7.push(7);
        
        for(int i=3;i<k;i++){
            int temp3 = q3.front();
            int temp5 = q5.front();
            int temp7 = q7.front();
            int min = getMin(temp3, temp5, temp7);
            if(min == temp3)
            {
                q3.push(temp3*3);
                q5.push(temp3*5);
                q7.push(temp3*7);
                q3.pop();
            }
            if(min == temp5)
            {
                q5.push(temp5*5);
                q7.push(temp5*7);
                q5.pop();
            }
            if(min == temp7)
            {
                q7.push(temp3*7);
                q7.pop();
            }
        }
        cout<<getMin(q3.front(),q5.front(),q7.front())<<endl;
        cout<<q3.front()<<" "<<q5.front()<<" "<<q7.front()<< " "<<endl;
        
        priority_queue<int,vector<int>,cmp1> q13;
        priority_queue<int,vector<int>,cmp1> q15;
        priority_queue<int,vector<int>,cmp1> q17;
        
        
        q13.push(3);
        q15.push(5);
        q17.push(7);
        
        for(int i=3;i<k;i++){
            int temp3 = q13.top();
            int temp5 = q15.top();
            int temp7 = q17.top();
            int min = getMin(temp3, temp5, temp7);
            if(min == temp3)
            {
                q13.push(temp3*3);
                q15.push(temp3*5);
                q17.push(temp3*7);
                q13.pop();
            }
            if(min == temp5)
            {
                q15.push(temp5*5);
                q17.push(temp5*7);
                q15.pop();
            }
            if(min == temp7)
            {
                q17.push(temp3*7);
                q17.pop();
            }
        }
        cout<<getMin(q13.top(),q15.top(),q17.top())<<endl;
        cout<<q13.top()<<" "<<q15.top()<<" "<<q17.top()<< " "<<endl;
        // insert code here...

        cout<<endl;
    }
    
}



int main(int argc, const char * argv[])
{
    int a = 15;
    int b = 4;
    a = a^b;
    b = a^b;
    a = a^b;
    cout<<a<<" "<<b<<endl;
    print(500);
    
    return 0;
}

