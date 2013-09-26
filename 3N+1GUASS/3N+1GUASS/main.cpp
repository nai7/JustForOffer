//
//  main.cpp
//  3N+1GUASS
//
//  Created by nai7 on 13-9-17.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>

using namespace std;
const int maxNum = 5000;

int a[maxNum];

//num == 1 表示已经输入的数；
//num == 2 表示被覆盖的数；
//num == 3 表示不在数组内，但是被覆盖的数

void overlap(int n){
    while(n != 1){
        if(!(n&1))
        {
            n = n/2;
        }
        else{
            n = (3*n+1)/2;
        }
        if(a[n] == 1 && n<=100)
        {
            a[n] = 2 ;
        }
        else if(a[n] == 0 && n<=100)
        {
            a[n] = 3 ;
        }
    }
}
int main(int argc, const char * argv[])
{

    int times;
    scanf("%d",&times);
    int i= 0;
    for(;i<times;i++){
        int num;
        cin >> num;
        a[num] = 1;
    }
    int j = 0;
    for(;j<101;j++){
        if(a[j] == 1)
            overlap(j);
    }
    int k =101;
    bool head = true;
    for(;k>=1;k--){
        if(a[k] == 1)
        {
            if(head)
            {
                cout<<k;
                head = false;
                continue;
            }
            if(!head)
            {
                cout<<" "<<k;
            }
        }
    }
    
    return 0;
}

