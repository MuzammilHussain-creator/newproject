#include <iostream>
#include<fstream>
using namespace std;
void Read(char ch,int &c,ifstream &fin,char arr[]);

int main()
{
	char ch={'\0'};
	char arr[100]={'\0'};
	int c=0;
	ifstream fin;
	fin.open("input.txt");
	Read(ch,c,fin,arr);
	
	
	return 0;
}
void Read(char ch,int &c,ifstream &fin,char arr[])
{
	int flag=0;
	int i=0;
	while(fin)
	{
		fin.get(ch);
		if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
		{
			arr[i]=ch;
			i++;
			c++;
		}
	}
	int k=c-1;
	for(int j=0; j<c/2; j++,k--)
	{
		if(arr[j]==arr[k])
		{
			flag=1;
		}
		else
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
	{
		cout<<"Palindrome"<<endl;
	}
	else
	{
		cout<<"Not Palindrome"<<endl;
	}
}
