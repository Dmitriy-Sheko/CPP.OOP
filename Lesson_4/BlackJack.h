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
