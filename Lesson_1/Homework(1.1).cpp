//1. Создать класс Power, который содержит два вещественных числа.
//   Этот класс должен иметь две переменные - члена для хранения этих вещественных чисел.
//   Еще создать два метода : один с именем set, который позволит присваивать значения 
//   объявленным в классе переменным, второй — calculate,который будет выводить результат 
//   возведения первого числа в степень второго числа.Задать значения этих двух чисел по умолчанию.


#include <iostream>
#include <cmath>

class Power
{
public:
	int m_a;
	int m_b;

	void set(int one, int two)
	{
		m_a = one;
		m_b = two;
	}

	void calculate(int m_a, int m_b)
	{
		std::cout << "Возведение в степень: " << pow(m_a, m_b);
	}

	void print()
	{
		std::cout << "Числа(" << m_a << ", " << m_b << ")\n";
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Power num1;
	num1.set(2, 1);

	Power num2{ 5 };

	num1.print();
	num2.print();

	Power step;
	step.calculate(3, 7);

	return 0;
}
