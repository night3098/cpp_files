/*	Guess game	*/

#include <clocale>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	
	const int MAX_WRONG = 5;
	int i = 0;
	int y = 0;

	vector<string> words;

	words.push_back("wrinkless");
	words.push_back("scissors");
	words.push_back("mustache");
	words.push_back("head");
	words.push_back("mouth");
	words.push_back("leg");
	words.push_back("hand");
	words.push_back("hairdress");
	words.push_back("eye");
	words.push_back("ear");
	words.push_back("limp");

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());

	string WORD = words[1];
	//cout << WORD << endl;

	string soFar(WORD.size(), '_');
	//cout << soFar;

	int wrong = 0;
	string used = "";
	cout << "Welcome. Guess the word. You have 5 attempts." << endl;

	while ((wrong < MAX_WRONG) && (soFar != WORD)) {
		cout << "You can allow " << (MAX_WRONG - wrong) << "errors." << endl;
		cout << "You used the following letters: " << used << endl;
		cout << "So far, the word is:\n" << soFar << endl;

		char guess;
		cout << "Enter the letter: " << soFar << endl;
		cin >> guess;

		while ((used.find(guess) != string::npos) && (used.find(guess) > 5)) {
			cout << "This letter has already been used. [o]: " << guess << endl;
			cout << "Letter: " << soFar << endl;
			cin >> guess;
		}
		used += guess;
		
		if (WORD.find(guess) != string::npos){
			cout << "Greate" << endl;
			for (int i = 0; i < WORD.length(); i++){
				if(WORD[i] == guess){
					soFar[i] = guess;	
				}
			}
		}
		else {
			cout << "Soryy, [" << guess << "] - this letter isn't in this word...." << endl;
			wrong ++;
		}
	}

	if (wrong == MAX_WRONG) {
		cout << "You lose)))))" << endl;
	}
	else {
		cout << "You win" << endl;
	}
	cout << WORD << endl;
	return 0;
}
