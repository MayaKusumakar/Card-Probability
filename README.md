# Card-Probability
## Problem
In collectible/trading card games like Magic The Gathering and HearthStone it is important for some decks to draw a specific card by a certain turn. For this problem, you will be calculating the probability of drawing at least one copy of a specific card by a given turn

Here's how our card game will be played

You will initially draw N cards from your deck. This is your starting hand
The next step is the mulligan. In the mulligan step you select between 0 and N cards to set aside. Let the number of cards you choose to set aside be M. You will then draw M more cards from the deck.
Note. You cannot redraw the cards you set aside because you set them aside and did not place them back into the deck
You then shuffle those cards back into the deck
After the initial draw and the mulligan you draw one card per turn.
So now we want to calculate what are the odds that you will get at least one copy of the card you are looking for by the desired turn.

Note that we are calculating the actual probability in this problem and are NOT estimating it through simulation. This means that there is NO randomness at all in this problem.
## Assumptions
Input will always be valid.

Valid Input:
Number of cards in the deck: an integer greater than 0
Copies we are looking for: an integer greater than 0
Initial hand size: an integer greater than or equal to 0
Number of Cards to Mulligan: an integer greater than or equal to 0
Turn to draw by: an integer greater than or equal to 0
## Requirements
Print all floats to 2 decimal points unless stated otherwise
You must use have at least three functions in your program
## Restrictions
No global variables may be used
# Examples
## Example 1
Enter how many total cards there are in the deck: 10

Enter how many copies of the card that you are looking for are in the deck: 2

Enter your initial hand size: 2

Enter how many cards you are mulliganing: 1

Enter what turn you want to draw the card by: 3

The probability of drawing at least one of the cards by turn 3 given you mulliganed 1 cards is 0.83

