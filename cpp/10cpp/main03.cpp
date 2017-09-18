#include <iostream>

using namespace std;

template <typename T>
class MyClass
{
public:
	MyClass(const T& v): _val(v) {}

	//�ǳ�Աģ��
	//void Assign(const MyClass<T>& other)
	//{
	//	_val = other._val;
	//}

	//��Աģ��, ��const�汾
	//template<typename X>
	//void Assign(MyClass<X>& other)
	//{
	//	_val = other.GetValue();
	//}

	//T& GetValue() {return _val;}

	//��Աģ��, const�汾
	template<typename X>
	void Assign(const MyClass<X>& other)		// �����������const����������ֻ�ܵ���const������
	{
		_val = other.GetValue();
	}

	const T& GetValue() const {return _val;}	// �����������const������ʵ���Ͻ�thisָ����ָ�������const�����������Բ��ɸı䡣
												// ����_val const�ˣ���ô��������һ��Ҫconst�����Ժ�������ֵΪconst &
private:							
	T _val;
};

int main()
{
	MyClass<int> m1(10);
	MyClass<int> m3(20);
	MyClass<double> m2(1.1);

	//m1.Assign(m2);
	m1.Assign(m3);
	return 0;
}