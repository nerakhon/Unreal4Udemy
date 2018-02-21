#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame {
public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void IncrementTries(); // TODO remove once counting is implemented 
	void Reset(); // TODO make more rich return value
	bool CheckGuessValidity(FString); // TODO make more rich return value
	// TODO provide a method for counting bulls and cows and increasing try number


private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
};