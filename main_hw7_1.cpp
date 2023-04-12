/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw7_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw7_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw7_1.cpp
 * Abstract: Recursively, through divide and conquer, return the minimum value of an array
 * ID: 9190    
 * Name: Reece Whitelaw
 * Date: 03/24/2023
 */
//Base our own algorithm on the example algorithm
int min(int A[ ], int start, int end) 
{
    if (start == end) 
    {
        return A[start];
    }
    else 
    {
        int sum1 = min (A, start, (start+end)/2);
        int sum2 = min (A, (start+end)/2+1, end);
        if(sum1 < sum2){
            return sum1;
        }
        return(sum2);
    }
}
#include <iostream>
#include <map>
#include <string>
using namespace std;



int main() {
	int length;
    cin >> length;
    int array[length];
    
    for(int i = 0; i < length; i++){
        cin >> array[i];
    }
    //Recursively, through divide and conquer, find the smallest value.
    int mint = min(array, 0, length-1);
    cout << mint << "\n";
}
