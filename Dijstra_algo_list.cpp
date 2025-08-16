#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V);
        for (int i = 0; i < V; i++) {
            dist[i] = INT_MAX;
        }
        dist[S] = 0;
        pq.push({0, S});

        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dis > dist[node]) {
                continue;
            } 

            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edgeWeight = it[1];

                if (dist[node] + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dist[node] + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};

int main() {
    Solution solver;

    int V = 5;
    vector<vector<int>> adj[V];

    adj[0].push_back({1, 2});
    adj[0].push_back({3, 1});

    adj[1].push_back({2, 4});

    adj[2].push_back({4, 3});

    adj[3].push_back({1, 1});
    adj[3].push_back({4, 5});

    int S = 0;

    cout << "Dijkstra's Shortest Paths (Source: " << S << "):\n";
    vector<int> distances = solver.dijkstra(V, adj, S);

    for ( int i=0;i<V;++i) {
        if (distances[i] == INT_MAX) {
            cout << "  To node " << i << ": INF\n";
        } else {
            cout << "  To node " << i << ": " << distances[i] << "\n";
        }
    }

    return 0;
}