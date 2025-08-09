#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> st;
        vector<int> dist(V, INT_MAX);
        st.insert({0, S});
        dist[S] = 0;

        while (!st.empty())
        {
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);

            for (auto neighbor : adj[node])
            {
                int adjNode = neighbor[0];
                int edgeWeight = neighbor[1];

                if (dis + edgeWeight < dist[adjNode])
                {
                    if (dist[adjNode] != INT_MAX)
                    {
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dis + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};

int main()
{
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

    for (int i = 0; i < V; ++i)
    {
        if (distances[i] == INT_MAX)
        {
            cout << "  To node " << i << ": INF\n";
        }
        else
        {
            cout << "  To node " << i << ": " << distances[i] << "\n";
        }
    }

    return 0;
}