#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int BLACKJACK = 21;
const int DEALER_HIT_LIMIT = 16;

int drawCard() {
  return rand() % 11 + 1;
}

int main() {

  srand(time(0));

  int playerScore = 0;
  int dealerScore = 0;

  cout << "Welcome to Blackjack!" << endl;
  cout << "Do you want to play (y/n)" << endl;

  char playchoice;
  cin >> playchoice;
  if (playchoice == 'y' || playchoice == 'Y')
  {


      // Deal initial cards
      playerScore += drawCard();
      dealerScore += drawCard();
      playerScore += drawCard();
      dealerScore += drawCard();

      Start:cout << "You have a score of " << playerScore << "." << endl;
      cout << "The dealer has a score of " << dealerScore << "." << endl;

      // Player turn
      while (true) {
          cout << "Would you like to hit or stand? (h/s)" << endl;
          char choice;
          cin >> choice;

          if (choice == 'h') {
              playerScore += drawCard();
              cout << "Your new score is " << playerScore << "." << endl;
          }
          else if (choice == 's') {
              break;
          }

          if (playerScore > BLACKJACK) {
              cout << "You bust! You lose." << endl;
              return 0;
          }
      }

      // Dealer turn
      while (dealerScore < DEALER_HIT_LIMIT) {
          dealerScore += drawCard();
          cout << "The dealer hits and now has a score of " << dealerScore << "." << endl;

          if (dealerScore > BLACKJACK) {
              cout << "The dealer busts! You win." << endl;
              return 0;
          }
      }

      // Compare scores
      if (playerScore > dealerScore) {
          cout << "You win!" << endl;
          goto End;
      }
      else if (playerScore < dealerScore) {
          cout << "You lose." << endl;
          goto End;
      }
      else {
          cout << "It's a tie." << endl;
          goto End;
      }

      End:cout << "Do you want to play again (y/n)" << endl;
      char endchoice;
      cin >> endchoice;
      if (endchoice == 'y' || endchoice == 'Y')
      {
          goto Start;
      }

      if (endchoice == 'n' || 'N')
      {
          exit(0);
      }
  }

  if (playchoice == 'n' || 'N') {
      exit(0);
  }

  return 0;
}
