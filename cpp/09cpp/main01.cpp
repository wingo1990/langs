#include<iostream>
#include<iomanip>

using namespace std;


//ʵ�ֲ����ӷ�ʽ�ͳ�Ա�������ַ�ʽ��
//��ȿ���
//�������
//������
//���ȿ���
//���ƿ���

int main()
{
	int n = 65;
	double d = 123.45;
	double d2 = 0.0123;

	cout << "====================��ȿ���===================" << endl;
	cout << setw(10) << n << "#" << endl;								//��Ӱ������Ĳ�����
	cout << n << "#" << endl;

	cout.width(10);														//ֻӰ�����һ�εĲ���
	cout << n << "#" << endl;
	cout << n << "#" << endl;

	cout << "====================�������===================" << endl;
	cout << setw(10) << setiosflags(ios::left) << n << "#" << endl;		//Ӱ����һ�β���
	cout << setw(10) << n << "#" << endl;
	cout << setw(10) << resetiosflags(ios::left) << n << "#" << endl;

	cout.setf(ios::left);												//Ӱ����һ�β���
	cout << setw(10) << n << "#" << endl;
	cout << setw(10) << n << "#" << endl;
	cout.unsetf(ios::left);
	cout << setw(10) << n << "#" << endl;

	cout << "====================������===================" << endl;
	cout << setw(10) << setfill('?') << n << "#" << endl;		//Ӱ����һ�β���
	cout << setw(10) << n << "#" << endl;
	cout << setw(10) << setfill(' ') << n << "#" << endl;

	cout.fill('?');  											//Ӱ����һ�β���
	cout << setw(10) << n << "#" << endl;
	cout << setw(10) << n << "#" << endl;
	cout.fill(' ');
	cout << setw(10) << n << "#" << endl;

	cout << "====================���ȿ���===================" << endl;
	cout << setprecision(4) << setiosflags(ios::fixed) << d << endl; //Ӱ����һ�β���
	cout << setprecision(0) << resetiosflags(ios::fixed)<< d << endl;

	cout.precision(6);
	cout.setf(ios::fixed);
	cout << d2 << endl;
	cout << d2 << endl;
	cout.precision(0);
	cout.unsetf(ios::fixed);

	cout << "====================���ƿ���===================" << endl;
	cout << n << endl;
	cout << hex << setiosflags(ios::showbase) << n << endl;	//�Ժ�����Ӱ��,ͬʱ���ö�����Ʒ�ʽ��������ģ����뽫ǰ��Ļ�ԭ��10���Ƶġ�
	cout << oct << n << endl;
	cout << resetiosflags(ios::showbase) << n << endl;

	cout.unsetf(ios::oct);									//ʹ��֮ǰһ���ð�ǰ��Ľ��Ƹ�unset�����С�
	cout.setf(ios::hex);
	cout.setf(ios::showbase);
	cout << n << endl;
	
	cout.unsetf(ios::hex);
	cout.setf(ios::oct);
	cout << n << endl;

}