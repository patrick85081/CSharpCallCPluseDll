#include "Calculate.h"
#include <stdio.h>

Calculate::Calculate()
{
}

int Calculate::Addition(int a, int b)
{
	return a + b;
}

int Calculate::Subtraction(int a, int b)
{
	return a - b;
}

int Calculate::Multiplication(int a, int b)
{
	return a * b;
}

float Calculate::Division(int a, int b)
{
	return a / b;
}

void Calculate::RegisterCallback(void(*callback)(int, int, int, int))
{
	callback(1, 2, 3, 4);
}

