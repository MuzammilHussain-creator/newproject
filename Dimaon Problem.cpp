#include<iostream>
using namespace std;
class A
{
public:
	A(){ cout << "Constructor Of A :" << endl; }
	int a;
	void f1(){ cout << "F1" << endl; }
};
class B1:virtual public A
{
public:
	B1(){ cout << "Constructor Of B1 :" << endl; }
	int b1;
	void f2(){ cout << "F2" << endl; }
};
class B2:virtual public A
{
public:
	B2(){ cout << "Constructor Of B2 :" << endl; }
	int b2;
	void f3(){ cout << "F3" << endl; }
};
class C :public B1,public B2
{
public:
	C(){ cout << "Constructor Of C :" << endl; }
	int c;
	void f4(){ cout << "F4" << endl; }
};
int main()
{
	C c;
	return 0;
}