#include<iostream>
#include<fstream>
using namespace std;
void Read(int &count, ifstream &fin,int value);
void Read2(int &count, ifstream &fin, int value,int A[]);

int main()
{
	int count = 0,value=0;
	ifstream fin;
	fin.open("input.txt");
	Read(count,fin,value);
	cout <<"count: "<< count<<endl;
	int *A = new int[count];
	fin.close();
	fin.open("input.txt");
	Read2(count, fin, value,A);

	return 0;
}
void Read(int &count, ifstream &fin,int value)
{
	while (fin >> value)
	{
		count++;
	}
}
void Read2(int &count, ifstream &fin, int value,int A[])
{
	for (int i = 0; i < count; i++)
	{
		fin >> A[i];
	}
	for (int i = 0; i < count; i++)
	{
		cout << A[i] << endl;
	}
}