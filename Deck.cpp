#include "Deck.h"

Deck::Deck()
{
    for (int i = 1; i <= 10; i++)
    {
        deck.push_back(Card(i, Card::Color::purple));
        deck.push_back(Card(i, Card::Color::orange));
    }

    deck.push_back(Card(10, Card::Color::orange));
}

void Deck::shuffle()
{
    srand(time(0));

    for (auto& card : deck)
    {
        int j = rand() % deck.size();
        std::swap(card, deck[j]);
    }
}

Card Deck::drawCard()
{
    Card drawnCard = deck.front();
    deck.erase(deck.begin());
    return drawnCard;
}

int Deck::getDeckSize()
{
    return deck.size();
}
