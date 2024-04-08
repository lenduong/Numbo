#include <iostream>
#include <vector> 
using namespace std;

// Le Duong
// Project: Numbo

/* Goals:
1. 3 options menu: 1) user is teaser 2) computer is teaser 3)
2. Use functions to execute most of programs
3. Comments
4. Use as little number of guesses as possible
*/

//---------------------------------------------------------------------------------------------------

// Declare functions here:
// void funcName();
void compTease();
void playerTease();
//---------------------------------------------------------------------------------------------------

// Main Function starts here:
int main() {
  int gameOption =1;
  cout << "Welcome to Numbo";

  // Start of the entire game loop
  while (gameOption !=3){
    // Ask user who is teaser or want to quit
    cout << "Selection: \n1) You Guess\n2) Computer Guess \n3) Quit Game\n";
    cout << "PLease enter your selection (1-3): ";
    cin >> gameOption;
    switch (gameOption){
      case 1:
      compTease();
    }
  }
  return 0;
}

//---------------------------------------------------------------------------------------------------
// FUNCTION DEFINITION STARTS HERE:

/* Function: Turning number into string using code given in instruction
Name: num2str
Input name: counter 
Input meaning: counter is an integer and its value will be drawn from the counter varible 
              in createComboArr() function. This one of the 10000 numbers in the array w/o the 0's
Description: takes in a number (int counter) and output a string version of it and add 0's to the 
              front of the number and create a string. This will be used everytime we need to turn
              an integer into string
Example: counter = 204, the function will return comboArrNum = "0204"
Return type: return variable is string type. Its name is comboArrNum. This is going to be each 
              individual number combination (from 0000-9999) in each position of the bigger array of 
              all the possible combination */
string num2str(int counter)
{
  string comboArrNum = "";
  char c; // is used for a single character in the string
  for (int i=0; i<4; i++ ) // using loop to number into string right to left
  {
  c = 48 + counter%10; // this is the ASCII value for the character. 48 = 0
  comboArrNum = c + comboArrNum; // adds the character to the FRONT of string
  counter /=10; // this helps moves number from one decimal point to the next
  }
  return comboArrNum;
}

//---------------------------------------------------------------------------------------------------

/* Function: Putting string number into an array
Name: createComboArr
Input: none 
Description: uses num2str function to generate the string number for each combination of number 
            and input all 10000 combo into an array (comboArr[10000]) that holds all 10000 
            possible combos. */
void createComboArr (){
  int counter = 0; // counter will count from 0-9999
  string comboArr[10000]; // defining the array that holds all the combos
  string comboArrNum; // defining string of each number combination
  for (int i=0; i<10000; i++){ // using loop to input all the possible combo into the array
    comboArrNum = num2str(counter); // using num2str() to generate each string of possible combo
    comboArr[i] = comboArrNum; // input each string number into its appropriate position
    counter++;
  }
}

//---------------------------------------------------------------------------------------------------

/* Function: Checking number of bulls
Name: bullCheck
Inputs: string playerGuess, string tgtNumStr
Inputs Meanings: playerGuess is the string of play'ers guess. tgtNumStr is the secret number generated 
            by the computer
Description: Checking for bulls:
            1. For each of the 4 #'s the user input, computer will run it through a for loop that checks the
               # against each of the 4 correct #
            2. If a number is in the correct place (bull), add 1 to bull counter
            3. If a number isn't in the correct place but is part of the correct combo, add 1 to hit counter 
               for every number that matches the correct combo
            Ex: 5151 (guess) x 1151 (correct) >> h=5, b=3 */
int bullCheck(string playerGuess, string tgtNumStr){
  int hit = 0; // hit counter
  int bull = 0; // bull counter
      for (int p = 0; p<4; p++){ // int p for player's guess
        for (int c=0; c<4; c++){ // int c for correct number
          if (p == c){
            if (playerGuess[p] == tgtNumStr[c]){ // if the # of the same position on each string matches
              bull ++;
            }
          }
        }
      }
      return bull;
    }

//---------------------------------------------------------------------------------------------------

/* Function: Checking number of hits
Name: hitCheck
Inputs: string playerGuess, string tgtNumStr
Inputs Meanings: playerGuess is the string of play'ers guess. tgtNumStr is the secret number generated 
            by the computer
Description: Checking for bulls:
            1. For each of the 4 #'s the user input, computer will run it through a for loop that checks the
               # against each of the 4 correct #
            2. If a number is in the correct place (bull), add 1 to bull counter
            3. If a number isn't in the correct place but is part of the correct combo, add 1 to hit counter 
               for every number that matches the correct combo
            Ex: 5151 (guess) x 1151 (correct) >> h=5, b=3 */
int hitCheck(string playerGuess, string tgtNumStr){
  int hit = 0; // hit counter
  int bull = 0; // bull counter
      for (int p = 0; p<4; p++){ // int p for player's guess
        for (int c=0; c<4; c++){ // int c for correct number
          if (p != c) {
            if (playerGuess[p] == tgtNumStr[c]){ // if the # of a different position matches
              hit ++;
            }
          }
        }
      }
      return hit;
    }

//---------------------------------------------------------------------------------------------------

/* Function: Computer is Teaser
Name: compTease() 
Input: none
Description: option 1 of the game where the computer tease player. Compuer will randomly 
            generate a number. User will take a guess. Computer will give a response of # of hits 
            and bulls. This will be in a loop until the 12th guess is over or the player have 
            guessed correctly. */
void compTease () {
  //int tgtNumInt = rand()%10000; // randomizer 0-9999. Genergate the secret number. Target number integer
  string tgtNumStr = "9676";//num2str(tgtNumInt); // turning target number integer into a string
  int guess = 0; // 1 means correct guess, 0 means incorrect
  int guessCount = 1; // for the purpose keeping track of # of guesses
  string playerGuess; // the number that the play guesses in string
  int hit = 0; // hit counter
  int bull = 0; // bull counter

  // loop of the entire game
  while (guess != 1){
    //cout << tgtNumStr;
    cout << "please enter your number: ";
    cin >> playerGuess;
    bull = bullCheck(playerGuess, tgtNumStr);
    hit = hitCheck(playerGuess, tgtNumStr);
    cout << "hit = " << hit; // displaying hit and bull
    cout << " bull = " << bull <<endl;
    if (bull == 4){ // use this to terminate loop - if player guesses correctly or if guesses exceeds 12
      guess = 1;
      cout << "You guessed correctly! - " << playerGuess << " is correct" << endl;
    } else if(guessCount == 12){
      guess =1;
      cout << " Number of guesses exceeds 12, restart game! " << endl;
    }
    hit = 0;
    bull = 0;
    guessCount ++;
  }
}
