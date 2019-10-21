/*
WordCount v0.2
Lan-xiaobo
2019.10.20
*/

#include<stdio.h>
#include<string.h>
#include<assert.h>

void CodeCount(FILE *file) //�����ַ�����
{	
	int c_num = 0;
	char c;
	
	while(!feof(file))// ����Ƿ��ļ��Ľ���λ��
	{
	 c=fgetc(file);
	 if(c!=' ' && c!= '\n' && c!='\t')//�ж��Ƿ�Ϊ�ַ�
	 	c_num++; 
	}
	fclose(file);
	printf("�ַ���: %d",c_num);
	
}

void WordCount(FILE *file) 	//���㵥�ʸ���
{
	char c;
	int word_flag = 0;	//���ڼ�¼�ַ��Ƿ��ڵ�����
	int w_num = 0;
	
	while (!feof(file)) 
	{
	 c=fgetc(file);
	 if((c>='a' &&c <= 'z')||(c>= 'A'&&c<='Z') || c=='_')
		word_flag=1;//���һֱ���ַ���word_flagֵΪ1
	 else if(word_flag)//��⵽�����ַ���ת�����ѭ�������е�����Ŀ�ļӼ�
		{
		 w_num++;
	 	 word_flag=0;
		}
	} 
	fclose(file);
	printf("������: %d",w_num);
	
}

void LineCount(FILE *file) 	//��������
{
	char c;
	int l_num=1;
	
	while(!feof(file))
	{
	c=fgetc(file);
	if(c=='\n' || c=='\t')
		l_num++;
	}
	fclose(file);
	printf("����: %d",l_num);
		
}

int main(int argc, char* argv[]) 
{
	FILE *file = fopen(argv[2], "r");//��ֻ���ķ�ʽ��ȡ�ļ�
	assert(file != NULL);	//���ļ��������򱨴�
	
	switch (argv[1][1]) 
	{
	 case 'c': CodeCount(file); break;
	 case 'w': WordCount(file); break;
	 case 'l': LineCount(file); break;
	 default: printf("Type input error"); break;
	}
	printf("\n");

}


