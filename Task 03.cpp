#include<iostream>
#include<fstream>
using namespace std;
void Read(int size, char Arr[], ifstream &fin);
int Compare(int size, int search, char Arr[]);

int main()
{
	int num = 0, size = 0;
	char search = '\0';
	char *Arr = new char[size];
	ifstream fin;
	fin.open("input.txt");
	fin >> num;
	fin.ignore();
	for (int i = 0; i < num; i++)
	{
		fin >> search;
		fin.ignore();
		fin >> size;
		cout << "Search: " << search << endl;
		cout << "Size: " << size << endl;
		Arr = new char[size];
		Read(size,Arr,fin);
		Compare(size,search,Arr);
	}
}
void Read(int size, char Arr[],ifstream &fin)
{
	for (int j = 0; j < size; j++)
	{
		fin >> Arr[j];
		cout << Arr[j] << " ";
	}
	cout << endl;
}
int Compare(int size,int search, char Arr[])
{
	cout << "Search Number: ";
	for (int j = 0; j < size; j++)
	{
		if (Arr[j] == search)
		{
			cout << Arr[j] << endl;
			break;
		}
	}
	return search;
}