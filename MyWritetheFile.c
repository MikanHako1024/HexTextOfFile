
/*
MyWritetheFile
*/


/*
void MyWritetheFile(char *FName_HT, char *FName_FI);
*/


#ifndef _MYWRITETHEFILE

#define _MYWRITETHEFILE


#include <stdio.h>
#include "MySizeConfig.h"
#include "MyGetName.c"

void MygetHex(char *pBuf_t, int len_t, char *pBuf_h)
	// text -> hex
{
	int zt, zh;
	char ct, ch;
	
	zh=0;
	for(zt=0; zt<len_t; zt++)
	{
		ct=pBuf_t[zt++];
		if('0'<=ct && ct<='9')ch=ct-'0'+0;
		else if('A'<=ct && ct<='Z')ch=ct-'A'+10;
		else ch=ct-'a'+10;
			// 考虑到小写字母 
		pBuf_h[zh]=ch;
		
		ct=pBuf_t[zt++];
		if('0'<=ct && ct<='9')ch=ct-'0'+0;
		else if('A'<=ct && ct<='Z')ch=ct-'A'+10;
		else ch=ct-'a'+10;
		pBuf_h[zh]<<=4;
		pBuf_h[zh]+=ch;
		
		zh++;
	}
}


// 待 防止覆盖原文件 
void MyWritetheFile(char *FName_HT, char *FName_FI)
	// text -> file
{
	FILE *fp_HT=NULL;
	FILE *fp_FI=NULL;
	
	if(( fp_HT=fopen(FName_HT, "rb") )==NULL)
	{
		printf("打开 %s 失败！\n", FName_HT); 
		system("pause");
		exit(0);
	}
	
	if(( fp_FI=fopen(FName_FI, "wb") )==NULL)
	{
		printf("打开 %s 失败！\n", FName_FI);
		system("pause"); 
		exit(0);
	}
	
	int len=0, tl=0, tsize_t, tsize_f;
	char pBuf_t[BUF_HT_SIZE]; 
	char pBuf_h[BUF_FI_SIZE]; 
	
	fseek(fp_HT,0,SEEK_END); 
	len=ftell(fp_HT);
	rewind(fp_HT); 
	
	while( len>0 )
	{
		tsize_t=BUF_HT_SIZE;
		tsize_f=BUF_FI_SIZE;
		if( len<BUF_HT_SIZE )
		{
			tsize_t=len;
			tsize_f=(tsize_t+1)/3;
				// 应对 hextext 结尾没有空格的情况 
		}
		
		fread(pBuf_t, 1, tsize_t, fp_HT);
		MygetHex(pBuf_t, tsize_t, pBuf_h);
		fwrite(pBuf_h, 1, tsize_f, fp_FI);
		
		len-=tsize_t;
	}
	
	fclose(fp_HT);
	fclose(fp_FI);
}



void MyWritetheFile(char *FName_HT, char *FName_FI);

#endif

