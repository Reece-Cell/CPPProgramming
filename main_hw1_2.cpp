/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw1_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw1_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw1_2.cpp
 * Abstract: To find the frequencies of numbers in an array, then print that array in order groups of frequencies ascending by value
 * ID: 9190
 * Name: Reece Whitelaw
 * Date: 2/03/2023
 */

#include <iostream>
#include <map>
using namespace std;

bool isin(int array[], int count, int value){
    //Scan through array of size count+1 and return true if value is present. Otherwise false.
    for(int i = 0; i < count; i++){
        if(array[i] == value){
            return true;
        }
    }
    return false;
}

void print(int value, int freq){
    for(int i = 0; i < freq; i++){
        cout << value << " ";
    }
}
void printnospace(int value, int freq){
    for(int i = 0; i < freq; i++){
        //If this isn't the last loop, add space
        if(i + 1 != freq){
            cout << value << " ";
        }else{
        cout << value << "\n";            
        }
    }
}

void scan(int array[], int count, map<int, int> freq){
    //This shall iterate through the map using the keys[] array, looking for a key-value pair with the lowest value.
    //If it encounters a value that is equal to its own, it will take the key value pair of the highest number.
    //Then it will call a print function that, given a x, y numbers, prints x y times
    //THEN it will set the value of the number to be -1, so we do not call it again
    int value = 0;
    int frequency = 0;
    int spacecheck = count - 1;
    for(int i = 0; i < count; i++){
        value = 100;
        frequency = 100;
        
        for(int x = 0; x < count; x ++){
            if(frequency > freq[array[x]] && freq[array[x]] > 0){
                //If our frequency is higher and theirs is greater than 0, switch values and frequencies
                value = array[x];
                frequency = freq[array[x]];
            }else if (frequency == freq[array[x]] && freq[array[x]] > 0){
                if(value > array[x]){
                    //If our number is higher than array but frequencies are equal, switch values and frequencies
                    value = array[x];
                    frequency = freq[array[x]];
                }
            }
            //If loop is about to end, send values to a print function and set frequency in map to -1
            if(x + 1 == count){
                if(spacecheck == 0){
                    printnospace(value, frequency);
                }else{
                print(value, frequency);
                freq[value] = -1;
                spacecheck--;   
                }
            }
        }
    }
}

int main()
{
    // Your code should be here.
    // The following is a just sample statement.
    int size;
    cin >> size;
    int arr[size];

    //Make map where every key value is a found number, and every mapped value is how many times they occurred.
    map<int, int> freq;
    //Make array that keeps the keys account for. Setting size to 500 for arbitrary protection from being too small.
    int keys[500];
    //Count tell us how many keys are in said map
    int count = 0;
    
    for(int i = 0; i < size; i++){
        //Add all numbers to the array
        int insert;
        cin >> insert;
        arr[i] = insert;
    }
    for(int i = 0; i < size; i++){
        //Is the value in arr[i] in the map?
        //Check keys. If in keys[], increment map at that key. If not, add key to map with count 1, then add key to keys[] and increase count.
        if(isin(keys, count, arr[i]) == true){
            //Increasing Count
            freq[arr[i]] = freq[arr[i]] + 1;
        }else{
            freq.insert({arr[i], 1});
            keys[count] = arr[i];
            count++;
        }
    }
    //At the end of the above loop, every value will have been added to the map, along with every occurrence as their mapped value.
    scan(keys, count, freq);
    return 0;
}

