#ifdef TESTDLL_EXPORTS //同專案名稱，只是後面固定為_EXPORTS
#define TestDll_API __declspec(dllexport) //請注意！正確的是Export要亮起
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
	//宣告在function內，只有該function能使用
	return instance->Addition(a, b);
}

extern "C" TestDll_API int Sub(Calculate* instance, int a, int b)
{
	//宣告在function內，只有該function能使用
	return instance->Subtraction(a, b);
}

extern "C" TestDll_API int Multi(Calculate* instance, int a, int b)
{
	//宣告在function內，只有該function能使用
	return instance->Multiplication(a, b);
}

extern "C" TestDll_API float Div(Calculate* instance, int a, int b)
{
	//宣告在function內，只有該function能使用
	return instance->Division(a, b);
}

extern "C" TestDll_API void RegisterCallback(Calculate* instance, void(*callback)(int, int, int, int))
{
	return instance->RegisterCallback(callback);
}