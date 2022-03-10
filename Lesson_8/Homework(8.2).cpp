//2. Написать класс Ex, хранящий вещественное число x и имеющий конструктор по вещественному числу, 
//   инициализирующий x значением параметра.Написать класс Bar, 
//   хранящий вещественное число y(конструктор по умолчанию инициализирует его нулем) 
//   и имеющий метод set с единственным вещественным параметром a.Если y + a > 100, 
//   возбуждается исключение типа Ex с данными a* y, иначе в y заносится значение a.
//   В функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n.
//   Использовать его в качестве параметра метода set до тех пор, 
//   пока не будет введено 0. В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта исключения.

#include <iostream>

class Ex
{
private:
	double x;
public:
	Ex(double input)
		: x(input) {}

	double getX()
	{
		return x;
	}
};

class Bar
{
private:
	double y;
public:
	Bar()
		: y(0) {}
	void set(double a)
	{
		if (y + a > 100)
		{
			throw Ex(a * y);
		}
		else y = a;
	}
	double getY()
	{
		return y;
	}
};

int main()
{
	std::cout << "\n\nTask 2:\n";
	Bar* bar = new Bar();
	int n = 0;
	try
	{
		bool nNotZero = true;
		while (nNotZero)
		{
			std::cout << "Enter n: ";
			std::cin >> n;
			if (n != 0)
			{
				bar->set(n);
			}
			else nNotZero = false;
		}
	}
	catch (Ex& e)
	{
		std::cout << "Exception thrown, code " << e.getX();
	}
	delete bar;
}
