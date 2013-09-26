//
//  main.cpp
//  Q8.2
//
//  Created by nai7 on 13-9-17.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef long long ll;
const int m = 20;
const int n = 20;

ll path(ll m,ll n){
    if(m == 1|| n == 1)
        return 1;
    else return path(m-1, n)+path(m, n-1);

}

struct point{
    int x;
    int y;
};

int g[m][n];

//如果场地中间可能有地雷
bool get_path(int m,int n)
{
    point p;
    p.x=m;
    p.y=n;
    stack<point> sp;
    sp.push(p);
    if(n==1&& m==1) return true;
    bool suc =false;
    if(m>=1&&g[m-1][n])
        suc =get_path(m-1, n);
    if(!suc && n>1 && g[m][n-1])
        suc =get_path(m,n-1);
    if(!suc)
        sp.pop();
    return suc;
}

vector<point> vp;
void print_paths(int m,int n,int M,int N,int len){
    if (g[m][n] == 0) {
        return ;
    }
    point p ;
    p.x = m;
    p.y = n;
    vp[len++] = p;
    if(m == M && n == N){
        for(int i=0; i<len; ++i)
            cout<<"("<<vp[i].y<<", "<<vp[i].x<<")"<<" ";
        cout<<endl;
    }
    else{
        print_paths(m, n+1, M, N, len);
        print_paths(m+1, n, M, N, len);
    }
}


int main(int argc, const char * argv[])
{
    // insert code here...
    cout<<path(5,5)<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}

