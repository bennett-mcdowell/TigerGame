/*  Bennett McDowell
    CPSC 1020 - 001
    3/28/2023
    This program is a game where the objective is to get more ponts than the computer from cards.
    Time spent: ~10 hours
*/
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include <iostream>
using namespace std;

int main()
{
  // 1. Create a deck of cards and shuffle it.
  Deck deck;
  deck.shuffle();

  // 2. Create two players, each one with 5 cards in their hand.
  Player human(deck, 5);
  Player computer(deck, 5);

  cout << "Welcome to TigerGame!" << endl;
  cout << "The deck was shuffled and each player has drawn 5 cards." << endl;
  cout << endl;

  // 3. Play five rounds. In each round:
  for (int i = 1; i <= 5; i++)
  {
    cout << "Round " << i << ":" << endl;
    cout << "-------" << endl;

    // Have computer deal a card from their hand.
    Card computer_card = computer.hand.dealCard(rand() % computer.hand.getHandSize() + 1);
    cout << "The computer plays: " << computer_card.printCard() << endl;

    // Show human their hand of cards so that they can make a selection.
    cout << "Your hand: " << human.hand.printHand() << endl;

    // Have human deal their card.
    int selected_card_num;
    cout << "Which card do you want to play? ";
    cin >> selected_card_num;
    Card human_card = human.hand.dealCard(selected_card_num);
    cout << "You played: " << human_card.printCard() << endl;

    // Determine who won the round and update points accordingly.
    if (human_card.getValue() > computer_card.getValue())
    {
      cout << "You win this round!" << endl;
      human.score += human_card.getValue();
    }
    else if (human_card.getValue() < computer_card.getValue())
    {
      cout << "The computer wins this round!" << endl;
      computer.score += computer_card.getValue();
    }
    else 
    {
      cout << "Tie!" << endl;
    }
    cout << endl;

    // Print results for current round.
    cout << "Current scores:" << endl;
    cout << "Human: " << human.score << endl;
    cout << "Computer: " << computer.score << endl;

    cout << endl;
  }

  // 4. Print final game results.  
  cout << "FINAL SCORE:" << endl;
  cout << "Human: " << human.score << endl;
  cout << "Computer: " << computer.score << endl;
  if (human.score > computer.score)
  {
    cout << "Human has won!" << endl;
  }
  else if (human.score < computer.score)
  {
    cout << "Computer has won!" << endl;
  } 
  else
  {
    cout << "Tie" << endl;
  }

  return 0;
}