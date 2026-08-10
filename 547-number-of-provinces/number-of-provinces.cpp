#include <vector>

using namespace std;

class Solution {
private:
    // Function to perform DFS traversal
    void dfs(int node, vector<int> adjList[], vector<int>& visited) {
        // Mark current node as visited
        visited[node] = 1;

        // Visit all adjacent unvisited nodes
        for (auto neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adjList, visited);
            }
        }
    }

public:
    // Function to count number of connected components (provinces)
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();

        // Create adjacency list from adjacency matrix
        vector<int> adjList[V];

        // Convert matrix to list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // Ignore self-loops and non-connected nodes
                if (isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                }
            }
        }

        // Vector to keep track of visited nodes
        vector<int> visited(V, 0);

        // Count of connected components
        int count = 0;

        // Traverse all nodes
        for (int i = 0; i < V; i++) {
            // If node is not visited
            if (!visited[i]) {
                // Perform DFS and increment count
                count++;
                dfs(i, adjList, visited);
            }
        }

        // Return final count
        return count;
    }
};