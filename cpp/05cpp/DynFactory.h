#ifndef _DYNFACTORY_H_
#define _DYNFACTORY_H_

#include "Shape.h"
#include <map>
#include <string>
using namespace std;

typedef void* (*FUNC)();

class DynFactory
{
public:
	static void *CreateObject(const string &name)
	{
		map<string, FUNC>::const_iterator it;
		it = _mf.find(name);
		if (it == _mf.end())
			return 0;
		return it->second();
	}

	static void Register(const string &name, FUNC func)
	{
		_mf[name] = func;
	}

	//��Ӵ˴���ʵ����Դ���Զ����գ��ƺ�����ʵ�֡�
	//static void Destroy()
	//{
	//	map<string, FUNC>::const_iterator it;
	//	for (it = _mf.begin(), it != _mf.end(), ++it)
	//	{
	//		delete 
	//	}
	//	_mf.clear();
	//}
private:
	static map<string, FUNC> _mf;
};

map<string, FUNC> DynFactory::_mf;


//�����ʵ�ַ����и����ص����⣺
//�ڳ����ִ��˳������Ҫ�󣬰���˳�����̣�������Ҫ����ע�ᣬ���ܵ���CreateObject������
//�����Ը�������ע��������������ط������Եġ�

//#define REGISTER_CLASS(ClassName) \
//class ClassName##Register{	\
//public: \
//	static void *NewInstance() \
//	{ \
//		return new ClassName; \
//	} \
//}; \
//DynFactory::Regist(#ClassName, ClassName##Register::NewInstance);

class RegisterMap
{
public:
	RegisterMap(const string &name, FUNC func)
	{
		DynFactory::Register(name, func);
	}
	~RegisterMap()
	{
		//��������Ӵ��룬�ƺ�����ʵ����Դ���Զ����ա�
	}
};

#define REGISTER_CLASS(ClassName)	\
class ClassName##Register{	\
public:	\
	static void *NewInstance()	\
	{	\
		return new ClassName;	\
	}	\
private:	\
static RegisterMap _reg;	\
};	\
RegisterMap ClassName##Register::_reg(#ClassName, ClassName##Register::NewInstance);

#endif //_DYNFACTORY_H_