#include <stdio.h>
#include <string.h>
int *getCharNum(char *filename, int *totalNum);//文件名:filename,  文件统计数据:totalNum

int main()
{
	char filename[30];
	//totalNum[1]为总字符数  totalNum[2]为总单词数 
	int totalNum[3] = {0,0,0};
	scanf("%s", filename);
	if(getCharNum(filename,totalNum))
	{
		printf("字符数为: %d, 单词数为：%d \n", totalNum[1], totalNum[2]);
	}
	else
	{printf("Error!\n");}
	return 0;
}

//统计
int *getCharNum(char *filename, int *totalNum)
{
	FILE *fp; // 指向文件的指针 
    char buffer[1003]; // 缓冲区，存储读取到的每行的内容
	int bufferLen;  // 缓冲区中实际存储的内容的长度
	int i;  // 当前读到缓冲区的第i个字符
	char c;  // 读取到的字符
	int isLastBlank = 0; // 上个字符是否是空格 
	int charNum = 0;  // 当前行的字符数 
	int wordNum = 0; // 当前行的单词数 
	if ( (fp=fopen(filename, "rb")) == NULL )
	{
		perror(filename);
		return NULL;
	}
	//每次读取一行数据，保存到buffer
	while (fgets(buffer,1003,fp) != NULL)
	{
		bufferLen = strlen(buffer);
		//遍历缓冲区内容
		for(i=0; i<bufferLen; i++)
		{
			c = buffer[i];
			if(c == ' '||c == ',')//遇到空格或逗号
			{
				!isLastBlank && wordNum++;//如果上个字符不是空格或逗号，单词数+1
				isLastBlank = 1;
			}
			else 
			{
				charNum++;
				isLastBlank = 0;
			}
				
		}
		!isLastBlank && wordNum++; //如果最后一个字符不是空格，那么单词数+1、
		isLastBlank = 1; //每次换行重置为1
		totalNum[0]++;
		totalNum[1] += charNum;
		totalNum[2] += wordNum;
		charNum = 0;
		wordNum = 0;
	}
	return totalNum;
}