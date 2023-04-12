/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw4_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw4_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw4_1.cpp
 * Abstract: Print an array while representing iterative values as n-n+1
 * ID: 9190
 * Name: Reece Whitelaw
 * Date: 2/23/2023
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // Your code should be here.
    // The following is a just sample statement.
    int count;
    cin >> count;
    int arr[count];
    for(int i = 0; i < count; i++){
        cin >> arr[i];
    }
    int size = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + count);
    
    for(int i = 0; i < count; i++){
        if(arr[i+1] == arr[i]+1){
            //If the next value equals the current value + 1
            cout << arr[i] << "-";
            for(int x = i+1; x < count; x++){
                if(arr[x+1] != arr[x]+1){
                    i = x;
                if(x+1 == count){
                    cout << arr[x];
                }else{
                    cout << arr[x] << " ";
                }
                        break;
                }
            }
        }else{
            if(i+1 == count){
                cout << arr[i];
            }else{
            cout << arr[i] << " ";
            }
        }
    }
    cout << "\n";
    return 0;
}

