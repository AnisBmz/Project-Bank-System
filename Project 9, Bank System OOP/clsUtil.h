#pragma once

#include <cstdlib>
#include "clsDate.h"
#include <iostream>
using namespace std;

class clsUtil
{

public:

	enum enCharacterType { CapitalLetter = 1, SmallLetter = 2, DigitLetter = 3, MixChar = 4};

	static void Srand() {

		srand((unsigned)time(NULL));

	}

	static int randomNumber(int from, int to) {

		return rand() % (to - from + 1) + from;

	}

	static char getRandomCharacter(enCharacterType characterType) {

		switch (characterType) {
		
		case CapitalLetter:
			return (char)randomNumber('A', 'Z');
			break;

		case SmallLetter:
			return (char)randomNumber('a', 'z');
			break;

		case DigitLetter:
			return (char)randomNumber('1', '9');
			break;

		case MixChar:
			return getRandomCharacter((enCharacterType)randomNumber(1, 3));
			break;
		
		}

	}

	static string generateWord(enCharacterType characterType, short wordLength) {

		string word = "";

		for (short i = 0; i < wordLength; i++)
		{

			word += getRandomCharacter(characterType);

		}

		return word;

	}

	static string generateKey(enCharacterType characterType, short wordLength = 4, short keyLength = 4) {

		string key = "";

		for (short i = 0; i < keyLength; i++)
		{

			key += generateWord(characterType, wordLength) + "-";

		}

		key.erase(key.length() - 1, 1);

		return key;
			
	}

	static void generateKeys(enCharacterType characterType, short numberOfKeys, short wordLength = 4, short keyLength = 4) {

		for (short i = 0; i < numberOfKeys; i++)
		{

			cout << generateKey(characterType, wordLength, keyLength) << endl;

		}

	}

	static void swap(int &a, int &b) {

		int temp = a;
		a = b;
		b = temp;

	}

	static void swap(float& a, float& b) {

		double temp = a;
		a = b;
		b = temp;

	}

	static void swap(double& a, double& b) {

		double temp = a;
		a = b;
		b = temp;

	}

	static void swap(string& a, string& b) {

		string temp = a;
		a = b;
		b = temp;

	}

	static void swap(clsDate& a, clsDate& b) {

		clsDate tempDate = a;
		a = b;
		b = tempDate;

	}

	static void shuffleArray(int arr[], int arrLength) {

		for (int i = 0; i < arrLength; i++)
		{
			swap(arr[randomNumber(1, arrLength) - 1], arr[randomNumber(1, arrLength) - 1]);
		}

	}

	static void shuffleArray(string arr[], int arrLength) {

		for (int i = 0; i < arrLength; i++)
		{
			swap(arr[randomNumber(1, arrLength) - 1], arr[randomNumber(1, arrLength) - 1]);
		}

	}

	static void fillArrayWithRandomNumber(int arr[], int arrLength, int from, int to){
	
		for (int i = 0; i < arrLength; i++)
		{

			arr[i] = randomNumber(from, to);

		}
	
	}

	static void fillArrayWithRandomWords(string arr[], int arrLength, enCharacterType characterType, short wordLength) {

		for (int i = 0; i < arrLength; i++)
		{

			arr[i] = generateWord(characterType, wordLength);

		}

	}

	static void fillArrayWithRandomKeys(string arr[], int arrLength, enCharacterType characterType, short wordLength = 4, short keyLength = 4) {

		for (int i = 0; i < arrLength; i++)
		{

			arr[i] = generateKey(characterType, wordLength, keyLength);

		}

	}

	static string encryptText(string text, short encryptionKey = 2) {

		for (int i = 0; i < text.length(); i++)
		{

			text[i] = char((int)text[i] + encryptionKey);


		}
		return text;
	}

	static string decryptText(string text, short encryptionKey= 2) {

		for (int i = 0; i < text.length(); i++)
		{

			text[i] = char((int)text[i] - encryptionKey);


		}
		return text;
	}

	static string numberToText(int number) {

		string arr[] = { "", "One", "Two", "Three", "Four", "Five","Six", "Seven", "Eight","Nine", "Ten", "Eleven", "Twelve",
						  "Thirteen", "Fourteen", "Fifteen", "Sixteen","Seventeen", "Eighteen", "Nineteen" };

		if (number == 0)
		{
			return "";
		}
		if (number >= 1 && number <= 19)
		{
			return arr[number];
		}
		if (number >= 20 && number <= 99)
		{
			string arr[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

			return arr[number / 10] + " " + numberToText(number % 10);

		}
		if (number >= 100 && number <= 199)
		{
			return "One Hundred " + numberToText(number % 100);

		}
		if (number >= 200 && number <= 999)
		{
			return numberToText(number / 100) + " Hundreds " + numberToText(number % 100);

		}
		if (number >= 1000 && number <= 1999)
		{
			return "One Thousand " + numberToText(number % 1000);

		}
		if (number >= 2000 && number <= 999999)
		{
			return numberToText(number / 1000) + " Thousands " + numberToText(number % 1000);

		}
		if (number >= 1000000 && number <= 1999999)
		{
			return  "One Million " + numberToText(number % 1000000);

		}
		if (number >= 2000000 && number <= 999999999)
		{
			return numberToText(number / 1000000) + " Millions " + numberToText(number % 1000000);

		}
		if (number >= 1000000000 && number <= 1999999999)
		{
			return "One Billion " + numberToText(number % 1000000000);

		}
		else
		{
			return numberToText(number / 1000000000) + " Billions " + numberToText(number % 1000000000);

		}


	}

	static string tabs_Space(short numberOfTabs, short numberOfSpaces = 0) {

		string sTabs_Spaces = "";

		for (int i = 0; i < numberOfTabs; i++)
		{

			sTabs_Spaces += "\t";

		}

		for (int i = 0; i < numberOfSpaces; i++)
		{

			sTabs_Spaces += " ";

		}

		return sTabs_Spaces;

	}

};

