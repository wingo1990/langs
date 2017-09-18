#include <iostream>
using namespace std;

#define sizeof_v(x)  ((char*)(&x+1) - (char*)&x )		//������С
#define sizeof_t(X)  (size_t)((X*)0 + 1 )				//���ʹ�С
								
#define ALIGN(v, b)  ((v+b-1) & ~(b-1))				//���룬�����ڴ�غ����� 

int main(void)
{
	double d;
	int i;
	struct {int j; int k;} sttt;

	cout << sizeof_v(sttt) << endl;
	cout << sizeof_v(d) << endl;
	cout << sizeof_v(i) << endl;

	cout << sizeof_t(int) << endl;
	cout << sizeof_t(double) <<endl;

	cout << ALIGN(4,4096) << endl;


	return 0;
}