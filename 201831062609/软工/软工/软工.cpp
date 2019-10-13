#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
//#include<pch.h>
using namespace std;
int charcount()//字符的统计
{
	FILE *x;
	int n = 0;
	char ch;
	if ((x = fopen("测试数据.txt", "r")) == NULL)
	{
		printf("读取文件失败");
	}
	ch = fgetc(x);
	while (ch != EOF) {
		n++;
		ch = ch = fgetc(x);
	}
	cout << "字符总数是" << n << endl;
	return n;//所有return都是为了在输文件的时候进行调用相应的值
	fclose(x);
}
int  linecount()//行数的统计
{
	FILE *x;//统一在所有函数中出现的文件都用x
	int n = 1;//所有出现的次数都用n表示
	char ch;
	if ((x = fopen("测试数据.txt", "r")) == NULL)
	{
		printf("读取文件失败");
	}
	ch = fgetc(x);
	while (ch != EOF)
	{
		if (ch == '\n')
		{
			n++;
			ch = fgetc(x);
		}
		else
		{
			ch = fgetc(x);
		}
	}
	cout << "行数为" << n << endl;
	return n;
	fclose(x);
}
int wordcount()//字母数字和符号的统计
{
	FILE *x;
	int n = 0;
	char ch;
	if ((x = fopen("测试数据.txt", "r")) == NULL)
	{
		printf("读取失败");
	}
	ch = fgetc(x);
	while (ch != EOF)
	{
		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&&ch <= '9'))//采用的Ascii码进行相应的判断
		{
			while ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&&ch <= '9') || ch == '_')
			{
				ch = fgetc(x);
			}
			n++;
			ch = fgetc(x);
		}
		else
		{
			ch = fgetc(x);
		}
	}
	cout << "字母数字和符号数目是" << n << endl;
	return n;
	fclose(x);
}
int  Ewordcount()//英文字母的统计
{
	FILE *x;
	int n = 0;
	char ch;
	if ((x = fopen("测试数据.txt", "r")) == NULL)
	{
		printf("读取失败");
	}
	ch = fgetc(x);
	while (ch != EOF)//EOF的意思是文件结束即end of file的简写
	{
		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))//同样采用的Ascii码进行相应的判断和上一个相比只是把数字去掉了，所以这里也只是去掉了相应的ASCII码
		{
			while ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))
			{
				ch = fgetc(x);
			}
			n++;
			ch = fgetc(x);
		}
		else
		{
			ch = fgetc(x);
		}
	}
	cout << "英文字母数目是" << n << endl;
	return n;
	fclose(x);
}
int main(int argc, char *argv[])
{
	if ((strcmp(argv[1], "测试数据.txt") == 0))//输入叫做测试数据的txt文档
	{
		charcount();
		linecount();
		wordcount();
		Ewordcount();
	}
	int a, b, c, d;
	ofstream outfile;
	a = charcount();//前面函数中return的值再这里进行调用
	b = linecount();
	c = wordcount();
	d = Ewordcount();
	outfile.open("Result.txt");//将得到的结果输出到一个叫做Result的txt文档中
	outfile << "字符总数是" << a << endl << "行数为" << b << endl << "字母数字和符号数目是" << c << endl << "英文字母数目是" << d << endl;
	return 0;
}
