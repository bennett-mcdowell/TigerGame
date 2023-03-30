#include "Card.h"

Card::Card() {}

Card::Card(int rank, Color color) : rank(rank), color(color)
{
    if (color == Color::orange)
    {
        value = rank * 2;
    }
    else
    {
        value = rank;
    }
}

std::string Card::printCard()
{
    std::string strColor;
    if (color == Color::orange)
    {
        strColor = "orange";
    }
    else
    {
        strColor = "purple";
    }
    return strColor + ":" + std::to_string(rank);
}

int Card::getRank()
{
    return rank;
}

Card::Color Card::getColor()
{
    return color;
}

int Card::getValue()
{
    return value;
}
