#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int main() {
	srand(time(NULL));
	int tries = 0;
	cout << "Welcome to the Game 'Hangman'!"<<endl<<"You have 8 attempts to make a mistake"<<endl;
	vector<string> words = { "place","ball","football","phone","lamp","blender","school","university" };
	int word_num = rand() % words.size();
	string word;
	while (word.size() != words[word_num].size()) {
		word.push_back('_');
	}
	char letter;
	int right = 0;
	while (tries < 8) {
		cout << "Enter a letter: ";
		cin >> letter;
		bool isit = false;
		for (int i = 0;i < word.size();++i) {
			if (words[word_num][i] == letter) {
				word[i] = letter;
				isit = true;
				++right;
				if (right == words[word_num].size()) {
					
					break;
				}
			}
		}
		if (isit == true) {
			if (right == words[word_num].size()) {
				cout << "Well done! The word is " << words[word_num];
				break;
			}
			cout << "You are right! Now you have: " << word<< endl;
		}
		else {
			++tries;
			if (tries == 8) {
				break;
			}
			cout << "No! A Big mistake! You have " << tries << " mistakes..."<<endl;
		}
	}
	if (tries == 8) {
		cout << "You are a looser!";
	}
}