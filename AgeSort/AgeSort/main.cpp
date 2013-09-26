//
//  main.cpp
//  AgeSort
//
//  Created by nai7 on 13-9-21.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>

void SortAges(int ages[], int length)
{
    if(ages == NULL || length <= 0)
        return;
    
    const int oldestAge = 99;
    int timesOfAge[oldestAge + 1];
    
    for(int i = 0; i <= oldestAge; ++ i)
        timesOfAge[i] = 0;
    
    for(int i = 0; i < length; ++ i)
    {
        int age = ages[i];
        if(age < 0 || age > oldestAge)
            return;
        
        ++ timesOfAge[age];
    }
    
    int index = 0;
    for(int i = 0; i <= oldestAge; ++ i)
    {
        for(int j = 0; j < timesOfAge[i]; ++ j)
        {
            ages[index] = i;
            ++ index;
        }
    }
}



int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

