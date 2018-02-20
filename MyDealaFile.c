
/*
MyDealaFile
*/


/*
void MyDealaFile(char *FName);
*/


#ifndef _MYDEALAGILE

#define _MYDEALAGILE


#include <stdio.h>
#include <stdlib.h>

#include "MySizeConfig.h"
#include "MyNameAddConfig.h"
#include "MyStrDeal.c"
#include "MyGetName.c"
#include "MyWriteHexText.c"
#include "MyWritetheFile.c"

int MyCheckName(char *FName)
// ���� �ļ���չ�� �ж� ��Ҫ����Ϊ 
// "\\Hex_xxx.txt"  ��Ҫ��ԭ : ���� 1 
// 			���� 	��Ҫ���� : ���� 0
{
	int z1=-1, z2=-1;
	
	z1=MystrFind(FName, '\\', -1);
	if( z1==-1 )z1=0;
	z2=MystrFind(FName, '.', -1);
	if( z2==-1 )return 0; // ������Ҫ��ԭ���ļ��� 
	
	if( Mystrcmp( MyHT_front, FName+z1+1)==0 )return 0;
	if( Mystrcmp( MyHT_rear, FName+z2)==0 )return 0;
	return 1;
}

void MyDealaFile(char *FName)
{
	char FName_r[NAME_MAX_SIZE];
	char FName_w[NAME_MAX_SIZE];
	Mystradd(FName_r, 0, FName, 0, -1);
	
	if( MyCheckName(FName_r)==0 ) // ��Ҫ д HexText 
	{
		MyGetHexTextName(FName_r, FName_w);
		printf("From File : %s\n", FName_r);
		MyWriteHexText(FName_r, FName_w);
		printf("To Text : %s\n", FName_w);
		printf("���!\n");
	}
	else // ��Ҫ д theFile 
	{
		MyGettheFileName(FName_r, FName_w); 
		printf("From Text : %s\n", FName_r);
		MyWritetheFile(FName_r, FName_w);
		printf("To File : %s\n", FName_w);
		printf("���!\n");	
	}
}



void MyDealaFile(char *FName);

#endif

