/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw3_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw3_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw3_2.cpp
 * Abstract: Given times, find the max amount of possible events.
 * ID: 9190
 * Name: Reece Whitelaw
 * Date: 02/17/2023
 */

#include <iostream>
using namespace std;

int count(int time, int arr[], int sched){
    int count = 0;
    for(int i = 0; i < sched; i += 2){
        if(time >= arr[i] && time <= arr[i+1]){
            count++;
        }
    }
    return count;
}

int main()
{
    int size;
    cin >> size;
    int sched = size*2;
    int arr[sched];
    int maxev = 0;
    for(int i = 0; i < sched; i++){
        cin >> arr[i];
    }
    for(int i = 1; i < 24; i++){
        if(count(i,arr,sched) > maxev){
            maxev = count(i,arr,sched);
        }
    }
    cout << "Max events: " << maxev << "\n";
}

