#pragma once
class Calculate
{
public:
	Calculate();

	int Addition(int a, int b);//�[�k

	int Subtraction(int a, int b);//��k

	int Multiplication(int a, int b);//���k

	float Division(int a, int b);//���k

	void RegisterCallback(void(*callback)(int, int, int, int));
};

