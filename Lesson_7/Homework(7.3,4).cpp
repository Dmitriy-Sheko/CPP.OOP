#include <iostream>
#include <vector>
#include <algorithm>

//3. Создать класс Deck, который наследует от класса Hand и представляет собой колоду карт.Класс Deck имеет 4 метода:
//   • vold Populate() - Создает стандартную колоду из 52 карт, вызывается из конструктора.
//   • void Shuffle() - Метод, который тасует карты, можно использовать функцию из алгоритмов STL random_shuffle
//   • vold Deal(Hand& aHand) - метод, который раздает в руку одну карту
//   • void AddltionalCards(GenericPlayer& aGenerlcPlayer) - раздает игроку дополнительные карты до тех пор, пока он может и хочет их получать

class Deck : virtual public Hand
{
private:
public:
    void Populate()
    {
        for (int suitCount = CLUBS; suitCount <= SPADES; suitCount++)
        {
            for (int rankCount = ACE; rankCount <= KING; rankCount++)
            {
                Add(new Card(static_cast<Ranks>(rankCount), static_cast<Suits>(suitCount)));
            }
        }
    }

    Deck()
    {
        Populate();
    }

    void Shuffle()
    {
        std::random_shuffle(hand.begin(), hand.end());
    }

    void Deal(Hand& aHand)
    {
        if (!hand.empty())
        {
            aHand.Add(hand.back());
            hand.pop_back();
        }
        else
        {
            std::cout << "No cards left!";
        }

    }

    void AdditionalCards(GenericPlayer& aGenericPlayer)
    {
        while (!aGenericPlayer.IsBoosted() && aGenericPlayer.IsHitting())
        {
            Deal(aGenericPlayer);
        }
        if (aGenericPlayer.IsBoosted()) aGenericPlayer.Bust();
    }
};


//4. Реализовать класс Game, который представляет собой основной процесс игры.У этого класса будет 3 поля:
//   • колода карт
//   • рука дилера
//   • вектор игроков.
//   Конструктор класса принимает в качестве параметра вектор имен игроков и создает объекты самих игроков.
//   В конструкторе создается колода карт и затем перемешивается.
//   Также класс имеет один метод play().В этом методе раздаются каждому игроку по две стартовые карты, 
//   а первая карта дилера прячется.Далее выводится на экран информация о картах каждого игра, в т.ч.и для дилера.
//   Затем раздаются игрокам дополнительные карты.Потом показывается первая карта дилера и дилер набирает карты, 
//   если ему надо.После этого выводится сообщение, кто победил, а кто проиграл.В конце руки всех игроков очищаются.

class Game
{
private:
    Deck gameDeck;
    House dealerHand;
    std::vector<Player*> players;
public:
    Game(std::vector<std::string> playerNames)
    {
        players.clear();
        players.resize(playerNames.size());
        std::vector<std::string>::const_iterator namesIterator = playerNames.begin();
        while (namesIterator != playerNames.end())
        {
            players.push_back(new Player(*namesIterator));
        }
        gameDeck.Shuffle();
    }
    void Play()
    {

    }
};