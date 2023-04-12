/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw6_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw6_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw6_1.cpp
 * Abstract: Write the main purpose of the program.
 * ID: 9190
 * Name: Reece Whitleaw
 * Date: 03/12/2023
 */

#include <iostream>
#include <map>

using namespace std;
//visits recusrively all the univisted vertices connected to vertex v
void dfs(int v, map<int, bool>& visited, map<int, map<int, bool>>& adj_map, int& count) {
    visited[v] = true;
    cout << "Mark[" << count-1 << "]:" << count << "\n";
    count++;
    //mark v with count
    for (map<int, bool>::iterator it = adj_map[v].begin(); it != adj_map[v].end(); it++) {
        if (!visited[it->first]) {
            dfs(it->first, visited, adj_map, count);
        }
    }
}

int main() {
    int vertices;
    int edges;
    cin >> vertices >> edges;
    //Get out map of adjaceny and then keep track of whats been visited already
    map<int, map<int, bool>> adj_map;
    map<int, bool> visited;
    for (int i = 0; i < edges; i++) {
        //Create indexes
        int first;
        int second;
        cin >> first >> second;
        //Graph G with its vertices marked with consecutive integers
        //In the order they are first encountered by the DFS traversal
        //mark each vertex in V with 0 as a mark of being unvisited
        //Alloting each pair and also keeping track of if its been visited already
        adj_map[first][second] = true;
        adj_map[second][first] = true;
        visited[first] = false;
        visited[second] = false;
    }
    int count = 1;
    for (map<int, map<int, bool>>::iterator it = adj_map.begin(); it != adj_map.end(); it++) {
        //for each vertex v in V do
            //if v is marked with 0 
                //dfs(v)
        if (!visited[it->first]) {
            dfs(it->first, visited, adj_map, count);
        }
    }
    return 0;
}
