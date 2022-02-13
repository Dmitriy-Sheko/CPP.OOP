//3. Написать класс, который реализует функциональность стека.Класс Stack должен иметь :
//   private - массив целых чисел длиной 10;
//   private целочисленное значение для отслеживания длины стека;
//   public - метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
//   public - метод с именем push(), который будет добавлять значение в стек.push() должен возвращать значение false,
//   если массив уже заполнен, и true в противном случае;
//   public - метод с именем print(), который будет выводить все значения стека.Чтобы снова открыть этот проект позже, 
//   выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

#include <iostream>
#include <cassert>

class Stack
{
private:
	int m_array[10]; 
	int m_next; 

public:

	void reset()
	{
		m_next = 0;
		for (int i = 0; i < 10; ++i)
			m_array[i] = 0;
	}

	bool push(int value)
	{
		if (m_next == 10)
			return false;
		m_array[m_next++] = value; 
		return true;
	}

	int pop()
	{
		assert(m_next > 0);
		return m_array[--m_next];
	}

	void print()
	{
		std::cout << "( ";
		for (int i = 0; i < m_next; ++i)
			std::cout << m_array[i] << ' ';
		std::cout << ")\n";
	}
};

int main()
{
	Stack stack;
	stack.reset();
	stack.print();
	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();
	stack.pop();
	stack.print();
	stack.pop();
	stack.pop();
	stack.print();

	return 0;
}
