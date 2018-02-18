
/*
MyGetName
*/


/*
void MyGetHexTextName(char *FName_FI, char *FName_HT);
void MyGettheFileName(char *FName_HT, char *FName_FI);
*/


#ifndef _MYGETNAME

#define _MYGETNAME


#include "MyNameAddConfig.h"
#include "MyStrDeal.c"

void MyGetHexTextName(char *FName_FI, char *FName_HT)
{
	int z1=-1, z2=-1, zf=0, zh=0;
	
	z1=MystrFind(FName_FI, '\\', -1);
	//z2=MystrFind(FName_FI, '.', -1);
	
	// path  '\\'  前缀  文件名  ('.')拓展名 
	zh=0;
	if(z1!=-1) // 文件在 相对路径的根目录 时 路径没有 '\\' 
		zh=Mystradd(FName_HT, zh, FName_FI, 0, z1); // add path
	zh=Mystradd(FName_HT, zh, MyHT_front, 0, -1); // add 前缀 
	zh=Mystradd(FName_HT, zh, FName_FI, z1+1, -1); // add 文件名 
	zh=Mystradd(FName_HT, zh, MyHT_rear, 0, -1); // add 拓展名 
}

void MyGettheFileName(char *FName_HT, char *FName_FI)
{
	int z1=-1, z2=-1, zh=0, zf=0;
	
	z1=MystrFind(FName_HT, '\\', -1);
	z2=MystrFind(FName_HT, '.', -1);
	 
	Mystradd(FName_FI, 0, FName_HT, 0, -1); // add path 
	zf=z1+1;
	z1=z1+MystrFind(FName_HT+z1, '_', 1); 
	zf=Mystradd(FName_FI, zf, FName_HT, z1+1, z2-1); // add 文件名 
}



void MyGetHexTextName(char *FName_FI, char *FName_HT);
void MyGettheFileName(char *FName_HT, char *FName_FI);

#endif

