
/*
以十六进制读取文件并保存到新文件 
*/

// HexText <--> File

#include <stdio.h>
#include <stdlib.h>


#include "MySizeConfig.h"
#include "MyNameAddConfig.h"
#include "MyStrDeal.c"
#include "MyGetName.c"
#include "MyWriteHexText.c"
//#include "MyWrite... .c"


int MyCheckName(char *FName)
// 根据 文件推展名 判断 需要的行为 
// "\\Hex_xxx.txt"  需要还原 : 返回 1 
// 			否则 	需要处理 : 返回 0
{
	int z1=-1, z2=-1;
	
	z1=MystrFind(FName, '\\', -1);
	if( z1==-1 )z1=0;
	z2=MystrFind(FName, '.', -1);
	if( z2==-1 )return 0; // 不是需要还原的文件名 
	
	if( Mystrcmp( MyHT_front, FName+z1+1)==0 )return 0;
	if( Mystrcmp( MyHT_rear, FName+z2)==0 )return 0;
	return 1;
}




int MyDealaFile(int argc, char *argv[], int mod)
{
	char FName_r[NAME_MAX_SIZE]="D:\\2.txt";
	char FName_w[NAME_MAX_SIZE]="D:\\3.txt";
	if( mod==0 )
	{
		if(argc<=1)
		{
			printf("无文件!\n"); 
			system("pause");
			return 0;
		}
		Mystradd(FName_r, 0, argv[1], 0, -1);
	}
	
	if( MyCheckName(FName_r)==0 ) // 需要 写 HexText ...
	{
		MyGetHexTextName(FName_r, FName_w);
		printf("From File : %s\n", FName_r);
		MyWriteHexText(FName_r, FName_w);
		printf("To Text : %s\n", FName_w);
		printf("完成!\n");
	}
	else // 需要 写 File ... // 未完成 
	{
		//MyGetReadName(FName_r, FName_w); // 不是 readname 
		printf("From Text : %s\n", FName_r);
		//MyReadHexFile(FName_r, FName_w);
		printf("To File : %s\n", FName_w);
		printf("完成!\n");	
	}
	
	system("pause");
	return 0;
}



#define TestMod 1
	// 0 ：拖入文件模式 
	// 1 : 输入文件名模式 
	 

// 待支持处理多个
int main(int argc, char *argv[])
{
	return MyDealaFile(argc, argv, TestMod);
	
}

