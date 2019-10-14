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
	return n;
	fclose(x);
}
int charcount1()//字符的统计
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
	
	return n;
	fclose(x);
}
int  linecount()//行数的统计
{
	FILE *x;
	int n = 1;
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
}
int  linecount1()//行数的统计
{
	FILE *x;
	int n = 1;
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

	return n;
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
}int wordcount1()//字母数字和符号的统计
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

	return n;
	fclose(x);
}
int  Wwordcount()//英文字母的统计
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
}int  Wwordcount1()//英文字母的统计
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
	
	return n;
	fclose(x);
}
int main(int argc, char *argv[])
{
	if ((strcmp(argv[1], "测试数据.txt") == 0))
	{
		charcount();
		linecount();
		wordcount();
		Wwordcount();
	}
	int a, b, c, d;
	ofstream outfile;
	a = charcount1();
	b = linecount1();
	c = wordcount1();
	d = Wwordcount1();
	outfile.open("Result.txt");
	outfile << "字符总数是" << a << endl << "行数为" << b << endl << "字母数字和符号数目是" << c << endl << "英文字母数目是" << d << endl;
	return 0;
}
