//3. Реализовать класс Player, который наследует от класса GenericPlayer.У этого класса будет 4 метода:
//   • virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса.
//     Метод спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя в виде true или false.
//   • void Win() const - выводит на экран имя игрока и сообщение, что он выиграл.
//   • void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
//   • void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.


#include <iostream>

class Player : virtual public GenericPlayer
{
public:
    Player(const std::string& inputName)
        : GenericPlayer(inputName) {}
    virtual bool IsHitting() const override
    {
        while (true)
        {
            std::cout << *this;
            std::cout << "\nВзять другую карту? (Y/N): ";
            bool formatCheck = true;
            std::string input;
            std::getline(std::cin, input);
            if (std::cin && (input == "N" || input == "n")) return false;
            else if (std::cin && (input == "Y" || input == "y")) return true;
            else
            {
                //system("cls");
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Неверный ввод!";
            }
        }
    }

    void Win() const
    {
        std::cout << "\n" << name << " Выиграл!";
    }

    void Lose() const
    {
        std::cout << "\n" << name << "Проиграл";
    }

    void Push() const
    {
        std::cout << "\n" << name << "Сыграл вничью";
    }
}