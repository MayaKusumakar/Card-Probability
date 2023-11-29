#include <stdio.h>
/* This program finds the probability of drawing at least one copy of a specific
 * card by a certain turn. The deck size, number of copies and turns are
 * variable to change based on the input by the user. */

double ProbOfNotWinningInitialHand(int deckSize, int numCopies, int handSize) {
  /*
ProbOfNotWinningInitialHand finds the probability of not getting a copy of the
card wanted when picking up the initial hand
@param deckSize - the size of the deck
@param numCopies - the number of copies of the card wanted in the deck
@param handSize - the number of cards that will be in the initial hand
@reutrn - the probability of not getting a copy of the card in the initial hand
pickup
          */
  int otherCards = deckSize - numCopies;
  double currentProb = 1.0;
  for (int i = 0; i < handSize; i++) {
    currentProb *= ((double)otherCards / (double)deckSize);
    otherCards--;
    deckSize--;
  }
  return currentProb;
}

double ProbOfNotWinningMulligan(int deckSize, int numCopies,
                                int numCardsMulliganed) {
  /*
ProbOfNotWinningMulligan finds the probability of not getting a copy of the card
wanted when mulliganing the hand
@param deckSize - the size of the deck
@param numCopies - the number of copies of the card wanted in the deck
@param numCardsMulliganed - the number of cards that will mulliganed
@reutrn - the probability of not getting a copy of the card in the mulligan
          */
  int otherCards = deckSize - numCopies;
  double currentProb = 1.0;

  for (int i = 0; i < numCardsMulliganed; i++) {
    currentProb *= ((double)otherCards / (double)deckSize);
    otherCards--;
    deckSize--;
  }
  return currentProb;
}

double probOfNotWinningByTurns(int deckSize, int numCopies, int TurnToDraw) {
  /*
ProbOfNotWinningByTurns finds the probability of not getting a copy of the card
wanted when picking up at the end of the turn given
@param deckSize - the size of the deck
@param numCopies - the number of copies of the card wanted in the deck
@param TurnToDraw - the turn given to draw the card
@reutrn - the probability of not getting a copy of the card at the end of the
turn given
          */
  int otherCards = deckSize - numCopies;
  double currentProb = 1.0;
  for (int i = 0; i < TurnToDraw; i++) {
    currentProb *= ((double)otherCards / (double)deckSize);
    otherCards--;
    deckSize--;
  }
  return currentProb;
}

int main(void) {
  /* main gets the user input for deck size, number of copies, hand size, number
of cards mulliganed and the turn given to draw the card by and prints the
probability of getting a copy of the card by the end of the final turn.
@return 0 if the function is iterated all the way to the end
  */
  int deckSize;
  int numOfCopies;
  int handSize;
  int numCardsMulliganed;
  int turnToDraw;
  double probNotWinningInitial;
  double probNotWinningMulligan;
  double probNotWinningByTurn;
  double probOfGettingCard;

  printf("Enter how many total cards there are in the deck: ");
  scanf("%d", &deckSize);
  printf("Enter how many copies of the card that you are looking for are in "
         "the deck: ");
  scanf("%d", &numOfCopies);
  printf("Enter your initial hand size: ");
  scanf("%d", &handSize);
  printf("Enter how many cards you are mulliganing: ");
  scanf("%d", &numCardsMulliganed);
  printf("Enter what turn you want to draw the card by: ");
  scanf("%d", &turnToDraw);

  probNotWinningInitial =
      ProbOfNotWinningInitialHand(deckSize, numOfCopies, handSize);
  deckSize -= handSize;

  probNotWinningMulligan =
      ProbOfNotWinningMulligan(deckSize, numOfCopies, numCardsMulliganed);

  probNotWinningByTurn =
      probOfNotWinningByTurns(deckSize, numOfCopies, turnToDraw);

  probOfGettingCard = 1.0 - (probNotWinningInitial * probNotWinningMulligan *
                             probNotWinningByTurn);

  printf("The probability of drawing at least one of the cards by turn %d "
         "given you mulliganed %d cards is %.2lf",
         turnToDraw, numCardsMulliganed, probOfGettingCard);

  return 0;
}