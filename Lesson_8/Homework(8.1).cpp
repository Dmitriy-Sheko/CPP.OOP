//1. Написать шаблонную функцию div, 
//   которая должна вычислять результат деления двух параметров и запускать исключение DivisionByZero, 
//   если второй параметр равен 0. 
//   В функции main выводить результат вызова функции div в консоль, а также ловить исключения.


#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T1, typename T2>
auto div(T1 numerator, T2 denominator)
{
	return numerator / denominator;
}


int main()
{
	std::cout << "Task 1:\n";
	int numerator = 10;
	double denominator = 18;
	try
	{
		if (denominator == 0) throw std::overflow_error("Division by zero");
		std::cout << numerator << " / " << denominator << " = " << div(numerator, denominator);
	}
	catch (std::overflow_error)
	{
		std::cout << "Division by zero!";
	}
}
