#ifndef _STRING_H_
#define _STRING_H_
#include <iostream>
using namespace std;

class String
{
public:
    String(const char *str="");			//����Ĭ��ֵ�������ж��弴�ɣ������в�Ҫ�ظ�
	String(const String&);
	
	String& operator=(const String&);
	String& operator=(const char*);
	
	bool operator==(const String&) const;
	
	bool operator!() const;

	char &operator[](const int i);
	const char &operator[](const int i) const;

	friend String operator+(const String&, const String &);
	String& operator+=(const String &);

	friend ostream &operator<<(ostream &, const String &);
	friend istream &operator>>(istream &, String &);

	~String();
private:
	void AllocAndCpy(char* &d, const char *s);
	char *_str;
};


#endif // _STRING_H_