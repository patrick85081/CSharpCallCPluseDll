#pragma once
class Calculate
{
public:
	Calculate();

	int Addition(int a, int b);//加法

	int Subtraction(int a, int b);//減法

	int Multiplication(int a, int b);//乘法

	float Division(int a, int b);//除法

	void RegisterCallback(void(*callback)(int, int, int, int));
};

