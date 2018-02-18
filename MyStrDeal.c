
/*
MyStrDeal
*/


/*
int MystrFind(char *str, char ch, int no);
int Mystrcmp(char *str1, char *str2);
int Mystradd(char *str, int top, char *addstr, int s, int e);
*/


#ifndef _MYSTRDEAL

#define _MYSTRDEAL

int MystrFind(char *str, char ch, int no)
	// �ҵ� str �� ��no�� ch�ַ� ���±� 
	// no<=0 ʱ �ҵ����һ�� ch�ַ� ���±�
	// ���ҵ� �����±�  ��δ�ҵ� �򷵻� -1 
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
	// �ַ����Ƚ�
	// �����ַ�����ͬ ���� 1  ���� ���� -1 
	// �� һ���ȵ� '\0' ʱ �����ж� ֮ǰ������ͬ �򷵻� 1 �� 
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
	// �� addstr �� s��e(��e) ��ӵ� str �� ��topΪ�� ��λ��
	// e -1ʱ Ϊ addstr �� s��'\0' 
	// ���ؽ�β�±� 
{
	if(e==-1)e--;
	while( s!=e+1 && addstr[s]!='\0' ) 
		str[top++]=addstr[s++];
	str[top]='\0'; // ��β 
	return top;
}

void _Mystradd(char *str1, int *ptop, char *str2, int s, int e)\
	// ?
{
	int temp;
	temp=Mystradd(str1, *ptop, str2, s, e);
	*ptop=temp;
}



int MystrFind(char *str, char ch, int no);
int Mystrcmp(char *str1, char *str2);
int Mystradd(char *str, int top, char *addstr, int s, int e);

#endif

