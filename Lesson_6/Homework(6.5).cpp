//5. Написать перегрузку оператора вывода для класса Card.
//   Если карта перевернута рубашкой вверх(мы ее не видим), вывести ХХ, если мы ее видим, вывести масть и номинал карты.
//   Также для класса GenericPlayer написать перегрузку оператора вывода, 
//   который должен отображать имя игрока и его карты, а также общую сумму очков его карт.

#include <iostream>

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
            return "Clubs";
        case 1:
            return "Diamonds";
        case 2:
            return "Hearts";
        case 3:
            return "Spades";
        default:
            return "";
        }
    }

    std::string getRankName() const
    {
        switch (rank)
        {
        case 1:
            return "Ace";
        case 2:
            return "Two";
        case 3:
            return "Three";
        case 4:
            return "Four";
        case 5:
            return "Five";
        case 6:
            return "Six";
        case 7:
            return "Seven";
        case 8:
            return "Eight";
        case 9:
            return "Nine";
        case 10:
            return "Ten";
        case 11:
            return "Jack";
        case 12:
            return "Queen";
        case 13:
            return "King";
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