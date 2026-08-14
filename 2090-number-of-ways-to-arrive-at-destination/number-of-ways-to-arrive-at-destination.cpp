#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long MOD = 1e9 + 7;

        // Step 1: Build bidirectional adjacency list
        // adj[u] stores pairs of {v, time}
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        // Step 2: Distance and Ways arrays
        // Use 'long long' because edge weights can be up to 10^9
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        // Min-heap storing {current_shortest_time, node}
        priority_queue<pair<long long, int>, 
                       vector<pair<long long, int>>, 
                       greater<pair<long long, int>>> pq;

        // Base cases for source node 0
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        // Step 3: Dijkstra traversal
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            // If we found a path to 'u' that is longer than the optimal dist[u], skip
            if (d > dist[u]) continue;

            for (const auto& [v, wt] : adj[u]) {
                // Case 1: Found a strictly shorter route to v
                if (d + wt < dist[v]) {
                    dist[v] = d + wt;
                    ways[v] = ways[u]; // Reset ways
                    pq.push({dist[v], v});
                }
                // Case 2: Found an alternative route to v with the same minimum time
                else if (d + wt == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD; // Accumulate ways
                }
            }
        }

        return ways[n - 1] % MOD;
    }
};