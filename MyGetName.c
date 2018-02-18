
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
	
	// path  '\\'  ǰ׺  �ļ���  ('.')��չ�� 
	zh=0;
	if(z1!=-1) // �ļ��� ���·���ĸ�Ŀ¼ ʱ ·��û�� '\\' 
		zh=Mystradd(FName_HT, zh, FName_FI, 0, z1); // add path
	zh=Mystradd(FName_HT, zh, MyHT_front, 0, -1); // add ǰ׺ 
	zh=Mystradd(FName_HT, zh, FName_FI, z1+1, -1); // add �ļ��� 
	zh=Mystradd(FName_HT, zh, MyHT_rear, 0, -1); // add ��չ�� 
}

void MyGettheFileName(char *FName_HT, char *FName_FI)
{
	int z1=-1, z2=-1, zh=0, zf=0;
	
	z1=MystrFind(FName_HT, '\\', -1);
	z2=MystrFind(FName_HT, '.', -1);
	 
	Mystradd(FName_FI, 0, FName_HT, 0, -1); // add path 
	zf=z1+1;
	z1=z1+MystrFind(FName_HT+z1, '_', 1); 
	zf=Mystradd(FName_FI, zf, FName_HT, z1+1, z2-1); // add �ļ��� 
}



void MyGetHexTextName(char *FName_FI, char *FName_HT);
void MyGettheFileName(char *FName_HT, char *FName_FI);

#endif

