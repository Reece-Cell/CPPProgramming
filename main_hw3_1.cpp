/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw3_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw3_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw3_1.cpp
 * Abstract: Make an adjancency list gives vertexs and edges.
 * ID: 9190
 * Name: Reece Whitelaw
 * Date: 02/17/2023
 */

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool in_array(int value, int arr[], int edges) {
    for (int i = 0; i < edges; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

int main() {
    int vertices, edges;
    cin >> vertices;
    cin >> edges;

    //First array shall store all our inputs given vertices and edges
    int arr[3*edges];
    int print[3*edges];

    // Get input from the user for each element of the array
    for(int i = 0; i < (3*edges); i++){
        cin >> arr[i];
    }

    //Second array shall store all our vertices
    int vert[vertices];
    int vsize = 0;

    // Get unique vertices from the input array
    for (int i = 0; i < 3*edges; i++) {
        int sanity = i+1;
        sanity = sanity%3;
        if(i == 0){
            vert[vsize] = arr[i];
            vsize++;
        }
        if(in_array(arr[i], vert, edges) == false && (sanity != 0)){
            vert[vsize] = arr[i];
            vsize++;
        }
    }
    sort(vert, vert + vsize);
    //We need a function to sort the rows in an ascending order.
    
    // Print the graph
    for (int i = 0; i < vertices; i++) {
        cout << i;
        int psize = 0;
        //memset(print, 0, sizeof(print));
        //To print in order we'll make an array that stores every adjacent value
        //to vert[i] in ascending order.
        for(int x = 0; x < 3*edges; x+=3){
            if(arr[x] == i){
                print[psize] = arr[x+1];
                psize++;
            }
        }
        sort(print, print + psize);
        //Search for values equaling the ones stored in vert[i] AND print[x], then print and          increment print[x]
        //Sanit reminder. Vert[i] is a vertex, print[x] is a sorted array of all its adjacent
        //vertexes. Because of this we dont need to worry about duplicates, as a vertex will          only be adjacent once.
        
        for (int x = 0; x < psize; x++) {
            for(int y = 1; y < edges*3; y += 3){
                //cout << "Format Comparison " << y << ": \n" << "Arr[y] == " << arr[y] << "  Print[x]                   == " << print[x] << " and arr[y-1] == " << arr[y-1] << " and vert[i] equals: " <<                        vert[i] << "\n\n";
                if(arr[y] == print[x] && arr[y-1] == i){
                    cout << "->" << arr[y] << "," << arr[y+1];
                    break;
                }
            }
        }
        cout << "\n";
    }
}