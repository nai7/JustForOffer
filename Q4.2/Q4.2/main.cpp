//
//  main.cpp
//  Q4.2
//
//  Created by nai7 on 13-9-13.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

const int maxn = 100;
bool visit[maxn];
bool g[maxn][maxn];
int n;
queue<int> q;

bool route(int src,int dst){
    q.push(src);
    visit[src] = true;
    while(!q.empty()){
        
        int node = q.front();
        q.pop();
        
        if(node == dst)
            return true;
        for(int i =0;i < n;++i)
        {
            if(g[node][i]&&!visit[i])
            {
                q.push(i);
                visit[i] = true;
            }
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

