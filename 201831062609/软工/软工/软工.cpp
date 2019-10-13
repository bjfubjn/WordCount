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

int main(int argc, char *argv[])
{
	if ((strcmp(argv[1], "测试数据.txt") == 0))//输入叫做测试数据的txt文档
	{
		charcount();
		linecount();
		
	}
	int a, b, c, d;
	ofstream outfile;
	a = charcount();//前面函数中return的值再这里进行调用
	b = linecount();
	
	outfile.open("Result.txt");//将得到的结果输出到一个叫做Result的txt文档中
	outfile << "字符总数是" << a << endl << "行数为" << b << endl ;
	return 0;
}
