#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Fix 1 & 7: Standard 2D vector of pairs for {neighbor, price}
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        // Queue stores: {stops, {current_node, current_cost}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        // Fix 2: Comma ',' instead of '.'
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty()) {
            auto it = q.front();
            q.pop(); // Fix 3: No argument in pop()

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            // Fix 4: Check 'stops > k' instead of 'dist > k'
            if (stops > k) {
                continue;
            }

            for (const auto& itr : adj[node]) {
                int adjnode = itr.first;
                int weight = itr.second;

                if (cost + weight < dist[adjnode] && stops <= k) {
                    dist[adjnode] = cost + weight;
                    // Fix 5: Corrected 'codt' typo to 'cost'
                    q.push({stops + 1, {adjnode, cost + weight}});
                }
            }
        }

        if (dist[dst] == 1e9) {
            return -1;
        }

        return dist[dst];
    }
};