//  4. Реализовать класс House, который представляет дилера. 
//     Этот класс наследует от класса GenericPlayer. У него есть 2 метода:
//     • virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта. 
//       Если у дилера не больше 16 очков, то он берет еще одну карту.
//     • void FlipFirstCard() - метод переворачивает первую карту дилера.

#include <iostream>

class House : virtual public GenericPlayer
{
public:
    House()
        : GenericPlayer("Dealer") {}

    virtual bool IsHitting() const override
    {
        if (GetValue() <= DEALERTAKETHRESHOLD) return true;
        else return false;
    }

    void FlipFirstCard()
    {
        hand.front()->Flip();
    }
}