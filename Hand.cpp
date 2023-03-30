#include "Hand.h"

Hand::Hand() {}

Hand::Hand(Deck& deck, int N)
{
    for (int i = 0; i < N; i++)
    {
        hand.push_back(deck.drawCard());
    }
}

std::string Hand::printHand()
{
    std::stringstream ss;
    int i = 0;
    for (auto& card : hand)
    {
        ss << "[" << i + 1 << "] " << card.printCard() << " ";
        i++;
    }
    return ss.str();
}


Card Hand::dealCard(int num)
{
    Card card = hand[num - 1];
    hand.erase(hand.begin() + num - 1);
    return card;
}

int Hand::getHandSize()
{
    return hand.size();
}