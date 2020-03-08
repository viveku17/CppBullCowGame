/* 
#include is a preprocessor directive that tells the compiler to cut and paste the contents of file within the angular brackets in place 
 of the preprocessor directive.

 Angular brackets are used for files which come with the compiler.
 Quotes are used for files written by the user.
*/
#include <iostream>
#include <string>
#include "main.h"

/* NOTE namespaces group together common code. 
In order to use something in a namespace it must be either 
	- prefixed by the namespace followed by two colons e.g. std:: (preferred as this is more explicit) OR 
	- the namespace must be referenced at the top of the file e.g. using namespace std;
*/ 
// using namespace std;

// NOTE entry point for all C++ application (int main() {})
int main() 
{	
	do 
	{
		std::cout << Game.GetMaxTries();
		Game.Reset();
		std::cout << Game.GetMaxTries();
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());
		
	// NOTE The compiler automatically returns 0 for main function
	// return 0;
}	

void PrintIntro()
{

	std::cout << "Welcome to Bulls and Cows, a fun word game\n";
	std::cout << "          .=     ,        =.\n";
	std::cout << "         /'/    )\\,/,/(_   \\ \\\n";
	std::cout << "        |  (  ,\\\\)\\//\\)\\/_  ) |\n";
	std::cout << "     ___\\   `\\\\\\/\\\\/\\/\\\\///'  /\n";
	std::cout << ",-\"~`-._ `\"--'_   `\"\"\"`  _ \\`'\"~-,_\n";
	std::cout << "\\       `-.  '_`.      .'_` \\ ,-\"~`/\n";
	std::cout << " `.__.-'`/   (-\\        /-) |-.__,'\n";
	std::cout << "        |     \\O)  /^\\ (O/  |\n";
	std::cout << "          |         /   `\\  |  \n";
	std::cout << "           \\       /      `\\| \n";
	std::cout << "            `-.  /' .---.--.\\\n";
	std::cout << "              `~(, '()      ('\n";
	std::cout << "                \\   _,.-.,_)\n";
	std::cout << "                 `--'`       \n";
	std::cout << "Can you guess the " << Game.GetHiddenWordLength() << " letter isogram I'm thinking off?\n\n";
}

void PlayGame()
{	
	BullCowCount bullCowCount;

	while (Game.GetCurrentTry() <= Game.GetMaxTries() && !Game.IsGameWon())
	{
		FText guess = GetValidGuess();
		bullCowCount = Game.SubmitValidGuess(guess);
		std::cout << "Bulls = " << bullCowCount.Bulls << ". Cows = " << bullCowCount.Cows << "\n";
		std::cout << "\n";
	}
	PrintGameSummary();
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? ";
	FText Response{ "" };
	std::getline(std::cin, Response);
	char response{ Response[0] };
	return (response == 'y' || response == 'Y');
}

FText GetGuess()
{
	std::cout << "Try " << Game.GetCurrentTry() << " of " << Game.GetMaxTries() << ". Enter your guess: ";
	FText guess = "";
	std::getline(std::cin, guess);
	PrintGuess(guess);
	return guess;
}

FText GetValidGuess()
{
	FText guess = "";
	auto guessValidity = GuessStatus::INVALID;
	do 
	{
		guess = GetGuess();
		guessValidity = Game.IsGuessValid(guess);

		switch (guessValidity)
		{
			case GuessStatus::WRONG_LENGTH:
				std::cout << "Your guess is not a " << Game.GetHiddenWordLength() << " letter isogram.\n";
				break;
			case GuessStatus::NOT_LOWERCASE:
				std::cout << "Please enter lowercase characters.\n";
				break;
			case GuessStatus::NOT_ISOGRAM:
				std::cout << "Your guess is not an isogram.\n";
				break;
			default:
				break;
		}

		if (guessValidity != GuessStatus::OK)
			std::cout << "\n";

	} while (guessValidity != GuessStatus::OK);


	return guess;
}

void PrintGameSummary()
{
	std::cout << (Game.IsGameWon() ? "Congratulations you won the game!" : "You lost the game!");
	std::cout << "\n\n";
}

void PrintGuess(FText Guess)
{
	std::cout << "Your guess was: " << Guess << "\n";
}