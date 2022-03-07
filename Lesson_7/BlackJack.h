#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

enum Suits {
    CLUBS = 0,
    DIAMONDS = 1,
    HEARTS = 2,
    SPADES = 3
};

enum Ranks {
    ACE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    JACK = 11,
    QUEEN = 12,
    KING = 13
};

enum Numbers {
    DECKSIZE = 52,
    HIGHESTCARDVALUE = 10,
    MAXPOINTSTOWIN = 21,
    ACEMAXVALUE = 11,
    ACEMINVALUE = 1,
    DEALERTAKETHRESHOLD = 16
};

class Card
{
protected:
    Suits suit = CLUBS;
    Ranks rank = ACE;
    bool isFaceUp = true;
public:
    Card() {}
    Card(Ranks inputRank, Suits inputSuit)
        : suit(inputSuit), rank(inputRank)
    {

    }
    void Flip()
    {
        isFaceUp = !isFaceUp;
    }

    Ranks getValue()
    {
        return rank;
    }

    Suits getSuit()
    {
        return suit;
    }

    std::string getSuitName() const
    {
        switch (suit)
        {
        case 0:
            return "Треф";
        case 1:
            return "Бубей";
        case 2:
            return "Червей";
        case 3:
            return "Пик";
        default:
            return "";
        }
    }

    std::string getRankName() const
    {
        switch (rank)
        {
        case 1:
            return "Туз";
        case 2:
            return "Двойка";
        case 3:
            return "Тройка";
        case 4:
            return "Четверка";
        case 5:
            return "Пятерка";
        case 6:
            return "Шестерка";
        case 7:
            return "Семерка";
        case 8:
            return "Восьмерка";
        case 9:
            return "Девятка";
        case 10:
            return "Десятка";
        case 11:
            return "Валет";
        case 12:
            return "Дама";
        case 13:
            return "Король";
        default:
            return "";
        }
    }

    bool isFaceUpCheck()
    {
        if (isFaceUp) return true;
        else return false;
    }

    friend std::ostream& operator<<(std::ostream& out, const Card& card);
};

std::ostream& operator<<(std::ostream& out, const Card& card)
{
    if (card.isFaceUp)
    {
        out << card.getRankName() << " " << card.getSuitName() << "\n";
    }
    else out << "XX\n";
    return out;
}

class Hand
{
protected:
    std::vector<Card*> hand;
public:
    void Add(Card* input)
    {
        hand.push_back(input);
    }

    void Clear()
    {
        hand.clear();
    }

    int GetValue() const
    {
        int sum = 0;
        bool hasAce = false;
        for (Card* card : hand)
        {
            if (card->getValue() >= HIGHESTCARDVALUE)
            {
                sum += HIGHESTCARDVALUE;
            }
            else if (card->getValue() == ACE)
            {
                hasAce = true;
            }
            else
            {
                sum += card->getValue();
            }

            if (hasAce && (sum + ACEMAXVALUE <= MAXPOINTSTOWIN))
            {
                sum += ACEMAXVALUE;
            }
            else if (hasAce && (sum + ACEMAXVALUE > MAXPOINTSTOWIN))
            {
                sum += ACEMINVALUE;
            }
        }
        return sum;
    }

    virtual ~Hand()
    {
        Clear();
    }
};

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
    out << "\n" << genericPlayer.name << " имеет:\n";
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
            std::cout << "\nВзять ещё карту? (Y/N): ";
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
                std::cout << "Введите y или n!";
            }
        }
    }

    void Win() const
    {
        std::cout << "\n" << name << " Выиграл!";
    }

    void Lose() const
    {
        std::cout << "\n" << name << " Проиграл.";
    }

    void Push() const
    {
        std::cout << "\n" << name << " сыграл вничью";
    }
};

class House : virtual public GenericPlayer
{
public:
    House()
        : GenericPlayer("Диллер") {}

    virtual bool IsHitting() const override
    {
        if (GetValue() <= DEALERTAKETHRESHOLD) return true;
        else return false;
    }

    void FlipFirstCard()
    {
        hand.front()->Flip();
    }
};

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
        srand(static_cast<unsigned int>(time(NULL)));
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
            std::cout << "Карт не осталось!";
        }

    }

    void AdditionalCards(GenericPlayer& aGenericPlayer)
    {
        while (!aGenericPlayer.IsBusted() && aGenericPlayer.IsHitting())
        {
            Deal(aGenericPlayer);
        }
        if (aGenericPlayer.IsBusted())
        {
            aGenericPlayer.Bust();
        }
    }
};

class Game
{
protected:
    Deck gameDeck;
    House* dealerHand = new House();
    std::vector<Player*> players;
public:
    Game(std::vector<std::string> playerNames)
    {
        players.clear();
        std::vector<std::string>::const_iterator namesIterator = playerNames.begin();
        while (namesIterator != playerNames.end())
        {
            players.push_back(new Player(*namesIterator));
            ++namesIterator;
        }
        gameDeck.Populate();
        gameDeck.Shuffle();
    }

    void Play()
    {
        for (auto name : players)
        {
            gameDeck.Deal(*name);
            gameDeck.Deal(*name);
            std::cout << *name;
        }
        gameDeck.Deal(*dealerHand);
        gameDeck.Deal(*dealerHand);
        dealerHand->FlipFirstCard();
        std::cout << *dealerHand;

        for (auto player : players)
        {
            std::cout << "\n" << player->getName() << "принимает решение:";
            gameDeck.AdditionalCards(*player);
            std::cout << *player;
        }

        dealerHand->FlipFirstCard();
        std::cout << *dealerHand;
        gameDeck.AdditionalCards(*dealerHand);
        std::cout << "Диллер решает брать ли карты...\n" << *dealerHand;

        for (auto player : players)
        {
            if (player->IsBusted()) player->Lose();
            else if (!player->IsBusted() && dealerHand->IsBusted()) player->Win();
            else if (!player->IsBusted() && !dealerHand->IsBusted() && player->GetValue() > dealerHand->GetValue()) player->Win();
            else if (!player->IsBusted() && !dealerHand->IsBusted() && player->GetValue() < dealerHand->GetValue()) player->Lose();
            else if (!player->IsBusted() && !dealerHand->IsBusted() && player->GetValue() == dealerHand->GetValue()) player->Push();
            player->Clear();
        }
        dealerHand->Clear();
    }
};
