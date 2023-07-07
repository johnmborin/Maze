#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>

using namespace std;

class Graph {
    private:
    int numNodes;
    // With the data structure I'm under the assumption that a nodes ID # is also its spot in the adj vector
    // i.e node with ID 1 is in spot 1 of the vector (so the second cell bc of starting at 0)
    vector<vector<pair<int,int>>> adjList;

    public: 
    // Constructs a graph with n nodes
    Graph(int n) : numNodes(n) , adjList(n) {}

    // Adds an edge between two given nodes with the given weight
    void addEdge(int origin, int destination, int weight) {
        adjList[origin].push_back({destination,weight});
        adjList[destination].push_back({origin, weight});
    }

    // returns a reference to the list of a nodes neighbors and their respective weights
    const vector<pair<int,int>> & getNeighbors(int currentNode) const {
        return adjList[currentNode];
    }
}