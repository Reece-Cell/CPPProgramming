/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw0_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw0_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw0_1.cpp
 * Abstract: Calculate the sums and differences between two numbers, excluding negative numbers.
 * ID: 9190
 * Name: Reece Whitelaw
 * Date: 01/27/2023
 */

#include <iostream>
using namespace std;

int main()
{
    // Your code should be here.
    // The following is a just sample statement.
    int x;
    int y;
    cin >> x;
    cin >> y;
    int diff = (x - y);
    if((x-y)<0){
      diff = diff * -1;
    }
    cout << "SUM:" << (x + y) << "\n" << "DIFF:" << diff << "\n";
}

