/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw2_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw2_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw2_2.cpp
 * Abstract: Show all possible combinations of a provided set
 * ID: 9190
 * Name: Reece Whitelaw
 * Date: 02/10/2023
 */
#include <iostream>
#include<cmath>

using namespace std;

void eleprint(int pos, int print[], int size){
    if(print[pos] == 1){
        cout << print[pos];
    }else{
        cout << "0";
    }
    return;
}

void combprint(int num_comb, int print[], int size, string elements[]){
    int count = 0;
    for (int i = 0; i < num_comb; i++) {
        int temp = i;
        for (int x = 0; x < size; x++) {
            print[x] = temp % 2;
            temp /= 2;
        }
        cout << count <<":";
        for (int x = size - 1; x >= 0; x--) {
            cout << print[x];
        }
        cout << ":";
        int spacer = 0;
        int emptrack = 0;
        for (int x = size - 1; x >= 0; x--) {
            if(print[x] == 1 && size != 0 && spacer == 0){
                cout << elements[x];
                spacer++;
                emptrack++;
            }else if(print[x] == 1 && size != 0){
                cout << " " << elements[x];
                emptrack++;
            }
        }
        if(emptrack == 0){
            cout << "EMPTY";
        }        
        count ++;
        cout << "\n";
    }
}

int main() {
    int size;
    cin >> size;
    //Get values
    string elements[size];
    for(int i = size - 1; i >= 0; i--){
        cin >> elements[i];
    }
    //Declare array to print combos
    int print[size];
    int num_comb = pow(2, size);
    //Organize all possible combinations
    if(size == 0){
        cout << "0:0:EMPTY\n";
        }else{
        combprint(num_comb, print, size, elements);
        }
  return 0;
}
