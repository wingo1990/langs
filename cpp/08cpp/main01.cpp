#include<iostream>
#include<sstream>

using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		istringstream iss(str);		//�����������ַ���str
		string word;

		iss >> word;
		cout << word;
		while(iss>>word)			//������������ʱ��EOF, ������
			cout << "#" << word; 
	}

	return 0;
}