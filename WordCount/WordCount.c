#include <stdio.h>
#include <string.h>
int *getCharNum(char *filename, int *totalNum);//�ļ���:filename,  �ļ�ͳ������:totalNum

int main()
{
	char filename[30];
	//totalNum[1]Ϊ���ַ���  totalNum[2]Ϊ�ܵ����� 
	int totalNum[3] = {0,0,0};
	scanf("%s", filename);
	if(getCharNum(filename,totalNum))
	{
		printf("�ַ���Ϊ: %d, ������Ϊ��%d \n", totalNum[1], totalNum[2]);
	}
	else
	{printf("Error!\n");}
	return 0;
}

//ͳ��
int *getCharNum(char *filename, int *totalNum)
{
	FILE *fp; // ָ���ļ���ָ�� 
    char buffer[1003]; // ���������洢��ȡ����ÿ�е�����
	int bufferLen;  // ��������ʵ�ʴ洢�����ݵĳ���
	int i;  // ��ǰ�����������ĵ�i���ַ�
	char c;  // ��ȡ�����ַ�
	int isLastBlank = 0; // �ϸ��ַ��Ƿ��ǿո� 
	int charNum = 0;  // ��ǰ�е��ַ��� 
	int wordNum = 0; // ��ǰ�еĵ����� 
	if ( (fp=fopen(filename, "rb")) == NULL )
	{
		perror(filename);
		return NULL;
	}
	//ÿ�ζ�ȡһ�����ݣ����浽buffer
	while (fgets(buffer,1003,fp) != NULL)
	{
		bufferLen = strlen(buffer);
		//��������������
		for(i=0; i<bufferLen; i++)
		{
			c = buffer[i];
			if(c == ' '||c == ',')//�����ո�򶺺�
			{
				!isLastBlank && wordNum++;//����ϸ��ַ����ǿո�򶺺ţ�������+1
				isLastBlank = 1;
			}
			else 
			{
				charNum++;
				isLastBlank = 0;
			}
				
		}
		!isLastBlank && wordNum++; //������һ���ַ����ǿո���ô������+1��
		isLastBlank = 1; //ÿ�λ�������Ϊ1
		totalNum[0]++;
		totalNum[1] += charNum;
		totalNum[2] += wordNum;
		charNum = 0;
		wordNum = 0;
	}
	return totalNum;
}