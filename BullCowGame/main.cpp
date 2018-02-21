/* This is the console executable making use of the BullCow class
acts as view in MVC and is responsible for all user interaction.
For game logic check FBUllCowGame class
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// the entry point of application
int main()
{
	do
	{
		PrintIntro();
		PlayGame();
	}
	while (AskToPlayAgain());
	return 0; // exit application
}


// introduce the game
void PrintIntro()
{
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}


void PlayGame()
{
	// loop for the number of turns asking for guesses
	//TODO move to while loop once validation is present
	for (int32 i = 1; i <= BCGame.GetMaxTries(); i++)
	{
		FText Guess = GetGuess(); // TODO make check valid guesses

		// submit guess to the game
		// print number of Bulls and Cows
		std::cout << "You guessed: " << Guess << std::endl;
		std::cout << std::endl;
		BCGame.IncrementTries();
	}
	// TODO summarize game
}


FText GetGuess()
{
	// get a guess from player
	FText Guess = "";
	std::cout << "Try " << BCGame.GetCurrentTry() << ".Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	FText Response = "";
	std::cout << "Do you want to play again? (y/n) ";
	std::getline(std::cin, Response);
	std::cout << std::endl;
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
