//4. Согласно иерархии классов, которая представлена в методичке к уроку 3, 
//   от класса Hand наследует класс GenericPlayer, который обобщенно представляет игрока, 
//   ведь у нас будет два типа игроков - человек и компьютер.Создать класс GenericPlayer, 
//   в который добавить поле name - имя игрока.Также добавить 3 метода:
//   • IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
//   • IsBoosted() - возвращает bool значение, есть ли у игрока перебор
//   • Bust() - выводит на экран имя игрока и объявляет, что у него перебор.

#include <iostream>


class GenericPlayer : virtual public Hand
{
protected:
    std::string name;
public:
    GenericPlayer(const std::string& inputName)
        : name(inputName) {}

    virtual bool IsHitting() const = 0;

    std::string getName()
    {
        return name;
    }

    bool IsBusted() const
    {
        if (GetValue() > MAXPOINTSTOWIN) return true;
        else return false;
    }

    void Bust()
    {
        std::cout << "\n" << name << " Перебор!\n";
    }

    friend std::ostream& operator<<(std::ostream& out, const GenericPlayer& genericPlayer);
};

std::ostream& operator<<(std::ostream& out, const GenericPlayer& genericPlayer)
{
    bool faceUp = true;
    out << "\n" << genericPlayer.name << " имеется:\n";
    for (auto card : genericPlayer.hand)
    {
        out << *card;
        if (!card->isFaceUpCheck()) faceUp = false;
    }
    if (faceUp)
    {
        out << "Общее количество: " << genericPlayer.GetValue() << "\n";
    }
    else
    {
        out << "Некоторые карты скрыты, невозможно определить общее количество.\n";
    }
    return out;
}
