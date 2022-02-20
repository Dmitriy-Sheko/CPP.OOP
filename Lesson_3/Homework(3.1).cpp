//1. Создать абстрактный класс Figure(фигура).Его наследниками являются классы Parallelogram(параллелограмм) и Circle(круг).
//   Класс Parallelogram — базовый для классов Rectangle(прямоугольник), Square(квадрат), Rhombus(ромб).
//   Для всех классов создать конструкторы.Для класса Figure добавить чисто виртуальную функцию area() (площадь).
//   Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.

#include <iostream>


//Task 1 =================================================================================================================
class Figure
{
public:
	Figure() {};
	virtual double area() = 0;
};

class Parallelogram : public Figure
{
protected:
	double a, h;

public:
	Parallelogram(double inputA, double inputH)
		: a(inputA), h(inputH) {};

	double area() override
	{
		return (a * h);
	}
};

class Circle : public Figure
{
private:
	double r;
public:
	Circle(double inputR)
		: r(inputR) {};

	double area() override
	{
		return (3.14 * r * r / 2);
	}
};

class Rectangle : public Parallelogram
{
public:
	Rectangle(double inputA, double inputH)
		: Parallelogram(inputA, inputH) {};

	double area() override
	{
		return (a * h);
	}
};

class Square : public Parallelogram
{
public:
	Square(double inputA)
		: Parallelogram(inputA, inputA) {};

	double area() override
	{
		return (a * a);
	}
};

class Rhombus : public Parallelogram
{
public:
	Rhombus(double inputA, double inputH)
		: Parallelogram(inputA, inputH) {};

	double area() override
	{
		return (a * h);
	}
};

int main()
{

	double parallelorgamHeight(3), parallelogramBase(5.1);
	Parallelogram parallelogram(parallelogramBase, parallelorgamHeight);
	std::cout << parallelogram.area() << "\n";

	double circleRadius(2.8);
	Circle circle(circleRadius);
	std::cout << circle.area() << "\n";

	double squareBase(5);
	Square square(squareBase);
	std::cout << square.area() << "\n";

	double rectangleBase(3), rectangleHeight(3);
	Rectangle rectangle(rectangleBase, rectangleHeight);
	std::cout << rectangle.area() << "\n";

	double rhombusBase(2), rhombusHeight(5);
	Rhombus rhombus(rhombusBase, rhombusHeight);
	std::cout << rhombus.area() << "\n";
}