
/*
MyNameAddConfig
*/


/*
添加的前缀后缀 
Hex_xxx.txt 
new_xxx
*/


#ifndef _MYNAMEADDCONFIG

#define _MYNAMEADDCONFIG


#define MyHexText_front "Hex_" 	// abc_ 
#define MyHexText_rear ".txt"
#define MytheFile_front "new_" // ？或 用 time_
	// 防止覆盖已有文件 

char MyHT_front[]=MyHexText_front;
char MyHT_rear[]=MyHexText_rear;
char MyFI_front[]=MytheFile_front;

#endif

