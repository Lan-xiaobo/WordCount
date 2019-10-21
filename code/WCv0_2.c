/*
WordCount v0.2
Lan-xiaobo
2019.10.20
*/

#include<stdio.h>
#include<string.h>
#include<assert.h>

void CodeCount(FILE *file) //计算字符个数
{	
	int c_num = 0;
	char c;
	
	while(!feof(file))// 检查是否到文件的结束位置
	{
	 c=fgetc(file);
	 if(c!=' ' && c!= '\n' && c!='\t')//判断是否为字符
	 	c_num++; 
	}
	fclose(file);
	printf("字符数: %d",c_num);
	
}

void WordCount(FILE *file) 	//计算单词个数
{
	char c;
	int word_flag = 0;	//用于记录字符是否处于单词中
	int w_num = 0;
	
	while (!feof(file)) 
	{
	 c=fgetc(file);
	 if((c>='a' &&c <= 'z')||(c>= 'A'&&c<='Z') || c=='_')
		word_flag=1;//如果一直是字符那word_flag值为1
	 else if(word_flag)//检测到不是字符，转入这个循环，进行单词数目的加加
		{
		 w_num++;
	 	 word_flag=0;
		}
	} 
	fclose(file);
	printf("单词数: %d",w_num);
	
}

void LineCount(FILE *file) 	//计算行数
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
	printf("行数: %d",l_num);
		
}

int main(int argc, char* argv[]) 
{
	FILE *file = fopen(argv[2], "r");//以只读的方式读取文件
	assert(file != NULL);	//若文件不存在则报错
	
	switch (argv[1][1]) 
	{
	 case 'c': CodeCount(file); break;
	 case 'w': WordCount(file); break;
	 case 'l': LineCount(file); break;
	 default: printf("Type input error"); break;
	}
	printf("\n");

}


