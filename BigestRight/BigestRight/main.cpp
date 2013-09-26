//
//  main.cpp
//  BigestRight
//
//  Created by nai7 on 13-9-21.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>


int MaxDiff_Solution3(int numbers[], unsigned length)
{
    if(numbers == NULL || length < 2)
        return 0;
    
    int max = numbers[0];
    int maxDiff =  max - numbers[1];
    
    for(int i = 2; i < length; ++i)
    {
        if(numbers[i - 1] > max)
            max = numbers[i - 1];
        
        int currentDiff = max - numbers[i];
        if(currentDiff > maxDiff)
            maxDiff = currentDiff;
    }
    
    return maxDiff;
}
int main(int argc, const char * argv[])
{
    int numbers[] = {2, 4, 1, 16, 7, 5, 11, 9};
    
    int res = MaxDiff_Solution3(numbers, sizeof(numbers)/sizeof(numbers[0]));
    std::cout<<res;
    return 0;
}

