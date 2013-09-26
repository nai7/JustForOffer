//
//  main.cpp
//  inputTest
//
//  Created by nai7 on 13-9-15.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, const char * argv[])
{

    // insert code here...
    
//    char str[8];
//    cin.getline(str, 5);
//    cout<<str<<endl;
//    cin.getline(str, 5);
//    cout<<str<<endl;
//    return 0;
    
//    cin 可以读取字符串和数组，cin的终止条件为 enter space tab
//
//    char str1[10], str2[10];
//    cin>>str1;
//    cin>>str2;
//    cout<<str1<<endl;
//    cout<<str2<<endl;
    
//    int a,b;
//    cin>>a>>b;
//    cout<<a<<" "<<b<<endl;
//    
//    int c,d;
//    while(cin>>c>>d){
//        cout << c<<" "<<d<<endl;
//    }
//    
//    char ch;
//    char a[20];
//    cin.getline(a, 5);
//    cin >>ch;
//    cout<<a<<endl;
//    cout<<(int)ch<<endl;
//    
//    string s ;
//    getline(cin,s);
//    
//    cout<<s<<endl;
//    const char* chars = s.c_str();
//    cout<<chars<<endl;
    
//    std::cout << "Hello, World!\n";
//    int a,b,c ;
//    char ar,br,cr;
//    scanf("%d%c%d",&a,&br,&c);
//    cout<<a<<" "<<br<<" "<<c<<" "<<endl;
//    scanf("%c%c%c",&ar,&br,&cr);
//    cout<<ar<<" "<<br<<" "<<cr<<" "<<endl;
    
    char *p, str[20];
    
    p = new char[20];
    
//    scanf("%s", p); /*从健盘输入字符串*/
//    scanf("%s", str);
//    printf("%s\n", p); /*向屏幕输出字符串*/
//    printf("%s\n", str);
//    int d;
//    scanf("%d",&d);
//    cout<<d<<endl;
//    long a;
//    scanf("%ld",&a);
//    cout<<a<<endl;
//    int a,b ;
//    scanf("%d%d",&a,&b);
////    scanf("%x%x%x",&a,&b,&c);
////    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
////    scanf("%d,%d,%d",&a,&b,&c);   
////    cout<<a<<" "<<b<<" "<<c<<" "<<endl;   
//    cout<<a<<" "<<b<<endl;
    
    string s;
    getline(cin,s);
    const char* crs = s.c_str();
    int a,b;
    sscanf(crs,"%d%d",&a,&b);
    cout<<a<<" "<<b<<endl;
    
    
    return 0;
}

