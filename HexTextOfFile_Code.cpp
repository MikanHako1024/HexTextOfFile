
/*
��ʮ�����ƶ�ȡ�ļ������浽�ı�
���ı��޸�ʮ���������ݲ��γ��ļ� 
*/


// HexText <--> File


#include <stdio.h>
#include <stdlib.h>

#include "MySizeConfig.h"
#include "MyNameAddConfig.h"
#include "MyStrDeal.c"
#include "MyGetName.c"
#include "MyWriteHexText.c"
#include "MyWritetheFile.c"
#include "MyDealaFile.c"


#define TestMod 0
	// 0 �������ļ�ģʽ 
	// 1 : �����ļ���ģʽ 
	 

// ��֧�ִ�����
int main(int argc, char *argv[])
{
	//printf("%d\n", argc); 
		// ���� 1���ļ� Ϊ2
		// ���� 3���ļ� Ϊ4 
	int z;
	for(z=1; z<argc; z++)
		MyDealaFile(argc, argv, z, TestMod);
	
	return 0;
}


/*
#define NAME_MAX_SIZE (1024)
#define BUF_FI_SIZE (64)
#define BUF_HT_SIZE (192) // 3*BUF_FI_SIZE
 
#define MyHexText_front "Hex_" 	// abc_ 
#define MyHexText_rear ".txt"
char MyHT_front[]=MyHexText_front;
char MyHT_rear[]=MyHexText_rear;

int MystrFind(char *str, char ch, int no);
int Mystrcmp(char *str1, char *str2);
int Mystradd(char *str, int top, char *addstr, int s, int e);

void MyGetHexTextName(char *FName_FI, char *FName_HT);
void MyGettheFileName(char *FName_HT, char *FName_FI);

void MyWriteHexText(char *FName_FI, char *FName_HT);

void MyWritetheFile(char *FName_HT, char *FName_FI);

int MyDealaFile(int argc, char *argv[], int m, int mod);
*/


