#include <iostream>

using namespace std;

template <typename T>
class MyClass
{
public:
	void Dispalay()
	{
		cout << ss << endl;
	}

	typename T::SubType ss;			// ���������������ʱ����Ҫ��typename�ؼ��֡�
};

class Test
{
public:
	typedef int SubType;

};

int main()
{
	MyClass<Test> tt;
	tt.ss = 100;
	tt.Dispalay();
}