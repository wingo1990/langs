#include <iostream>
using namespace std;

int main(void)
{
	int m = 1;
	volatile const int *mp = &m;
	// *mp = 2; very important, this is the key of `const`
	m = 3;
	int *mpp = const_cast<int *>(mp); // this is regular useful way of `const_cast`
	*mpp = 5;
	cout << "m = " << m << endl;
	cout << "*p = " << *mp << endl;
	
	// volatile �ױ�ģ����Ա�������ÿ�η��ʸñ���ʱ���Ǵӱ�����ַ�л�ȡ�������Ǵӻ���ļĴ����ж�ȡ
	/* volatile */ const int a = 100;				// ��û��volatile��ʱ��C++���õ��Ż����õ�a�滻��100

	int *p = const_cast<int*>(&a);

	*p = 700;

	cout << "&a = "<<(int*)&a<<endl;
	cout << "p = " <<p<<endl;

	cout <<"a1 = "<<a<<endl;				//a ��volatile ���δ�ӡ�ľ�һ����,���Ա�֤a�Ǵ��ڴ��ж������Ǵӷ��ű��ж�ȡ��
	cout <<"a2 = "<<*(int*)&a<<endl;
	cout <<"*p = "<<*p<<endl;

	//������������Ǻ���ģ�����������ǲ�����ģ������ԭ���ǣ�
	//const_cast��Ҫת���Ķ���ʱָ������ò������塣

	//ָ��
	const int *b = new int(100);
	int *q = const_cast<int*>(b);

	*q = 200;
	cout << "b= "<< b <<endl;
	cout << "q= "<< q <<endl;

	cout <<"*b="<<*b <<endl;
	cout <<"*q="<<*q <<endl;

	//����
	volatile const int i = 100;
	int &j = const_cast<int &>(i);
	cout << "before &i = " << (int*)&i <<endl;
	cout << "befoer &j = " << &j <<endl;

	j = 200;

	cout << "after &i = " << (int*)&i <<endl;
	cout << "after &j = " << &j <<endl;

	cout << "i = " << i << endl;
	cout << "j = " << j << endl;
 


	//�Զ���
	class MyClass
	{
	public:
		int a;
		double b;
		MyClass(int a1, double b1): a(a1), b(b1){}
	};

	const MyClass aa(1,2.5);
	MyClass &bb = const_cast<MyClass &>(aa);

	cout<< "before &aa = " << &aa << endl;
	cout<< "before &bb = " << &bb << endl;

	bb.a = 100;
	bb.b = 25.5;

	cout<< "after &aa = " << &aa << endl;
	cout<< "after &bb = " << &bb << endl;

	cout << "aa.a = " << aa.a << endl;
	cout << "aa.b = " << aa.b << endl;
	cout << "bb.a = " << bb.a << endl;
	cout << "bb.b = " << bb.b << endl;
	
	return 0;
}
