//
//  main.cpp
//  TestGetChar
//
//  Created by nai7 on 13-9-14.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>
#include <string.H>


int main(int argc, const char * argv[])
{
//    int n, e, flag = 0;
//    while(scanf("%d%d",&n,&e) != EOF){
//    
//    }
    int n, e, flag = 0;
    while (scanf("%d%d", &n, &e) != EOF)
    {
        if( n*e )
        {
            if(flag)
                printf(" ");
            else
                flag = 1;
            printf("%d %d", n*e, e-1);
        }
    }
    if(!flag) printf("0 0");
    
    return 0;
    
    
}

