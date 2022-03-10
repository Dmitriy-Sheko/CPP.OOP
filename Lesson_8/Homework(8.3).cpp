//3. Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у которого есть метод, 
//   означающий задание переместиться на соседнюю позицию.Эти методы должны запускать классы - исключения OffTheField, 
//   если робот должен уйти с сетки, и IllegalCommand, если подана неверная команда(направление не находится в нужном диапазоне).
//   Объект исключения должен содержать всю необходимую информацию — текущую позицию и направление движения.Написать функцию main, 
//   пользующуюся этим классом и перехватывающую все исключения от его методов, а также выводящую подробную информацию о всех возникающих ошибках.

#include <iostream>
#include <stdexcept>
#include <vector>


class Cell
{
private:
	int x, y;
	bool containsRobot = false;
public:
	Cell(int inputX, int inputY)
		: x(inputX), y(inputY) {}

	int getX()
	{
		return x;
	}

	int getY()
	{
		return y;
	}

	void setX(int input)
	{
		x = input;
	}

	void setY(int input)
	{
		y = input;
	}
};

class Robot
{
private:
	int fieldSize;
	Cell currentCell;
public:
	Robot(int inputSize)
		: fieldSize(inputSize), currentCell(0, 0) {}

	void move()
	{
		std::string axis, direction;
		try
		{
			std::cout << "Choose movement axis (x, y):";
			std::cin >> axis;
			if (axis != "x" && axis != "y") throw IllegalCommand();

			std::cout << "Choose movement direction (+, -):";
			std::cin >> direction;
			if (direction != "+" && direction != "-") throw IllegalCommand();
		}
		catch (IllegalCommand)
		{
		}

		int newCoord = 0;

		if (axis == "x" && direction == "+")
		{
			try
			{
				newCoord = currentCell.getX() + 1;
				if (newCoord >= fieldSize)
				{
					throw OffTheField(this, axis, direction);
				}
				else
				{
					currentCell.setX(newCoord);
				}
			}
			catch (OffTheField& e)
			{
				e.printDetails();
			}
		}

		if (axis == "x" && direction == "-")
		{
			try
			{
				newCoord = currentCell.getX() - 1;
				if (newCoord < 0)
				{
					throw OffTheField(this, axis, direction);
				}
				else
				{
					currentCell.setX(newCoord);
				}
			}
			catch (OffTheField& e)
			{
				e.printDetails();
			}
		}

		if (axis == "y" && direction == "+")
		{
			try
			{
				newCoord = currentCell.getY() + 1;
				if (newCoord >= fieldSize)
				{
					throw OffTheField(this, axis, direction);
				}
				else
				{
					currentCell.setY(newCoord);
				}
			}
			catch (OffTheField& e)
			{
				e.printDetails();
			}
		}

		if (axis == "y" && direction == "-")
		{
			try
			{
				newCoord = currentCell.getY() - 1;
				if (newCoord < 0)
				{
					throw OffTheField(this, axis, direction);
				}
				else
				{
					currentCell.setY(newCoord);
					//return true;
				}
			}
			catch (OffTheField& e)
			{
				e.printDetails();
				//return false;
			}
		}
	}

	int getCoordX()
	{
		return currentCell.getX();
	}

	int getCoordY()
	{
		return currentCell.getY();
	}

	void printCoordinates()
	{
		std::cout << "Current coordinates (x, y): (" << currentCell.getX() + 1 << "," << currentCell.getY() + 1 << ")\n";
	}

	class IllegalCommand
	{
	public:
		IllegalCommand()
		{
			system("cls");
			std::cout << "Incorrect command! Choose correct axis and direction.\n";
		}
	};

	class OffTheField
	{
	private:
		Robot* robotPtr;
		std::string axis, direction;
	public:
		OffTheField(Robot* robot, std::string inputAxis, std::string inputDirection)
			: robotPtr(robot), axis(inputAxis), direction(inputDirection) {}
		void printDetails() const
		{
			std::cout << "\nIncorrect input, Robot will be off the field!\nInitial coordinates (x, y): (" << robotPtr->getCoordX() + 1 << "," << robotPtr->getCoordY() + 1 << ")\n";
			std::cout << "Movement axis: " << axis << ", movement direction: " << direction << "\n";
		}
	};
};
