# Numbo - DESCRIPTION
This is a guessing game. The goal is to guess the correct 4 numbers that are randomly generated. There are 2 modes: Player Guess and Computer Guess. Unfortunately, the computer guess algorithm has not been completed, so the code in this project will only support the option for the Player to guess. 

During each round, a 4-numbers sequence will be randomly generated in order and the player must guess what they are by making 12 or fewer guesses. Each guess, the "teaser" (or the person generating the random number) will return the numbers of "hit" and "bull" that provide the player with clues to guessing the numbers. A "hit" is when one of the guessed numbers exists in the correct sequence but it doesn't exist in the right place. For every one of these occurrence, it counts as one hit. So if the correct sequence is 6060 and the guess is 1116, there would be 2 hits. A "bull" is when the number is in the correct place in the correct sequence. So if the correct sequence is 0100 and the guess is 5167, since 1 is in the right place, there is 1 bull returned. 

More examples:

   "Correct Sequence"   "Guess"   "Hit"   "Bull" 
   
      0334            3312     3     1
      9676            6677     4     2

# GAME OUTPUT DEMO
![image](https://github.com/lenduong/Numbo/assets/141017307/9c101d69-19a9-47a8-9f8a-aa2360416fca)

# STRATEGY FOR COMPUTER TO GUESS

![image](https://github.com/lenduong/Numbo/assets/141017307/31cf11d8-b1d8-4a23-9386-aece5b0a088f)

