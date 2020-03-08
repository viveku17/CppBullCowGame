// NOTE Only includes this header file once. (In the event this header file is called more than once)
#pragma once

#include "BullCowGame.h"

// NOTE FText is mutable string in Unreal
// NOTE using typename = typename is called type aliassing
using FText = std::string;

using int32 = int;

// NOTE Forward declarations
void PrintIntro();
FText GetGuess();
FText GetValidGuess();
void PrintGuess(FText Guess);
void PrintGameSummary();
void PlayGame();
bool AskToPlayAgain();
BullCowGame Game;
