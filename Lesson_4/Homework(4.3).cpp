//3. Реализовать класс Hand, который представляет собой коллекцию карт.В классе будет одно поле : 
//   вектор указателей карт(удобно использовать вектор, т.к.это по сути динамический массив,
//   а тип его элементов должен быть - указатель на объекты класса Card).Также в классе Hand должно быть 3 метода :
//	   • метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
//	   • метод Clear, который очищает руку от карт
//	   • метод GetValue, который возвращает сумму очков карт руки(здесь предусмотреть возможность того, что туз может быть равен 11).

#include <iostream>
#include "BlackJack.h"

int main()
{
    setlocale(LC_ALL, "RUSSIAN");

    Card aceClubs(ACE, CLUBS);
    Card aceHearts(ACE, HEARTS);
    Card kingClubs(KING, CLUBS);

    Hand playerHand;
    playerHand.Add(&aceClubs);
    playerHand.Add(&aceHearts);
    playerHand.Add(&kingClubs);

    int sum = playerHand.GetValue();
    std::cout << "\n\nЗначение руки игрока: " << sum;
    playerHand.Clear();
    sum = playerHand.GetValue();
    std::cout << "\nРука очищена. Новое значение: " << sum;
}
