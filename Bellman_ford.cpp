#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;

class solution {
public:
    vector<int> bellmon_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;

        for (int i = 0; i < V - 1; i++) {
            for (auto it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];//source_node, destination_node, weight.so 0,1,5 out with those three.

                if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                return {-1}; 
            }
        }

        return dist;
    }
};

int main() {
    solution solver;
 
    int V = 6;  
    int S = 0;  

    // {source_node, destination_node, weight}
    vector<vector<int>> edges = {
        {0, 1, 5},
        {4, 2, 2},
        {1, 3, 3},
        {2, 4, 3},
        {3, 2, 6},
        {3, 5, 2},
        
    };

    cout << "Bellman-Ford Shortest Paths (Source: " << S << "):\n";
    vector<int> distances = solver.bellmon_ford(V, edges, S);

    if (distances.size() == 1 && distances[0] == -1) {// if there is only  1 edge and it wt is -1. then negative
        cout << "  Negative cycle detected!\n";
    } else {
        for (int i = 0; i < V; ++i) {
            if (distances[i] == INT_MAX) {
                cout << "  To node " << i << ": INF\n";
            } else {
                cout << "  To node " << i << ": " << distances[i] << "\n";
            }
        }
    }
   vector<vector<int>> edges_negative_cycle = {
        {0, 1, 1},
        {1, 2, -1},
        {2, 3, -1},
        {3, 1, -1}  
    };
    
    cout << "\nBellman-Ford with a Negative Cycle (Source: " << S<< "):\n";
    vector<int> negative_cycle_distances = solver.bellmon_ford(4, edges_negative_cycle, S);

    if (negative_cycle_distances.size() == 1 && negative_cycle_distances[0] == -1) {
        cout << "  Graph contains a negative weight cycle.\n";
    } else {
        for (int i = 0; i < 4; ++i) {
            if (negative_cycle_distances[i] == INT_MAX) {
                 cout << "  To node " << i << ": INF\n";
            } else {
                cout << "  To node " << i << ": " << negative_cycle_distances[i] << "\n";
            }
        }
    }

    return 0;
}
