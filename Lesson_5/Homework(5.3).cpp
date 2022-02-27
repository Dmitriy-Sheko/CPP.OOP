/*
    3. Написать шаблон класса StringValuePair, в котором первое значение всегда типа string, а второе — любого типа. Этот шаблон класса должен наследовать частично специализированный класс Pair, в котором первый параметр — string, а второй — любого типа данных.

    Следующий код:

    int main()
    {
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    return 0;
    }

    … должен производить следующий результат:
    Pair: Amazing 7

    Подсказка: при вызове конструктора класса **Pair* из конструктора класса StringValuePair не забудьте указать, что параметры относятся к классу Pair. *
*/

#include <iostream>
#include <string>

template <class A, class B>
class Pair
{
private:
	A m_a;
	B m_b;

public:
	Pair(const A& a, const B& b)
		: m_a(a), m_b(b)
	{

	}

	A& first() { return m_a; }
	const A& first() const { return m_a; }
	B& second() { return m_b; }
	const B& second() const { return m_b; }
};

template <class Y>
class StringValuePair : public Pair<std::string, Y>
{
public:
	StringValuePair(const std::string& key, const Y& value)
		: Pair<std::string, Y>(key, value)
	{

	}
};

int main()
{
	StringValuePair<int> svp("Amazing", 7);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}