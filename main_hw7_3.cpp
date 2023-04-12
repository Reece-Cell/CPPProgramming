/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw7_3.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw7_3.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw7_3.cpp
 * Abstract: Sort an array's negative and positive values through two different swapping methods
 * ID: 9190
 * Name: Reece Whitelaw
 * Date: 03/24/2023
 */

#include <iostream>
using namespace std;

int main() {
	int length;
	cin >> length;
	int array[length];
	int array2[length];
	// METHOD 1, Index i and j on opposing sides
	for (int i = 0; i < length; i++) {
		cin >> array[i];
		array2[i] = array[i];
	}

	// This logic will sort from both sides towards the middle, eventually
	// breaking.
	/*for (int i = 0; i < length; i++) {
		if (i > length - i - 1) {
			break;
		} else if (i == length - i - 1) {
			cout << " :i: ";
			cout << array[i];
			break;
		} else {
			cout << " :x: ";
			cout << array[i] << " " << array[length - i - 1] << " ";
		}
	}*/
	int j = length - 1;
	bool swapper = false;
	int temp;
	for (int i = 0; i < length; i++) {
		// First, we iterate through the array[] until i finds a positive
		// number. Check value of index i
		if (array[i] > 0) {
			for (; j > i; j--) {
				// Iterate down through the area until j > i.
				// Break this loop and set swapper to true if j finds a negative
				// number
				if (array[j] < 0) {
					swapper = true;
					break;
				}
			}
		}
		// Swap values if swapper is true;
		if (swapper == true) {
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			swapper = false;
		}
		if (j <= i) {
			break;
		}
	}
	for (int i = 0; i < length; i++) {
		if (i == 0) {
			cout << array[i];
		} else {
			cout << " " << array[i];
		}
	}

	// VERSION TWO. INDEXES STARTING AT THE OPPOSITE END
	// X shall hold position. j shall be our scout. Together, they shall get us
	// an A.
	j = length - 1;
	int x = length - 1;
	swapper = false;
	for (; j >= 0; j--) {
		// j must first find a negative number to hold
		if (array2[j] < 0) {
			// We have found a negative number. Scan ahead for the next positive
			// number and then switch.
			x = j;
			for (; x >= 0; x--) {
				if (array2[x] > 0) {
					// We have found the positive number. Switch them out
					// then break
					temp = array2[j];
					array2[j] = array2[x];
					array2[x] = temp;
					break;
				}
			}
		}
	}
	cout << "\n";
	for (int i = 0; i < length; i++) {
		if (i == 0) {
			cout << array2[i];
		} else {
			cout << " " << array2[i];
		}
	}
    cout << "\n";
}
