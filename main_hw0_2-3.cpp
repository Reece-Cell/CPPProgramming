/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw0_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw0_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw0_2.cpp
 * Abstract: Calculate the mix/max/median of five provided numbers.
 * ID: 9190
 * Name: Reece Whitelaw
 * Date: 01/27/2023
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Your code should be here.
    // The following is a just sample statement.
    int x1, x2, x3, x4, x5;
    int min, max, median;
    cin >> x1;
    cin >> x2;
    cin >> x3;
    cin >> x4;
    cin >> x5;
    int arr[5] = {x1,x2,x3,x4,x5};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    cout << "MIN:" << arr[0] << "\nMAX:" << arr[4] << "\nMEDIAN:" << arr[2] << "\n";
}

