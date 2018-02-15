
/*
��ʮ�����ƶ�ȡ�ļ������浽���ļ� 
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
	// addstr �� s��e(��e) ��ӵ� str �� ��topΪ�� ��λ��
	// e -1ʱ Ϊ addstr �� s��'\0' 
{
	if(e==-1)e--;
	while( s!=e+1 && addstr[s]!='\0' ) 
		str[top++]=addstr[s++];
	str[top]='\0'; // ��β 
	return top;
}

void _Mystradd(char *str1, int *ptop, char *str2, int s, int e)
{
	int temp;
	temp=Mystradd(str1, *ptop, str2, s, e);
	*ptop=temp;
}


// ������ FName_r Ϊ ���·�� 
int MyGetWriteName(char *FName_r, char *FName_w)
{
	int z1=-1, z2=-1, zr=0, zw=0;
	
	z1=MystrFind(FName_r, '\\', -1);
	//z2=MystrFind(FName_r, '.', -1);
	
	// path  '\\'  ǰ׺  �ļ���  ('.')��չ�� 
	zw=0;
	if(z1!=-1)zw=Mystradd(FName_w, zw, FName_r, 0, z1); // add path
	zw=Mystradd(FName_w, zw, MyWFAddf, 0, -1); // add ǰ׺ 
	zw=Mystradd(FName_w, zw, FName_r, z1+1, -1); // add �ļ��� 
	zw=Mystradd(FName_w, zw, MyWFAddr, 0, -1); // add ��չ�� 
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
		// �����Ǹ���
		
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
		printf("�� %s ʧ�ܣ�\n", FName_r);
		system("pause"); 
		exit(0);
	}
	
	if(( fp_w=fopen(FName_w, "wb") )==NULL)
	{
		printf("�� %s ʧ�ܣ�\n", FName_w); 
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
// ���� �ļ���չ�� �ж� ��Ҫ����Ϊ 
// \\Hex_xxx.txt :	��Ҫ��ԭ : ���� 1 
// 			���� 	��Ҫ���� : ���� 0
{
	int z1=-1, z2=-1;
	
	z1=MystrFind(FName, '\\', -1);
	if( z1==-1 )z1=0;
	z2=MystrFind(FName, '.', -1);
	if( z2==-1 )return 0; // ������Ҫ��ԭ���ļ��� 
	
	if( Mystrcmp( MyWFAddf, FName+z1+1)==0 )return 0;
	if( Mystrcmp( MyWFAddr, FName+z2)==0 )return 0;
	return 1;
}


#define TestMod 0
	// 0 �������ļ�ģʽ 
	// 1 : �����ļ���ģʽ 
	 

// ��֧�ִ�����
int main(int argc, char *argv[])
{
	
if( TestMod )
{	
	char FName_r[NAME_MAX_SIZE]="D:\\2.txt";
	char FName_w[NAME_MAX_SIZE];
	
	if( MyCheckName(FName_r)==0 ) // ��Ҫ д HexText ...
	{
		MyGetWriteName(FName_r, FName_w);
		printf("From File : %s\n", FName_r);
		MyReadHexFile(FName_r, FName_w);
		printf("To Text : %s\n", FName_w);
		printf("���!\n");
	}
	else // ��Ҫ д File ... // δ��� 
	{
		MyGetReadName(FName_r, FName_w); // ���� readname 
		printf("From Text : %s\n", FName_r);
		MyReadHexFile(FName_r, FName_w);
		printf("To File : %s\n", FName_w);
		printf("���!\n");	
	}
	
	return 0;
}
	
	
	
	if(argc<=1)
	{
		printf("���ļ�!\n"); 
		system("pause");
		return 0;
	}
		
	char FName_r[NAME_MAX_SIZE];
	char FName_w[NAME_MAX_SIZE];
	Mystradd(FName_r, 0, argv[1], 0, -1);
	
	if( MyCheckName(FName_r)==0 ) // ��Ҫ д HexText ...
	{
		MyGetWriteName(FName_r, FName_w);
		printf("From File : %s\n", FName_r);
		MyReadHexFile(FName_r, FName_w);
		printf("To Text : %s\n", FName_w);
		printf("���!\n");
	}
	else // ��Ҫ д File ... // δ��� 
	{
		Mystradd(FName_r, 0, argv[1], 0, -1);
		MyGetReadName(FName_r, FName_w);
		
		//printf("From Text : %s\n", FName_r);
		printf("From Text : %s\n", FName_r);
		MyReadHexFile(FName_r, FName_w);
		printf("To File : %s\n", FName_w);
		printf("���!\n");	
	}
	
	system("pause");
	return 0;
}
