#pragma once
#include <iostream>
#include <vector>

using namespace std;

class clsString
{
private:

	string _Value;

public:

	clsString() {

		_Value = "";

	}

	clsString(string value) {

		_Value = value;

	}

	void setValue(string value) {

		_Value = value;

	}

	string getValue() {

		return _Value;

	}

	__declspec (property (get = getValue, put = setValue)) string value;

	static short length(string S1) {

		return S1.length();

	}

	short length() {

		return _Value.length();

	}

	static short countWords(string S1) {

		string word = "";
		string delim = " ";
		short pos = S1.find(delim);
		short counter = 0;

		while (pos != string::npos) {

			word = S1.substr(0, pos);

			if (!word.empty())
			{
				counter++;
			}

			S1.erase(0, pos + delim.length());
			pos = S1.find(delim);

		}

		if (!S1.empty())
		{
			counter++;
		}

		return counter;

	}

	short countWords() {

		return countWords(_Value);

	}

	static void printFirstLetterOfEachWord(string S1) {

		cout << "First Letter of each word in this string:\n";

		bool isFirstLetter = true;

		for (int i = 0; i < S1.length(); i++)
		{

			if (S1[i] != ' ' && isFirstLetter)
			{

				cout << S1[i] << endl;

			}

			isFirstLetter = (S1[i] == ' ' ? true : false);

		}

	}

	void printFirstLetterOfEachWord() {

		printFirstLetterOfEachWord(_Value);

	}

	static string upperFirstLetterOfEachWord(string S1) {

		bool isFirstLetter = true;

		for (int i = 0; i < S1.length(); i++)
		{

			if (S1[i] != ' ' && isFirstLetter)
			{

				S1[i] = toupper(S1[i]);

			}

			isFirstLetter = (S1[i] == ' ' ? true : false);

		}

		return S1;

	}

	void upperFirstLetterOfEachWord() {

		_Value = upperFirstLetterOfEachWord(_Value);

	}

	static string lowerFirstLetterOfEachWord(string S1) {

		bool isFirstLetter = true;

		for (int i = 0; i < S1.length(); i++)
		{

			if (S1[i] != ' ' && isFirstLetter)
			{

				S1[i] = tolower(S1[i]);

			}

			isFirstLetter = (S1[i] == ' ' ? true : false);

		}

		return S1;

	}

	void lowerFirstLetterOfEachWord() {

		_Value =  lowerFirstLetterOfEachWord(_Value);

	}

	static string upperAllString(string S1) {

		for (int i = 0; i < S1.length(); i++)
		{

			S1[i] = toupper(S1[i]);

		}
		
		return S1;

	}

	void upperAllString() {

		_Value =  upperAllString(_Value);

	}

	static string lowerAllString(string S1) {

		for (int i = 0; i < S1.length(); i++)
		{

			S1[i] = tolower(S1[i]);

		}

		return S1;

	}

	void lowerAllString() {

		_Value = lowerAllString(_Value);

	}

	static char invertLetterCase(char letter) {

		return isupper(letter) ? tolower(letter) : toupper(letter);

	}

	static string invertAllStringLetterCase(string S1) {

		for (int i = 0; i < S1.length(); i++)
		{

			S1[i] = clsString::invertLetterCase(S1[i]);

		}

		return S1;

	}

	void invertAllStringLetterCase() {

		_Value =  invertAllStringLetterCase(_Value);

	}

	enum enWhatCount {SmallLetter = 1, CapitalLetter = 2, All = 3};

	static short countLetter(string S1, enWhatCount whatCount = enWhatCount::All) {

		short counter = 0;

		for (int i = 0; i < S1.length(); i++)
		{

			switch (whatCount) {
			
			case enWhatCount::All:
				counter++;
				break;
			case enWhatCount::CapitalLetter:
				if (isupper(S1[i]))
				{
					counter++;
				}
				break;
			case enWhatCount::SmallLetter:
				if (islower(S1[i]))
				{
					counter++;
				}
				break;

			}

		}

		return counter;

	}

	short countLetter(enWhatCount whatCount = enWhatCount::All) {

		return countLetter(_Value, whatCount);

	}

	static short countSmallLetters(string S1) {

		short counter = 0;

		for (int i = 0; i < S1.length(); i++)
		{

			if(islower(S1[i])) 
				counter++;

		}

		return counter;

	}

	short countSmallLetters() {

		return countSmallLetters(_Value);

	}

	static short countCapitalLetters(string S1) {

		short counter = 0;

		for (int i = 0; i < S1.length(); i++)
		{

			if (isupper(S1[i])) 
				counter++;

		}

		return counter;

	}

	short countCapitalLetters() {

		return countCapitalLetters(_Value);

	}

	static short countSpecificLetter(string S1, char letter, bool matchCase = true) {

		short counter = 0;

		for (int i = 0; i < S1.length(); i++)
		{

			if (matchCase)
			{

				if (S1[i] == letter)
					counter++;

			}
			else {

				if (toupper(S1[i]) == toupper(letter))
					counter++;

			}


		}

		return counter;

	}

	short countSpecificLetter(char letter, bool matchCase = true) {

		return countSpecificLetter(_Value, letter, matchCase);

	}

	static bool isVowel(char letter) {

		letter = tolower(letter);

		return (letter) == 'a' || (letter) == 'i' || (letter) == 'u' || (letter) == 'o' || (letter) == 'e';

	}

	static short countVowels(string S1) {

		short counter = 0;

		for (int i = 0; i < S1.length(); i++)
		{

			if (clsString::isVowel(S1[i]))
			{

				counter++;

			}

		}

		return counter;

	}

	short countVowels() {

		return countVowels(_Value);

	}

	static vector <string> split(string S1, string delim = " ") {

		vector<string> vString;
		string word = "";
		short pos = S1.find(delim);

		while (pos != string::npos) {

			word = S1.substr(0, pos);

			if (!word.empty())
			{
				vString.push_back(word);
			}

			S1.erase(0, pos + delim.length());
			pos = S1.find(delim);

		}

		if (!S1.empty())
		{
			vString.push_back(S1);

		}

		return vString;

	}

	vector <string> split(string delim = " ") {

		return split(_Value, delim);

	}

	static string trimLeft(string S1) {


		for (int i = 0; i < S1.length(); i++)
		{
			
			if (S1[i] != ' ')
			{

				return S1.substr(i, S1.length() - i);

			}

		}

	}

	string trimLeft() {

		return trimLeft(_Value);

	}

	static string trimRight(string S1) {


		for (int i = S1.length() - 1; i >= 0; i--)
		{

			if (S1[i] != ' ')
			{

				return S1.substr(0, i + 1);

			}

		}

	}

	string trimRight() {

		return trimRight(_Value);

	}

	static string trim(string S1) {

		return trimRight(trimLeft(S1));

	}

	string trim() {

		return trim(_Value);

	}

	static string joinString( vector <string> vString, string delim = " ") {

		string S1 = "";

		for (string& word : vString) {

			S1 += word + delim;

		}

		return S1.substr(0, S1.length() - delim.length());

	}

	static string joinString( string arrString [], short arrLength,  string delim = " ") {

		string S1 = "";

		for (int i = 0; i < arrLength; i++)
		{

			S1 += arrString[i] + delim;

		}

		return S1.substr(0, S1.length() - delim.length());

	}

	static string reverseWordsInString(string S1, string delim = " ") {

		vector <string> vString = clsString::split(S1, " ");
		string result = "";

		for (int i = vString.size() - 1; i >= 0; i--)
		{

			result += vString[i] + delim;

		}

		return result;

	}

	void reverseWordsInString() {

		_Value =  reverseWordsInString(_Value);

	}

	static string replaceWord(string S1, string stringToReplace, string replaceTo, bool matchCase = true) {

		vector <string> vString = clsString::split(S1, " ");

		for (string& word : vString) {

			if (matchCase)
			{
				if (word == stringToReplace)
				{
					word = replaceTo;
				}
			}
			else {

				if (lowerAllString(word) == lowerAllString(stringToReplace))
				{
					word = replaceTo;
				}

			}

		}

		return joinString(vString);

	}

	void replaceWord(string stringToReplace, string replaceTo, bool matchCase = true) {

		_Value = replaceWord(_Value, stringToReplace, replaceTo, matchCase);

	}

	static string replaceWordInString(string S1, string stringToReplace, string sReplaceTo) {

		short pos = S1.find(stringToReplace);

		while (pos != string::npos) {

			S1 = S1.replace(pos, stringToReplace.length(), sReplaceTo);

			pos = S1.find(stringToReplace);


		}
		return S1;
	}

	static string removePunctuations(string S1) {

		string result = "";

		for (int i = 0; i < S1.length(); i++)
		{

			if (!ispunct(S1[i]))
			{
				result += S1[i];
			}

		}

		return result;

	}

	void removePunctuations() {

		_Value = removePunctuations(_Value);

	}

};

