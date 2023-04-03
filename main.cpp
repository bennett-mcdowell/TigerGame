/*  Bennett McDowell
    CPSC 1020 - 001
    3/28/2023
    This program is a game where the objective is to get more ponts than the computer from cards.
    Time spent: ~15 hours
*/
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include <iostream>
using namespace std;

int main()
{
    vector<int> human_wins, computer_wins, human_points, computer_points;
    int total_rounds = 0;

    bool play_again = true;
    while (play_again)
    {
        // 1. Create a deck of cards and shuffle it.
        Deck deck;
        deck.shuffle();

        cout << "Welcome to TigerGame!" << endl;

        int drawAmount = 0;
        while (drawAmount <= 0 || drawAmount > 10)
        {
            cout << "How many cards would you like to draw? (Max of 10): " << endl;
            cin >> drawAmount;
            if (drawAmount <= 0 || drawAmount > 10)
            {
            cout << "Enter another input, max is 10." << endl;
            }
        }

        cout << "The deck was shuffled and each player has drawn " << drawAmount << " cards." << endl;
        cout << endl;

        // 2. Create two players, each one with 5 cards in their hand.
        Player human(deck, drawAmount);
        Player computer(deck, drawAmount);

        // 3. Play five rounds. In each round:
        for (int i = 1; i <= drawAmount; i++)
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
                human_wins.push_back(i);
            }
            else if (human_card.getValue() < computer_card.getValue())
            {
                cout << "The computer wins this round!" << endl;
                computer.score += computer_card.getValue();
                computer_wins.push_back(i);
            }
            else 
            {
                cout << "Tie!" << endl;
            }
            cout << endl;

            human_points.push_back(human.score);
            computer_points.push_back(computer.score);

            // Print results for current round.
            cout << "Current scores:" << endl;
            cout << "Human: " << human.score << endl;
            cout << "Computer: " << computer.score << endl;

            cout << endl;
        }

        total_rounds += drawAmount;

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
            cout << "It's a tie!" << endl;
        }

        // Ask if the user wants to play again.
        char play_again_input;
        cout << "Do you want to play again? (y/n)" << endl;
        cin >> play_again_input;
        play_again = (play_again_input == 'y' || play_again_input == 'Y');

    }

    // Print overall game statistics.
    cout << "Overall game statistics:" << endl;
    cout << "Total rounds played: " << total_rounds << endl;
    cout << "Human wins: " << human_wins.size() << endl;
    cout << "Computer wins: " << computer_wins.size() << endl;
    cout << "Human points each round: ";
    for (int i = 0; i < human_points.size(); i++)
    {
        cout << human_points[i] << " ";
    }
    cout << endl;
    cout << "Computer points each round: ";
    for (int i = 0; i < computer_points.size(); i++)
    {
        cout << computer_points[i] << " ";
    }
    cout << endl;

    // Human total
    int sum = 0;
    for (auto& n : human_points)
    {
        sum += n;
    }
    cout << "Human total: " << sum << endl;

    // Computer Total
    sum = 0;
    for (auto& n : computer_points)
    {
        sum += n;
    }
    cout << "Computer total: " << sum << endl;
    
return 0;
}