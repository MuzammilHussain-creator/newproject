#include<iostream>
#include<fstream>
using namespace std;
void IntRead(int Array[],int size,ifstream &fin);
void CharRead(char Arr[],int size,ifstream &fin);
bool Compare(int Array[],int search,int size);
bool CharCompare(char Arr[],char searching,int size);
int main()
{
	int search=0;char searching='\0';int num=0;
	int size=0;
	char ch='\0';
	int *Array=new int[size];
	char *Arr=new char[size];
	ifstream fin;
	fin.open("input.txt");
	fin>>num;
	for(int j=0;j<num;j++)
	{
		fin>>ch;
		if(ch=='i')
		{
			fin>>search;
			fin>>size;
			Array=new int[size];
			IntRead(Array,size,fin);
			if(Compare(Array,search,size))
			{
				cout<<"Number Is Found: "<<endl;
			}
			else
			{
				cout<<"Number Is Not Found: "<<endl;
			}
			delete [] Array;
			
		}
		else
		{
			fin>>searching;
			fin>>size;
			Arr=new char[size];
			CharRead(Arr,size,fin);
			if(CharCompare(Arr,searching,size))
			{
				cout<<"Character Is Found: "<<endl;
			}
			else
			{
				cout<<"Character Is Not Found: "<<endl;
			}
			delete [] Arr;
		}
	}
	return 0;
}
void IntRead(int Array[],int size,ifstream &fin)
{
	for(int k=0; k<size; k++)
	{
		fin>>Array[k];
	}
	cout<<endl;
}
void CharRead(char Arr[],int size,ifstream &fin)
{
	for(int k=0; k<size; k++)
	{
		fin>>Arr[k];
	}
	cout<<endl;
}
bool Compare(int Array[],int search,int size)
{
	int flag=true;
	for(int k=0; k<size; k++)
	{
		if(Array[k]==search)
		{
			flag=true;
			break;
		}
		else
		{
			flag=false;
		}
	}
	if(flag==true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool CharCompare(char Arr[],char searching,int size)
{
	int flag=true;
	for(int k=0; k<size; k++)
	{
		if(Arr[k]==searching)
		{
			flag=true;
			break;
		}
		else
		{
			flag=false;
		}
	}
	if(flag==true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
