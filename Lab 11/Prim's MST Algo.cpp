#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the minimum key value vertex from the set of vertices not yet included in MST
int minKey(vector<int>& key, vector<bool>& mstSet, int V) {
    int min = INT_MAX, min_index;
  
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
  
    return min_index;
}

// Function to print the minimum spanning tree
void printMST(vector<int>& parent, vector<vector<int>>& graph, int V) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
}

// Function to implement Prim's algorithm and obtain the minimum spanning tree
void primMST(vector<vector<int>>& graph, int V) {
    vector<int> parent(V); // Array to store constructed MST
    vector<int> key(V); // Key values used to pick the minimum weight edge
    vector<bool> mstSet(V, false); // To represent set of vertices included in MST
  
    // Initialize all key values as infinite
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX;
  
    // Always include the first vertex in MST
    key[0] = 0; // Make the key 0 so that this vertex is picked as the first vertex
    parent[0] = -1; // First node is always the root of MST
  
    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V); // Pick the minimum key vertex from the set of vertices not yet included in MST
        mstSet[u] = true; // Add the picked vertex to the MST set
  
        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
  
    // Print the constructed MST
    printMST(parent, graph, V);
}

int main() {
    // Modify the adjacency matrix according to your graph
    vector<vector<int>> graph = { { 0, 3, 0, 0, 0, 1 },
                        { 3, 0, 2, 1, 10, 0 },
                        { 0, 2, 0, 3, 0, 5 },
                        { 0, 1, 3, 0, 5, 0 },
                        { 0, 10, 0, 5, 0, 4 },
                        { 1, 0, 5, 0, 4, 0 } };

    int V = graph.size(); // Number of vertices

    primMST(graph, V);

    return 0;
}
