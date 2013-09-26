//
//  main.cpp
//  strToInt
//
//  Created by nai7 on 13-9-11.
//  Copyright (c) 2013年 nai7. All rights reserved.
//
#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 10000000

#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;
int a[1+N/BITSPERWORD];
void set(int i){
    a[i>>SHIFT]|=(1<<(i&MASK));
}
void clr(int i) {        a[i>>SHIFT] &= ~(1<<(i & MASK)); }
int  test(int i){ return a[i>>SHIFT] &   (1<<(i & MASK)); }

int main(int argc, const char * argv[])
{
    string str1 = "hello ";
    string str2 = "world!";
    str1.append(str2);
    str1.append(3,'!');
    str1.append(str2.begin(),str2.end());
    cout<<str1<<endl;
    string::iterator iter = str2.begin();

    
    string s1 = "hello world hello!", s2 = "hello";
    char* s3 = "boy";
    cout<<s1.find(s2)<<endl;    //从s1的第0个位置开始查找s2，返回第一个匹配串的下标：0
    cout<<s1.find(s2, 1)<<endl;  //从s1的第1个位置开始查找，返回12
    cout<<s1.find(s3, 0)<<endl; //s1中查找s3(char*),失败，返回string::npos(-1)
    cout<<s1.find(s3, 0, 10)<<endl; //s1中查找s3，从位置0开始，查找长度为10
    cout<<s1.find('e', 'l')<<endl; //从s1的第0个位置开始查找字符'l',返回第一个匹配下标：2
    
//    string getStr;
//    getline(cin,getStr);
    cout<<atoi("1234")<<endl;
    
    cout<<s1.substr(6)<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}

