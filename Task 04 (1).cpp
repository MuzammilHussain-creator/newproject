#include<iostream>
#include<fstream>
using namespace std;
void Count(int &count, char ch,ifstream &fin);
void Read1(char A[], ifstream &fin, int &count);
void Read2(char B[], ifstream &fin1, int &count);
void Write(char A[], char B[], ofstream &fout);

int main()
{
	int count = 0;
	char ch = '\0';
	char A[100] = { '\0' };
	char B[100] = { '\0' };
	ofstream fout;
	fout.open("output.txt");
	ifstream fin,fin1;
	fin.open("input1.txt");
	Count(count,ch,fin);
	fin.close();
	fin.open("input1.txt");
	fin1.open("input2.txt");
	for (int i = 0; i < count; i++)
	{
		Read1(A, fin, count);
		Read2(B, fin1, count);
		Write(A, B, fout);
	}
	

	return 0;
}
void Count(int &count, char ch,ifstream &fin)
{
	while (fin)
	{
		fin.get(ch);
		if (ch == '\n')
		{
			count++;
		}
	}
	count = count - 1;
}
void Read1(char A[], ifstream &fin, int &count)
{
	fin.getline(A,99);
}
void Read2(char B[], ifstream &fin1, int &count)
{
	fin1.getline(B, 99);
}
void Write(char A[], char B[], ofstream &fout)
{
	fout << A << " " << B << endl;
}
