
/*
以十六进制读取文件并保存到新文件 
*/
 
#include <stdio.h>
#include <stdlib.h>

#define NAME_MAX_SIZE (1024)
#define BUF_R_SIZE (64)
#define BUF_W_SIZE (192) // 3*BUF_R_SIZE
#define MyWriteFileAddfront "Hex_"
#define MyWriteFileAddrear ".txt"
char MyWFAddf[]=MyWriteFileAddfront;
char MyWFAddr[]=MyWriteFileAddrear;


int MystrFind(char *str, char ch, int no)
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
	// addstr 的 s到e(含e) 添加到 str 的 以top为首 的位置
	// e -1时 为 addstr 的 s到'\0' 
{
	if(e==-1)e--;
	while( s!=e+1 && addstr[s]!='\0' ) 
		str[top++]=addstr[s++];
	str[top]='\0'; // 结尾 
	return top;
}

void _Mystradd(char *str1, int *ptop, char *str2, int s, int e)
{
	int temp;
	temp=Mystradd(str1, *ptop, str2, s, e);
	*ptop=temp;
}


// 待考虑 FName_r 为 相对路径 
int MyGetWriteName(char *FName_r, char *FName_w)
{
	int z1=-1, z2=-1, zr=0, zw=0;
	
	z1=MystrFind(FName_r, '\\', -1);
	//z2=MystrFind(FName_r, '.', -1);
	
	// path  '\\'  前缀  文件名  ('.')拓展名 
	zw=0;
	if(z1!=-1)zw=Mystradd(FName_w, zw, FName_r, 0, z1); // add path
	zw=Mystradd(FName_w, zw, MyWFAddf, 0, -1); // add 前缀 
	zw=Mystradd(FName_w, zw, FName_r, z1+1, -1); // add 文件名 
	zw=Mystradd(FName_w, zw, MyWFAddr, 0, -1); // add 拓展名 
}

void MyGetReadName(char *FName_r, char *FName_w)
{
	int z1=-1, z2=-1, zr=0, zw=0;
	
	z1=MystrFind(FName_r, '\\', -1);
	z2=MystrFind(FName_r, '.', -1);
	
	for(zr=0; zr<=z1; zr++)
		FName_w[zw++]=FName_r[zr];
	
}



void MyWriteHexText(char *pBuf_r, int len_r, char *pBuf_w)
{
	int zr, zw;
	char cr, cw;
	
	zw=0;
	for(zr=0; zr<len_r; zr++)
	{
		// 待考虑负数
		
		cr=(pBuf_r[zr]>>4)&15; 
		cw=cr+((cr<10)?('0'-0):('A'-10));
		pBuf_w[zw++]=cw;
		
		cr=pBuf_r[zr]&15; 
		cw=cr+((cr<10)?('0'-0):('A'-10));
		pBuf_w[zw++]=cw;
		
		pBuf_w[zw++]=' ';
	}
}

void MyReadHexFile(char *FName_r, char *FName_w)
{
	FILE *fp_r=NULL;
	FILE *fp_w=NULL;
	
	if(( fp_r=fopen(FName_r, "rb") )==NULL)
	{
		printf("打开 %s 失败！\n", FName_r);
		system("pause"); 
		exit(0);
	}
	
	if(( fp_w=fopen(FName_w, "wb") )==NULL)
	{
		printf("打开 %s 失败！\n", FName_w); 
		system("pause");
		exit(0);
	}
	
	int len=0, tl=0, tsize_r, tsize_w;
	char pBuf_r[BUF_R_SIZE]; 
	char pBuf_w[BUF_W_SIZE]; 
	
	fseek(fp_r,0,SEEK_END); 
	len=ftell(fp_r);
	rewind(fp_r); 
	
	while( len>0 )
	{
		tsize_r=BUF_R_SIZE;
		tsize_w=BUF_W_SIZE;
		if( len<BUF_R_SIZE )
		{
			tsize_r=len;
			tsize_w=3*tsize_r;
		}
		
		fread(pBuf_r, 1, tsize_r, fp_r);
		MyWriteHexText(pBuf_r, tsize_r, pBuf_w);
		fwrite(pBuf_w, 1, tsize_w, fp_w);
		
		len-=tsize_r;
	}
	
	fclose(fp_r);
	fclose(fp_w);
}



int MyCheckName(char *FName)
// 根据 文件推展名 判断 需要的行为 
// \\Hex_xxx.txt :	需要还原 : 返回 1 
// 			否则 	需要处理 : 返回 0
{
	int z1=-1, z2=-1;
	
	z1=MystrFind(FName, '\\', -1);
	if( z1==-1 )z1=0;
	z2=MystrFind(FName, '.', -1);
	if( z2==-1 )return 0; // 不是需要还原的文件名 
	
	if( Mystrcmp( MyWFAddf, FName+z1+1)==0 )return 0;
	if( Mystrcmp( MyWFAddr, FName+z2)==0 )return 0;
	return 1;
}


#define TestMod 0
	// 0 ：拖入文件模式 
	// 1 : 输入文件名模式 
	 

// 待支持处理多个
int main(int argc, char *argv[])
{
	
if( TestMod )
{	
	char FName_r[NAME_MAX_SIZE]="D:\\2.txt";
	char FName_w[NAME_MAX_SIZE];
	
	if( MyCheckName(FName_r)==0 ) // 需要 写 HexText ...
	{
		MyGetWriteName(FName_r, FName_w);
		printf("From File : %s\n", FName_r);
		MyReadHexFile(FName_r, FName_w);
		printf("To Text : %s\n", FName_w);
		printf("完成!\n");
	}
	else // 需要 写 File ... // 未完成 
	{
		MyGetReadName(FName_r, FName_w); // 不是 readname 
		printf("From Text : %s\n", FName_r);
		MyReadHexFile(FName_r, FName_w);
		printf("To File : %s\n", FName_w);
		printf("完成!\n");	
	}
	
	return 0;
}
	
	
	
	if(argc<=1)
	{
		printf("无文件!\n"); 
		system("pause");
		return 0;
	}
		
	char FName_r[NAME_MAX_SIZE];
	char FName_w[NAME_MAX_SIZE];
	Mystradd(FName_r, 0, argv[1], 0, -1);
	
	if( MyCheckName(FName_r)==0 ) // 需要 写 HexText ...
	{
		MyGetWriteName(FName_r, FName_w);
		printf("From File : %s\n", FName_r);
		MyReadHexFile(FName_r, FName_w);
		printf("To Text : %s\n", FName_w);
		printf("完成!\n");
	}
	else // 需要 写 File ... // 未完成 
	{
		Mystradd(FName_r, 0, argv[1], 0, -1);
		MyGetReadName(FName_r, FName_w);
		
		//printf("From Text : %s\n", FName_r);
		printf("From Text : %s\n", FName_r);
		MyReadHexFile(FName_r, FName_w);
		printf("To File : %s\n", FName_w);
		printf("完成!\n");	
	}
	
	system("pause");
	return 0;
}
