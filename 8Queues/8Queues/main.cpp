//
//  main.cpp
//  8Queues
//
//  Created by nai7 on 13-9-20.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void PrintResult(int* arr,int n)
{
    for(int i =1;i<n+1;++i)
    {
        cout << "(" << i << "," << arr[i] << ")" << " ";
    }
    cout<<endl;
}

bool verify(int* arr,int i){
    for(int k =1;k<i;k++){
        if(arr[k] == arr[i] || abs(i-k) == abs(arr[i]-arr[k])){
            return false;
        }
    }
    
    return true;
}   

void Queen(int* arr,int i ,int n){
    for(int j = 1;j<n+1;j++){
        arr[i] = j;
        if(verify(arr,i)){
            if (i == n)
                PrintResult(arr, n);
            else{
                Queen(arr,i+1,n);
            }
        }
    }
}

int main(int argc, const char * argv[])
{               
    int* arr = new int[9];
    Queen(arr,1,8); 
    return 0;
}

