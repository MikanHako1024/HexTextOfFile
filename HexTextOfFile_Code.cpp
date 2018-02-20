
/*
以十六进制读取文件并保存到文本
在文本修改十六进制数据并形成文件 
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
	// 0 ：拖入文件模式 
	// 1 : 输入文件名模式 

//#define InputFName "D:\\2.txt" 
#define InputFName "D:\\Hex_2.txt.txt"
char FName[]=InputFName;


int main(int argc, char *argv[])
{
	int z;
	
	if( TestMod==0 )
	{
		if(argc<=1)
		{
			printf("无文件!\n"); 
			system("pause");
			return 0;
		}
		
		for(z=1; z<argc; z++)
			MyDealaFile(argv[z]);
	}
	else 
	{
		MyDealaFile(FName);
	}
	
	system("pause");
	return 0;
}


/*
#define NAME_MAX_SIZE (1024)
#define BUF_FI_SIZE (64)
#define BUF_HT_SIZE (192) // 3*BUF_FI_SIZE
 
#define MyHexText_front "Hex_"
#define MyHexText_rear ".txt"
#define MytheFile_front "new_" 
char MyHT_front[]=MyHexText_front;
char MyHT_rear[]=MyHexText_rear;
char MyFI_front[]=MytheFile_front;

int MystrFind(char *str, char ch, int no);
int Mystrcmp(char *str1, char *str2);
int Mystradd(char *str, int top, char *addstr, int s, int e);

void MyGetHexTextName(char *FName_FI, char *FName_HT);
void MyGettheFileName(char *FName_HT, char *FName_FI);

void MyWriteHexText(char *FName_FI, char *FName_HT);

void MyWritetheFile(char *FName_HT, char *FName_FI);

int MyDealaFile(int argc, char *argv[], int m, int mod);
*/


