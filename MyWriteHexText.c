
/*
MyWriteHexText
*/


/*
void MyWriteHexText(char *FName_FI, char *FName_HT);
*/


#ifndef _MYWRITEHEXTEXT

#define _MYWRITEHEXTEXT


#include <stdio.h>
#include "MySizeConfig.h"
#include "MyGetName.c"

void MygetText(char *pBuf_h, int len_h, char *pBuf_t)
	// hex -> text
{
	int zh, zt;
	char ch, ct;
	
	zt=0;
	for(zh=0; zh<len_h; zh++)
	{
		// 待考虑负数
		
		ch=(pBuf_h[zh]>>4)&15; 
		ct=ch+((ch<10)?('0'-0):('A'-10));
		pBuf_t[zt++]=ct;
		
		ch=pBuf_h[zh]&15; 
		ct=ch+((ch<10)?('0'-0):('A'-10));
		pBuf_t[zt++]=ct;
		
		pBuf_t[zt++]=' ';
	}
}

void MyWriteHexText(char *FName_FI, char *FName_HT)
{
	FILE *fp_FI=NULL;
	FILE *fp_HT=NULL;
	
	if(( fp_FI=fopen(FName_FI, "rb") )==NULL)
	{
		printf("打开 %s 失败！\n", FName_FI);
		system("pause"); 
		exit(0);
	}
	
	if(( fp_HT=fopen(FName_HT, "wb") )==NULL)
	{
		printf("打开 %s 失败！\n", FName_HT); 
		system("pause");
		exit(0);
	}
	
	int len=0, tl=0, tsize_f, tsize_t;
	char pBuf_h[BUF_FI_SIZE]; 
	char pBuf_t[BUF_HT_SIZE]; 
	
	fseek(fp_FI,0,SEEK_END); 
	len=ftell(fp_FI);
	rewind(fp_FI); 
	
	while( len>0 )
	{
		tsize_f=BUF_FI_SIZE;
		tsize_t=BUF_HT_SIZE;
		if( len<BUF_FI_SIZE )
		{
			tsize_f=len;
			tsize_t=3*tsize_f;
		}
		
		fread(pBuf_h, 1, tsize_f, fp_FI);
		MygetText(pBuf_h, tsize_f, pBuf_t);
		fwrite(pBuf_t, 1, tsize_t, fp_HT);
		
		len-=tsize_f;
	}
	
	fclose(fp_FI);
	fclose(fp_HT);
}



void MyWriteHexText(char *FName_FI, char *FName_HT);

#endif

