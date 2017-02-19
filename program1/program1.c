/*  Atta Saleh
 *  COP2220
 *  program1.c
 *	A quick letter guessing game that gives the user 5 chances
 *	at guessing a letter that is read from a file each game
 *	User defined functions used to make it look cleaner altogether
 *  2/18/2017
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#define MAXGUESSES 5

//this function provides instructions to the user on how to play the game
void GameRules(void);

//runs one game and calls other functions within it
//uses letter from file as an argument 
//gets guess using the GetGuess() function 
//checks for win using the CompareCharacters() function
void PlayOneRound(char letter); 

//called inside PlayOneRound(); 
//Prompts player for a guess and returns it
char GetGuess(void);			
								
//compares input from the player to the letter from file
//returns 1 if they match, 0 if they don't
//gives the user hints based on their guess
int CompareCharacters(char letter, char guess); 


int main()
{
	FILE *answers;							//file pointer

	int games, i; 							//number of games and i to iterate through array 
											//of letters in file
	char letter;							//letter from file

	GameRules();							//game rules 

	answers = fopen("letters.txt", "r");	//connect to file

	printf("How many games would you like to play? (1-10) ");  	//ask user for # of games
	
	scanf("%d", &games);										//recieves input

	for(i = 0; i < games; i++)
	{
		fscanf(answers, " %c", &letter); 	//reads solution letter from file

		letter = toupper(letter);			//changes letter from file to uppercase

		printf("\n***********************************************\n");

		printf("\nReady to play game %d\n",i+1);

		PlayOneRound(letter);
	}

	printf("\nThank you for playing the Letter Guessing Game!\n");
    fclose(answers);
	return 0;
}

void GameRules()
{
	printf("\nWelcome to the Letter Guessing Game\n");
	printf("\nFirst, you will enter the number of games you want to play (1 - 10 games)\n");
	printf("\nFor each game you will have 5 chances to guess each letter\n");
	printf("\nLet's begin:\n\n");
}

void PlayOneRound(char letter)
{
	int win = 0;
	int numGuesses = 0;
	while(numGuesses<MAXGUESSES && win==0)				//game ends if win = 1 or 5 guesses are made
	{
        printf("\n----------------------------------------\n");
        printf("\nGetting guess number %d\n", numGuesses+1);
		char guess = GetGuess();					//sets guess to capitalized user input
		win = CompareCharacters(letter, guess);		//sets win=1 if characters match	
		numGuesses++;
	}
	if(win==1)
	{
		printf("\nCongratulations! You won!\n");	//congratulates the user if they win
	}
	else											//Apologizes if they lose :(
	{
		printf("\nSorry, you didn't win this round.\n\nThe letter was %c\n", letter); 
	}
}

char GetGuess()
{
	char guess;
	printf("\nPlease enter a guess: ");
	scanf(" %c", &guess);										//gets guess from user and 
	guess = toupper(guess);										//makes it uppercase
	return guess;												//returns guess
}

int CompareCharacters(char letter, char guess)
{
	if(guess<letter)
	{
		printf("\nThe solution comes after your guess (%c)\n", guess);
		return 0;
	}
	else if(guess>letter)											//hints for the user if the
	{																//guess doesn't match, returns 0
		printf("\nThe solution comes before your guess (%c)\n", guess);
		return 0;
	}
	else
	{																//If they match, returns 1
		printf("\nThe solution and the guess are the same (%c)\n", guess);
		return 1;
	}
}







