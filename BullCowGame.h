#pragma once

#include <string>

// NOTE FString is for output text in unreal
using FString = std::string;


using int32 = int;

// NOTE Structs are classes which have public members by default.
struct BullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

/* NOTE enums are enumerated value lists e.g. OK=1, NOT_ISOGRAM=2
   Enums can be accessed using same syntax as namespace access ENUM::VALUE
   All values are avilable in public scope
*/
enum GuessStatus
{
	INVALID,
	OK,
	NOT_ISOGRAM,
	WRONG_LENGTH,
	NOT_LOWERCASE
};

// NOTE enum classes have scope. all values are only available within scope of enum class. 
enum class ResetStatus
{
	NO_HIDDEN_WORD,
	OK
};

class BullCowGame
{
public:
	BullCowGame();
	~BullCowGame();
	
	/* NOTE const after function name prevents modification of member variables. 
		- This only works for member functions.
		- Always use const after function name for getters
	*/

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const { return m_CurrentTry; }
	int32 GetHiddenWordLength() const { return m_HiddenWord.length(); }

	bool IsGameWon() const { return m_IsGameWon; }
	GuessStatus IsGuessValid(FString guess) const;
	bool IsCorrectLength(FString guess) const;
	bool IsLowerCase(FString guess) const;
	bool IsIsogram(FString guess) const;

	BullCowCount SubmitValidGuess(FString guess);

	void Reset();
	void IncrementTry() { m_CurrentTry += 1; }


private:
	bool m_IsGameWon{ false };
	int32 m_CurrentTry{ 0 };
	FString m_HiddenWord{ "" };
	int m_minimumTries = 5;
};

