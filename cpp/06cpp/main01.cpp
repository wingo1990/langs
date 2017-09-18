#include <iostream>
#include <memory>
using namespace std;

class Singleton
{
public:
	static Singleton *GetInstance()
	{
		if (!_Instance.get())
		{
			_Instance = auto_ptr<Singleton>(new Singleton);	//���캯��+��ֵ�����(ǳ����)
		}
		
		return _Instance.get();								//����new Singleton ��ָ��
	}

	~Singleton()
	{
		cout << "~Singleton..."<< endl;
	}
private:
	//��ֹ����
	Singleton(const Singleton &other){}
	Singleton& operator=(const Singleton&){}
	
	//Ĭ�Ϲ��캯��˽�У����������ʵ������
	Singleton()
	{
		cout << "Singleton..." << endl;
	}

static auto_ptr<Singleton> _Instance;
};

auto_ptr<Singleton> Singleton::_Instance;

int main(void)
{
	Singleton *t = Singleton::GetInstance();
	Singleton *t1 = Singleton::GetInstance();

	cout << t << endl;				// ʵ����ַ��ͬ
	cout << t1 << endl;

	//t2 = t;
}