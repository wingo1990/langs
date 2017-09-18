#include <iostream>
using namespace std;

struct E{};

class A
{
public:
	A()
	{
				throw E();
	}
};

class Test
{
public:
	Test(int n=100):_n(n)
	{
		cout << "Test ..." <<endl;
	}
	~Test()
	{
		cout << "~Test ..." <<endl;
	}

	int _n;
};

void *operator new(size_t size)						// operator new origin function
{
	cout << "operator new(size_t size)" << endl;
	return malloc(size);
}

void operator delete(void *p)
{
	cout << "operator delete(void *p)" << endl;
	free(p);
}

void *operator new[](size_t size)						// operator new origin function
{
	cout << "operator new[](size_t size)" << endl;
	return malloc(size);
}

void operator delete[](void *p)
{
	cout << "operator delete[](void *p)" << endl;
	free(p);
}

//void *operator new(size_t size, void *p)			//placement new���������ռ䣬����ָ�ż��ɣ� �����е��ù��캯��
//{
//	cout << "operator new(size_t size)" << endl;
//	return p;
//}
//
//void operator delete(void *p, void *q)			//placement delet�������ͷſռ䣬����Ӧ�õ��������������ŶԳư���������������޷�����(���Ǹ����ص����⣬�������)
//{
//	cout << "operator delete(void *p)" << endl;
//}


void *operator new(size_t size, const char *file, long line)
{
	cout << "[NEW] "<< file << ":" << line <<endl;
	return malloc(size);
}

void operator delete(void *p, const char *file, long line)
{
	cout << "[DELETE] "<< file << ":" << line <<endl;
	free(p);
}



int main(void)
{
	Test *t = new Test();		// new operator = operator new(��Ա�������ڴ�ռ�) + ���캯���ĵ���
	delete t;

	Test *t4 = new Test[10];	// ���������
	delete[] t4;

	//placement new ������������new�ؼ��ֱ�ʶ��Ϊplacement new + ���캯����
	char chunk[10];
	Test *t2 = new (chunk) Test(200);
	t2->~Test();				//��ʾ��������
	//delete t2;

	// operator new ��operator delete����ʹ�õ������
	try{
		A *t3 = new(__FILE__, __LINE__) A();			//��������Կ��������׵�operator delete ������delete������ʱ
	}catch(...) {cout << "exception cautch..." << endl;}	//�ǲ������õģ�������ʹ����Ӧnew�����쳣ʱ�Ż���á�		

	return 0;
}