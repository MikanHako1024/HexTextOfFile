
/*
MyStrDeal
*/


/*
int MystrFind(char *str, char ch, int no);
int Mystrcmp(char *str1, char *str2);
int Mystradd(char *str, int top, char *addstr, int s, int e);
*/


#ifndef _MYSTRDEAL

#define _MYSTRDEAL

int MystrFind(char *str, char ch, int no)
	// 找到 str 的 第no个 ch字符 的下标 
	// no<=0 时 找到最后一个 ch字符 的下标
	// 若找到 返回下标  若未找到 则返回 -1 
{
	int z=0, tz=-1, tno=0;
	while(str[z]!='\0')
	{
		if(str[z]==ch)
		{
			tno++;
			if(tno==no)return z;
			tz=z;
		} 
		z++;
	}
	if(no<=0)return tz; 
	else return -1;
}

int Mystrcmp(char *str1, char *str2)
	// 字符串比较
	// 若两字符串相同 返回 1  否则 返回 -1 
	// （ 一者先到 '\0' 时 结束判断 之前部分相同 则返回 1 ） 
{
	int z=0;
	while( (str1[z]!='\0') && (str2[z]!='\0') )
	{
		if( str1[z]!=str2[z] )
			return 0;
		z++;
	}
	return 1;
}

int Mystradd(char *str, int top, char *addstr, int s, int e)
	// 把 addstr 的 s到e(含e) 添加到 str 的 以top为首 的位置
	// e -1时 为 addstr 的 s到'\0' 
	// 返回结尾下标 
{
	if(e==-1)e--;
	while( s!=e+1 && addstr[s]!='\0' ) 
		str[top++]=addstr[s++];
	str[top]='\0'; // 结尾 
	return top;
}

void _Mystradd(char *str1, int *ptop, char *str2, int s, int e)\
	// ?
{
	int temp;
	temp=Mystradd(str1, *ptop, str2, s, e);
	*ptop=temp;
}



int MystrFind(char *str, char ch, int no);
int Mystrcmp(char *str1, char *str2);
int Mystradd(char *str, int top, char *addstr, int s, int e);

#endif

