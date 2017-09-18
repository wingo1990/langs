#include <cassert>
#include<iostream>
#include<fstream>
#include <string>
using namespace std;

typedef struct
{
	int a;
	string b;
	string c;
}Test;


int main()
{
	Test t;
	t.a = 100;
	t.b = "aaa";
	t.c = "ccc";

	ofstream f("test.txt");
	assert(f);
	f.write(reinterpret_cast<char*>(&t),sizeof t);				//���ֶ�д�Ǵ���ģ���aaa����string��û��̫��ֱ�ӵĹ�ϵ��ֻ��ָ���ֵ��string�б����š�
	f.close();

	ifstream f1("test.txt");
	assert(f1);
	Test t1;
	f1.read(reinterpret_cast<char*>(&t1), sizeof t1);
	f1.close();
	cout << sizeof string << endl;
	cout << t1.a << endl;
	cout << t1.b << endl;
	cout << t1.c << endl;

	return 0;
}
