/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw5_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw5_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw5_1.cpp
 * Abstract: Print the string in reverse, remove all trailing zeroes from original string
 * ID: 9190
 * Name: Reece Whitelaw
 * Date: 03/03/2023
 */

#include <iostream>
#include <string>

using namespace std;

bool nozero(string text, int textpos) {
    //Return true if nonzero character is found
    //Return false otherwise
    if (textpos == text.length()-1) {
        return false;
    }
    else if (text[textpos] == '0') {
        return nozero(text, textpos + 1);
    }
    else {
        return true;
    }
}

void recurstext(string text, int textpos){
    //Print the value held in textpos unless the value held in textpos == -1
    if(textpos == -1){
        return;
    }else{
        if(text[textpos] == '0'){
            if(nozero(text, textpos) == false){ 
                textpos--;
                recurstext(text, textpos);
            }
        }else{
            cout << text[textpos];
            textpos--;
            recurstext(text, textpos);
        }
    }
}

int main()
{
    string input;
    cin >> input;
    recurstext(input, input.length()-1);
    cout << "\n";
}

