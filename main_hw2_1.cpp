/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw2_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw2_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw2_1.cpp
 * Abstract: Determine if an input string is a palindrom while ignoring alphanumeric numbers and printing the first difference (as an uppercase number when able)
 * ID: 9190
 * Name: Reece Whitelaw
 * Date: 02/09/2023
 */

#include <cctype>
#include <iostream>
#include <cctype>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

int main() {
	// Your code should be here.
	// The following is a just sample statement.
	string palindrome;
    cin >> palindrome;
    string check[201];
    int size = 0;
    for(int i = 0; i < palindrome.length(); i++){
        if(iswalnum(palindrome[i]) != 0){
            //Substring is valid
            check[size] = tolower(palindrome[i]);
            size++;
        }
    }

    for(int i = 0; i < size; i++){
        if(check[i] != check[size - i - 1]){
            //Not a palindrome
            string input = check[i];
            if(isdigit(input[i]) == 0){
                //Not a number
                cout << "NO:" << char(toupper(input[0])) <<"\n";
                break;
            }else{
            //Is a number
            cout << "NO:" << input <<"\n";
            break;   
            }
        }
        if(i + 1 == size){
            cout << "PALINDROME\n";
        }
    }
	return 0;
}
