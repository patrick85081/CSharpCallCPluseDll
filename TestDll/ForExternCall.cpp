#ifdef TESTDLL_EXPORTS //�P�M�צW�١A�u�O�᭱�T�w��_EXPORTS
#define TestDll_API __declspec(dllexport) //�Ъ`�N�I���T���OExport�n�G�_
#else
#define TestDll_API __declspec(dllimport)
#endif

#include "Calculate.h"

extern "C" TestDll_API Calculate* CreateInstance()
{
	return new Calculate();
}

extern "C" TestDll_API void DisposeInstance(Calculate* instance)
{
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

extern "C" TestDll_API int Add(Calculate* instance, int a, int b)
{	
	//�ŧi�bfunction���A�u����function��ϥ�
	return instance->Addition(a, b);
}

extern "C" TestDll_API int Sub(Calculate* instance, int a, int b)
{
	//�ŧi�bfunction���A�u����function��ϥ�
	return instance->Subtraction(a, b);
}

extern "C" TestDll_API int Multi(Calculate* instance, int a, int b)
{
	//�ŧi�bfunction���A�u����function��ϥ�
	return instance->Multiplication(a, b);
}

extern "C" TestDll_API float Div(Calculate* instance, int a, int b)
{
	//�ŧi�bfunction���A�u����function��ϥ�
	return instance->Division(a, b);
}

extern "C" TestDll_API void RegisterCallback(Calculate* instance, void(*callback)(int, int, int, int))
{
	return instance->RegisterCallback(callback);
}