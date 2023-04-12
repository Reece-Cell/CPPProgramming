/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw6_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw6_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw6_2.cpp
 * Abstract: Discerning groups of nodes and finding if they connect. If not, printing the connections needed.
 * ID: 9190
 * Name: Reece Whitelaw
 * Date: 03/10/2023
 */

#include <iostream>
#include <map>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

void groupassign(map<int, int> &vertexes,int index,int vertlist[],int nodes,int& groupnum) {
	// This should set the value of the rightmost found node to the leftmost
	// node unless they're zero.
    int latest_group = 1;
    if (vertexes[vertlist[index]] == 0 && vertexes[vertlist[index + 1]] == 0) {
        latest_group = groupnum;
        groupnum++;
    } else if (vertexes[vertlist[index]] == 0) {
        latest_group = vertexes[vertlist[index + 1]];
    } else if (vertexes[vertlist[index + 1]] == 0) {
        latest_group = vertexes[vertlist[index]];
    } else {
        latest_group = vertexes[vertlist[index]];
    }
    vertexes[vertlist[index]] = latest_group;
    vertexes[vertlist[index + 1]] = latest_group;
}

void grouprintmap(map<int, int> &vertexes, int vertlist[], int nodes, int groupnum) {
	// Go through our map, and print the lowest key of all the numbers that hold
	// a the same value. We must iterate through all held      values, and print
	// the lowest value for each of them. Then, last step, is to print any keys
	// that hold a value of zero. We want to print them in descending order.
    int array[groupnum];
    int arrzeroes[groupnum];
    int zeroes = 0;
    for(int i = 0; i < nodes; i++){
        if(vertexes[i] == 0){
            arrzeroes[zeroes] = i;
            zeroes++;
        }
    }
    
    for (int i = 0; i < groupnum; i++) {
        array[i] = INT_MAX;
    }
    // Iterate through all keys and update lowest values in array
    for (auto it = vertexes.begin(); it != vertexes.end(); ++it) {
        int key = it->first;
        int value = it->second;
        if (value > 0) {
            array[value - 1] = min(array[value - 1], key);
        }
    }
    int n = sizeof(arrzeroes) / sizeof(arrzeroes[0]);
    sort(arrzeroes, arrzeroes + n);
    
    int ei = 0;
    for (int i = 0; i < groupnum-1; i++) {
        if(i + 1 != groupnum-1){
            cout << "Edge: " << array[i] << "-" << array[i+1] <<"\n";        
        }
        ei = i;
    }
    if(zeroes != 0){
        for(int i = 0; i < zeroes; i++){
            if(i == 0){
                cout << "Edge: " << array[ei] << "-" << arrzeroes[i];
            }
            if(i + 1 != groupnum-1 && i != 0){
                cout << "Edge: " << arrzeroes[i] << "-" << arrzeroes[i+1];
                }
        }
    }
}

int main() {
	// Your code should be here.
	// The following is a just sample statement.
	int nodes;
	int connections;
	cin >> nodes;
    cin >> connections;
	int vertlist[connections * 2];
	// We will go through our map, setting it to Vertex - 0. We shall set the
	// value to a number indicating if it belongs to a group. If it doesn't and
	// it is matched with another number, it has its value set to the number its
	// paired with.
	map<int, int> vertexes;
	// If there is a case where two numbers are called and neither are in a
	// group, but inherit from groupnum, which then iterates.
	int groupnum = 1;
	for (int i = 0; i < connections * 2; i++) {
		cin >> vertlist[i];
	}
	for (int i = 0; i < nodes; i++) {
		vertexes[i] = 0;
	}
	for (int i = 0; i < connections * 2; i += 2) {
		groupassign(vertexes, i, vertlist, nodes, groupnum);
	}
    int insanitycheck = groupnum;
    for (int i = 0; i < nodes; i++) {
		//cout << i << " Group Number: " << vertexes[i] << "\n";
	}
    if(insanitycheck != 1){
        grouprintmap(vertexes, vertlist, nodes, insanitycheck);
    }
    if(insanitycheck < 3 && insanitycheck != 1){
        cout << "No new edge:\n";
    }else if(insanitycheck == 1){
        //Print each value in vertexes but with dashes between them.
        for (int i = 0; i < nodes-1; i++) {
		  cout << "Edge: " << i << "-" << i+1 << "\n";
	    }
    }else{
        cout << "\n";
    }
}
