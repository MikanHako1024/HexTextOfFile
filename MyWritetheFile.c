
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

void MygetText(char *pBuf_t, int len_t, char *pBuf_h)
	// text -> hex
{
	int zt, zh;
	char ct, ch;
	
	zh=0;
	for(zt=0; zt<len_t; zt++)
	{
		ct=pBuf_t[zt++];
		if('0'<=ct && ct<='9')ch=ct-'0'+0;
		else if('A'<=ch && ch<='Z')ch=ct-'A'+10;
		else ch=ct-'a'+10;
			// ¿¼ÂÇµ½Ð¡Ð´×ÖÄ¸ 
		pBuf_h[zh]=ch;
		
		ct=pBuf_t[zt++];
		if('0'<=ct && ct<='9')ch=ct-'0'+0;
		else if('A'<=ch && ch<='Z')ch=ct-'A'+10;
		else ch=ct-'a'+10;
		pBuf_h[zh]<<=4;
		pBuf_h[zh]|=ch;
		
		zh++;
	}
}


// ´ý ·ÀÖ¹¸²¸ÇÔ­ÎÄ¼þ 
void MyWritetheFile(char *FName_HT, char *FName_FI)
	// text -> file
{
	FILE *fp_HT=NULL;
	FILE *fp_FI=NULL;
	
	if(( fp_HT=fopen(FName_HT, "rb") )==NULL)
	{
		printf("´ò¿ª %s Ê§°Ü£¡\n", FName_HT); 
		system("pause");
		exit(0);
	}
	
	if(( fp_FI=fopen(FName_FI, "wb") )==NULL)
	{
		printf("´ò¿ª %s Ê§°Ü£¡\n", FName_FI);
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
			tsize_f=len;
			tsize_t=3*tsize_f;
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

