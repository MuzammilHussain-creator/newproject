#include<iostream>
#include<fstream>
using namespace std;
void Read(int &count, ifstream &fin, int value);
void Read2(int A[], ifstream &fin, int &search, int &count);
bool Compare(int A[], int &search, int &count);

int main()
{
	int count = 0, value = 0;
	int search = 0;
	cout << "Enter Search Word: ";
	cin >> search;
	ifstream fin;
	fin.open("input.txt");
	Read(count, fin, value);
	cout << "count: " << count << endl;
	int *A = new int[count];
	fin.close();
	fin.open("input.txt");
	Read2(A, fin, search, count);
	if (Compare(A, search, count))
	{
		cout << "Found"<<endl;
	}
	else
	{
		cout << "Not Found: "<<endl;
	}
	return 0;
}
void Read(int &count, ifstream &fin, int value)
{
	while (fin >> value)
	{
		count++;
	}
}
void Read2(int A[], ifstream &fin, int &search,int &count)
{
	for (int i = 0; i < count; i++)
	{
		fin >> A[i];
	}
}
bool Compare(int A[], int &search, int &count)
{
	int flag = false;
	for (int i = 0; i < count; i++)
	{
		if (A[i] == search)
		{
			flag = true;
			break;
		}
		else
		{
			flag = false;
		}
	}
	if (flag == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}