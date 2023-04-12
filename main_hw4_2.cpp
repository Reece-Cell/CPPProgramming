/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw4_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw4_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw4_2.cpp
 * Abstract: Print the maximum possible number of apples based on provided baskets containing apples with the constraint that you cannot pick two adjacent baskets.
 * ID: 9190
 * Name: Reece Whitelaw
 * Date: 02/24/2023
 */
#include <map>
#include <iostream>
#include <cmath>
#include <string>
#include <utility>

using namespace std;

void combs(int size, string arr[]){
    int num_comb = pow(2, size);
    for (int i = 0; i < num_comb; i++) {
        string combination(size, '0');
        int temp = i;

        for (int x = size - 1; x >= 0; x--) {
            if (temp % 2 == 1) {
                combination[x] = '1';
            }
            temp /= 2;
        }
        arr[i] = arr[i] + combination;
    }
}

int constraint(string arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
      string temp = arr[i];
      bool has_adjacent_ones = false;
      for (size_t x = 0; x < temp.size()-1; x++) {
          if (temp[x] == '1' && temp[x+1] == '1') {
              has_adjacent_ones = true;
              break;
          }
      }
      if (!has_adjacent_ones) {
          arr[count] = temp;
          //cout << arr[count] << " ";
          count++;
      }
  }
    return count;
}

map<int, pair<string, int>> mapbask(map<int, pair<string, int>> map, string key[], int baskets[], int combos){
    //REMEMBER: COMBOS SHOULD BE ADJUSTED FOR A NEW ARRAY SIZE
    //First loop iterates through our array of keys
    int count = 0;
    for(int x = 0; x < combos; x++){
        string temp = key[x];
        int value = 0;
        string basknum;
        //Second loop iterates through the keys themselves and finds the value they would hold, as well as the associated baskets
        int printer = 0;
        for(int i = 0; i < temp.size(); i++){
            if(temp[i] == '1'){
                value = baskets[i] + value;
                if(printer == 0){
                    basknum = basknum + to_string(i);
                    printer++;
                }else{
                    basknum = basknum + " " + to_string(i);
                }
            }
        }
        //Finishing saving the basket numbers and their combined values, we save it to the             map.
        map[count] = make_pair(basknum, value);
        count++;
    }
    for(int i = 0; i < count+1; i++){
        //cout << "Key=" << i << ", Value=(" <<map[i].first << ", " << map[i].second << ")" << endl;
    }
    return map;
}

void findmax(map<int, pair<string, int>> map, int combos){
    int key = -1;
    int value = 0;
    for(int i = 0; i < combos; i++){
        if(map[i].second > value){
            key = i;
            value = map[i].second;
        }
    }
    if(key != -1) {
        cout << "Boxes:" << map[key].first << "\nMax Apples:" << map[key].second << "\n";
    } else {
        cout << "No valid keys found";
    }
}

int main()
{
    // Your code should be here.
    // The following is a just sample statement.
    int count;
    cin >> count;
    int baskets[count];
    
    for(int i = 0; i < count; i++){
        cin >> baskets[i];
    }
    //Length of array holding all combinations
    int combos = pow(2,count);
    string arr[combos];
    //Map that will hold relevant baskets and the value of their combinations
    map<int, pair<string, int>> basks;
    
    combs(count, arr);
    combos = constraint(arr, combos);
    basks = mapbask(basks, arr, baskets, combos);
    //Now we get a function that finds the highest value in the map, and prints it.
    findmax(basks, combos);
        
}

