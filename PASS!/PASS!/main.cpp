
#include <iostream>
#include <string.h>
#include "stdlib.h"
using namespace std;

const char* Pass(char* str){
	unsigned long len = strlen(str);
	char* head = str;
	int startAnum = 0;
	int endAnum = 0;
	int mediumAnum = 0;
	int Pnums = 0;
	int Tnums = 0;
	while(*head != '\0')
	{
		if(*head == 'P' || *head =='A' || *head == 'T'){
			if(*head == 'P')
				Pnums ++;
			if(*head =='T')
				Tnums ++;
		}
		else{
			return "NO";
		}
		head++;
	}
	if (Pnums >1 || Tnums >1)
	{
		return "NO";
	}
	char* head2 = str;
	int Pindex=0;
	int Tindex=0;
	bool p = false;
	bool t = false;
	while(*head2 != '\0'){
		if(*head2 == 'P')
		{
			p = true;
		}
		if (*head2 == 'T')
		{
			t= true;
		}
		if(!p)
			Pindex++;
		if(!t)
			Tindex++;
        
		head2++;
	}
    
	if(Tindex<=Pindex+1)
	{
		return "NO";
	}
    
	startAnum = Pindex;
	endAnum = len-Tindex-1;
	mediumAnum = Tindex-Pindex-1;
    
	bool flag = (endAnum == mediumAnum*startAnum);
    
	if (flag)
	{
		return "YES";
	}
	else{
		return "NO";
	}
    
}

int main()
{
	int times;
	scanf("%d",&times);
	int i =0;
	for(;i<times;i++){
		char s[1000];
		scanf("%s",&s);
		cout<<Pass(s)<<endl;
	}
	system("pause");
	return 0;
}

