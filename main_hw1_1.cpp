/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw1_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw1_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */
// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw1_1.cpp
 * Abstract: Listen every number not shared between two sets of arrays only once and in descending order.
 * ID: 9190
 * Name: Reece Whitelaw
 * Date: 02/03/2023
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool ispresent(int array[],int value, int size){
    //Return false if value is already present in array
    for(int i = 0; i < size; i++){
        if(value == array[i]){
            return true;
        }
    }
    return false;
}

void arraycomparison(int arr1[], int arr2[], int size1, int size2){
    int printarr[size1];
    //Count of non-intersecting numbers
    int count = 0;

    //First loop will check arr1 if value is shared between the 3 arrays. If not, it gets added.
    for(int i = 0; i < size1; i++){
        //Checking if arr[i] is in arr2
        if(ispresent(arr2, arr1[i], size2) == false && (ispresent(printarr, arr1[i], count) == false)){
            //arr1[i] is not present in arr2 or printarr, so we add it
            printarr[count] = arr1[i];
            count++;
        }
    }
     for(int i = 0; i < size2; i++){
        //Checking if arr[i] is in arr2
        if(ispresent(arr1, arr2[i], size1) == false && (ispresent(printarr, arr2[i], count) == false)){
            //arr1[i] is not present in arr1 or printarr, so we add it
            printarr[count] = arr2[i];
            count++;
        }
    }   
    
    
    int x = count/1;
    sort(printarr, printarr + x, greater<int>());
    if(count > 0){
        cout << "Answer:";
            for(int i = 0; i < count; i++){
                cout << printarr[i];
                if((i+1) != count){
                    cout << " ";
                }
         }
        cout << "\n";
    }else{
        cout << "Answer:NONE" << "\n";
    }
}

int main() {
	int count = 0;
    cin >> count;
    int arr1[count];
    for(int i = 0; i < count; i++){
        int temp;
        cin >> temp;
        arr1[i] = temp;
    }
    int count2;
    cin >> count2;
    int arr2[count2];
    for(int i = 0; i < count2; i++){
        int temp;
        cin >> temp;
        arr2[i] = temp;
    }
    arraycomparison(arr1, arr2, count, count2);
}
