#include "BullCowGame.h"

#include <map>
// NOTE #define will cut and paste TMap wherever std::map is written.
#define TMap std::map


BullCowGame::BullCowGame()
{
	Reset();
}

BullCowGame::~BullCowGame()
{
}


void BullCowGame::Reset()
{
	// NOTE This expression will be evaluated at compile time and cannot change.
	const FString HIDDEN_WORD{ "planet" };

	m_IsGameWon = false;
	m_CurrentTry = 1;
	m_HiddenWord = HIDDEN_WORD;
}

int32 BullCowGame::GetMaxTries() const
{
	return GetHiddenWordLength() > m_minimumTries ? GetHiddenWordLength() : m_minimumTries;
}

GuessStatus BullCowGame::IsGuessValid(FString guess) const
{
	if (!IsIsogram(guess))
		return GuessStatus::NOT_ISOGRAM;
	else if (!IsLowerCase(guess))
		return GuessStatus::NOT_LOWERCASE;
	if (!IsCorrectLength(guess))
		return GuessStatus::WRONG_LENGTH;
	else
		return GuessStatus::OK;
	
}

bool BullCowGame::IsCorrectLength(FString guess) const
{
	return guess.length() == GetHiddenWordLength();
}

bool BullCowGame::IsLowerCase(FString guess) const
{
	for (auto letter : guess)
		if (!islower(letter))
			return false;
	return true;
}

bool BullCowGame::IsIsogram(FString guess) const
{
	TMap<char, bool> letterSeen;

	// NOTE C++ syntax for foreach loop i.e. range based for loop
	// NOTE auto automatically figures out type from right hand value
	for (auto letter : guess)
		if (letterSeen.count(tolower(letter)) > 0)
			return false;
		else
			letterSeen[letter] = true;
	return true;
}


BullCowCount BullCowGame::SubmitValidGuess(FString guess)
{
	IncrementTry();
	BullCowCount bullCowCount;
	
	for (int32 hiddenWordIndex = 0; hiddenWordIndex < GetHiddenWordLength(); hiddenWordIndex++)
		for (int32 guessIndex = 0; guessIndex < GetHiddenWordLength(); guessIndex++)
			if (m_HiddenWord[hiddenWordIndex] == guess[guessIndex])
				if (guessIndex == hiddenWordIndex)
					bullCowCount.Bulls++;
				else
					bullCowCount.Cows++;
	
	m_IsGameWon = bullCowCount.Bulls == GetHiddenWordLength();

	return bullCowCount;
}
