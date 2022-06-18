#include<iostream>
#include<fstream>
using namespace std;
char *regrow1d(char *first, int col, char temp);
char **regrow2d(char **first, int row);
char **regrow2ds(char **first, int row,int DEL);
int *Regrow(int *id,int first,int di);
int *Shaink(int *id,int first,int size);
int main()
{
	int DEL=0;
	int row = 1, col = 0,size=1,di=0;
	int *id=NULL;
	id=new int[size];
	char **first = new char *[row];
	first[0] = new char[0];
	char temp = '\0';
	ifstream fin;
	fin.open("input.txt");
	fin>>di;
	id[0]=di;
	fin.ignore();
	while (fin.get(temp))
	{
		if (temp != ',')
		{
			first[row-1] = regrow1d(first[row-1], col, temp);
			col++;
		}
		else
		{
			first[row-1] = regrow1d(first[row-1], col,'\0');
			col = 0;
			fin>>di;
			id=Regrow(id,size,di);
			size++;
			first = regrow2d(first, row);
			row++;
		}
	}
	char del=0;
	cout<<"Enter D If You Want To Cancel: ";
	cin>>del;
	while(del=='D')
	{
		cout<<"Enter Which Contact You Wanna Del: ";
		cin>>DEL;
		first=regrow2ds(first,row,DEL);
		{
			row--;
			row--;
		}
		id=Shaink(id,DEL,size);
		{
			size--;
		}
		cout<<"Enter C ";
		cin>>del;
	}
	for (int i = 0; i < row; i++)
	{
		cout<<id[i]<<" ";
		for (int j = 0; first[i][j] != '\0'; j++)
		{
			cout << first[i][j];
		}
		cout<<endl;
	}
	cout << endl;
	return 0;
}
char *regrow1d(char *first, int col, char temp)
{
	char *TEMP = NULL;
	TEMP = first;
	first = new char[col + 1];
	for (int i = 0; i <= col; i++)
	{
		first[i] = TEMP[i];
	}
	first[col] = temp;
	delete[]TEMP;
	return first;
}
char **regrow2d(char **first, int row)
{
	char **TT = NULL;
	TT = first;
	first = new char *[row + 1];
	for (int i = 0; i < row; i++)
	{
		first[i] = TT[i];
	}
	first[row] = new char[0];
	delete[] TT;
	return first;
}
char **regrow2ds(char **first, int row,int DEL)
{
	int j = 0;
	char **TT = NULL;
	TT = first;
	first = new char *[DEL];
	for (int i = 0; i < row; i++)
	{
		if (DEL != i)
		{
			first[j] = TT[i];
			j++;
		}
	}
	delete[] TT;
	return first;
}
int *Regrow(int *id,int size,int di)
{
	int *temp=NULL;
	temp=id;
	id=new int[size+1];
	for(int i=0;i<size;i++)
	{
		id[i]=temp[i];
	}
	delete [] temp;
	id[size]=di;
	return id;
}

int *Shaink(int *id,int DEL,int size)
{
	int j = 0;
	int *TT = NULL;
	TT = id;
	for (int i = 0; i < size; i++)
	{
		if (DEL != id[i])
		{
			id[j] = TT[i];
			j++;
		}
	}
	delete[] TT;
	return id;
}
