/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw5_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw5_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */
// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw5_2.cpp
 * Abstract: Find the nearest directions on a map of vertexes
 * ID: 9190
 * Name: Reece Whitelaw 
 * Date: 03/03/2023
 */
#include <cmath>
#include <iostream>
#include <map>
#include <string>

using namespace std;

bool constraint(string num) {
	int len = num.length();
	for (int i = 0; i < len; i++) {
		char c = num[i];
		for (int x = i + 1; x < len; x++) {
			if (c == num[x]) {
				return false;
			}
		}
	}
	return true;
}

void combs(int size, int num, string array[], int &count) {
	int num_comb = pow(num, size);
	for (int i = 0; i < num_comb; i++) {
		string combination(size, '0');
		int temp = i;
		for (int x = size - 1; x >= 0; x--) {
			int remainder = temp % num;
			if (remainder < 10) {
				combination[x] = '0' + remainder;
			} else {
				combination[x] = 'A' + remainder - 10;
			}
			temp /= num;
		}
		if (constraint(combination)) {
			array[count] = combination;
			count++;
		}
	}
}

void flipArray(string arr[], int size) {
	for (int i = 0; i < size / 2; i++) {
		string temp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = temp;
	}
}

int correspond(string arr[], string vert, int vertsize) {
	// Vert is the vertices they pass as part of directions.
	// We're going to find what index it is at in our vertices array, and return
	// that index.
	for (int i = 0; i < vertsize; i++) {
		if (vert == arr[i]) {
			return i;
		}
	}
	return -1;
}

struct directlist {
	string value1;
	string value2;
	int value3;
};

void finale(
	string vertices[],
	string perms[],
	map<int, directlist> &directions,
	int vertsize,
	int count,
	int directnum) {
	int cost = -1;
	string printer = "";
	for (int x = 0; x < count; x++) {
		// Add the corresponding number of our beginning and end location to the
		// beginning and end of our permutation
		string permut =
			to_string(vertsize - 1) + perms[x] + to_string(vertsize - 1);

		// Array that iterates through our permutation
		for (int i = 0; i < permut.length() - 1; i++) {
			int origin = stoi(permut.substr(i, 1));
			int direction = stoi(permut.substr(i + 1, 1));

			for (int j = 0; j < directnum; j++) {
				if (directions[j].value1 == to_string(origin) &&
					directions[j].value2 == to_string(direction) &&
					(x + 1 == count)) {
					// If this is the last loop, it means these directions work
					// and are viable.
					cost = directions[j].value3;
					break;
				} else if (
					directions[j].value1 == to_string(origin) &&
					directions[j].value2 == to_string(direction)) {
					printer +=
						vertices[origin] + "->" + vertices[direction] + " ";
					break;
				}
			}
			if (i + 1 == permut.length() - 1) {
				break;
			}
		}

		if (cost != -1) {
			// If a viable direction was found in this permutation, print the
			// result and reset the cost and printer variables.
			cout << "Path: " << printer << " Cost: " << cost << endl;
			cost = -1;
			printer = "";
		}
	}
}

int main() {
	// Get the vertices
	int vertsize;
	cin >> vertsize;
	string vertices[vertsize];
	for (int i = 0; i < vertsize; i++) {
		cin >> vertices[i];
	}
	flipArray(vertices, vertsize);
	// Creating instructions Map
	int directnum;
	cin >> directnum;
	map<int, directlist> directions;
	for (int i = 0; i < directnum; i++) {
		string temp;
		cin >> temp;
		directions[i].value1 = correspond(vertices, temp, vertsize);
		cin >> temp;
		directions[i].value2 = correspond(vertices, temp, vertsize);
		int num;
		cin >> num;
		directions[i].value3 = num;
	}

	// Set up our list of possible permutations
	int permsize = pow(vertsize, vertsize);
	string permutations[permsize];
	int count = 0;
	combs(vertsize - 1, vertsize - 1, permutations, count);

	// Call a function that figures out what permutations are viable, and what
	// is cheapest.
	finale(vertices, permutations, directions, vertsize, count, directnum);

	return 0;
}
