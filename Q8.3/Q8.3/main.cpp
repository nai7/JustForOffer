//
//  main.cpp
//  Q8.3
//
//  Created by nai7 on 13-9-17.
//  Copyright (c) 2013年 nai7. All rights reserved.
//  返回一个集合的所有子集

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> getResult(int a[], int index, int n){
    vector<vector<int>> result ;
    if(index == n){
        vector<int> subset ;
        result.push_back(subset);
    }
    else{
        vector<vector<int>> rresult = getResult(a, index+1, n);
        int v = a[index];
        for(int i=0; i<rresult.size(); ++i){
            vector<int> subset = rresult[i];
            result.push_back(subset);
            subset.push_back(v);
            result.push_back(subset);
        }
    }
    return result;
}

void printLast(int a[],int index, int n){
    if(index == n){
        cout<<a[n]<<endl;
    }
    else{
        int i = 0;
        for(;i<2;i++)
        {
            if(i)
            {
                printLast(a,index+1,n);
            }
            else
            {
                cout<<a[index]<<" ";
                printLast(a,index+1,n);
            }
        }
    }
}

void NotPrintLast(int a[],int index, int n){
    if(index == n){
        cout<<endl;
    }
    else{
        int i = 0;
        for(;i<2;i++)
        {
            if(i)
            {
                NotPrintLast(a,index+1,n);
            }
            else
            {
                cout<<a[index]<<" ";
                NotPrintLast(a,index+1,n);
            }
        }
    }
}

//不能先打印后递归，不然就是乱的！一定要完全确定情况再进行打印
//比如我一个函数打印完了 1 2 3 ，往前回溯一步的时候打印了应该打印1 2，却先打印了一个2。
//这样的写法只能打印当前的节点，不能打印搜索到此节点的所有节点。
//一般来说采用一个队列来保持递归的路径，然后打印
void printSubset(int a[],int index, int n){
    printLast(a,0,n);
    NotPrintLast(a,0,n);
}


int find(char *A,int *a,int i,int n,int value)
{
    if(i<n)
    {
        if(i==n-1)
        {
            static int j=1;
            printf("第%d个子集：{",j);
            for(int j=0;j<n;++j)
            {
                if(a[j])
                    printf("%c",A[j]);
            }
            printf("}\n");
            j++;
        }
        i++;
        a[i]=1;
        find(A,a,i,n,0);
        a[i]=0;
        find(A,a,i,n,1);
    }
    return 1;
}

typedef vector<vector<int> > vvi;
typedef vector<int> vi;
vvi get_subsets(int a[], int n){ //O(n2^n)
    vvi subsets;
    int max = 1<<n;
    for(int i=0; i<max; ++i){
        vi subset;
        int idx = 0;
        int j = i;
        while(j > 0){
            if(j&1){
                subset.push_back(a[idx]);
            }
            j >>= 1;
            ++idx;
        }
        subsets.push_back(subset);
    }
    return subsets;
}

int main(int argc, const char * argv[])
{
    char A[]={'a','b','c'};
    int a[4]={0};
    find(A,a,-1,3,0);

    return 0;
}

