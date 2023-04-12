/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw7_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw7_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw7_2.cpp
 * Abstract: Check if two inputs are anagrams. If so, print the number of letters present.
 * ID: 9190
 * Name: Reece Whitelaw
 * Date: 03/24/2023
 */
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	string word1;
	string word2;
	cin >> word1;
	cin >> word2;
	map<char, int> word1letters;
	map<char, int> word2letters;
	bool matching = true;
	char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
						 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
						 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

	for (int i = 0; i < 26; i++) {
		word1letters[alphabet[i]] = 0;
		word2letters[alphabet[i]] = 0;
	}
	// Increase values based on the chars in word1
	for (int i = 0; i < word1.size(); i++) {
		word1letters[word1[i]]++;
	}
	for (int i = 0; i < word1.size(); i++) {
		word2letters[word2[i]]++;
	}
	// Compare each value. If they ever don't match, it sets to false and prints
	// NO ANAGRAM
	for (int i = 0; i < 26; i++) {
		if (word1letters[alphabet[i]] != word2letters[alphabet[i]]) {
			matching = false;
			break;
		}
	}
	if (matching == true) {
		cout << "ANAGRAM\n";
		for (int i = 0; i < 26; i++) {
			if (word1letters[alphabet[i]] > 0) {
				cout << alphabet[i] << ":" << word1letters[alphabet[i]] << "\n";
			}
		}
        return 0;
	}else{
        cout << "NO ANAGRAM\n";
        return 0;
    }
}
