#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <chrono>

using namespace std;
using namespace std::chrono;

class GraphTraversal
{
private:
    void dfs_recursive(int node, const vector<int> adj[], vector<bool> &visited, vector<int> &traversal_path)
    {
        visited[node] = true;
        traversal_path.push_back(node);
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                dfs_recursive(neighbor, adj, visited, traversal_path);
            }
        }
    }

    void bfs_traversal(int start_node, int V, const vector<int> adj[], vector<int> &traversal_path)
    {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start_node] = true;
        q.push(start_node);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            traversal_path.push_back(node);

            for (int neighbor : adj[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

public:
    vector<int> dfsOfGraph(int V, const vector<int> adj[], int start_node)
    {
        vector<bool> visited(V, false);
        vector<int> traversal_path;
        dfs_recursive(start_node, adj, visited, traversal_path);
        return traversal_path;
    }

    bool pathExistsDFS(int V, const vector<int> adj[], int start_node, int target_node)
    {
        vector<bool> visited(V, false);
        stack<int> s;

        visited[start_node] = true;
        s.push(start_node);

        while (!s.empty())
        {
            int node = s.top();
            s.pop();

            if (node == target_node)
            {
                return true;
            }

            for (int neighbor : adj[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    s.push(neighbor);
                }
            }
        }
        return false;
    }

    vector<int> bfsOfGraph(int V, const vector<int> adj[], int start_node)
    {
        vector<int> traversal_path;
        bfs_traversal(start_node, V, adj, traversal_path);
        return traversal_path;
    }

    bool pathExistsBFS(int V, const vector<int> adj[], int start_node, int target_node)
    {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start_node] = true;
        q.push(start_node);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            if (node == target_node)
            {
                return true;
            }

            for (int neighbor : adj[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return false;
    }
};

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<int> adj[V];
    cout << "Enter edges:" << endl;
    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start_node, target_node;
    cout << "Enter source node: ";
    cin >> start_node;
    cout << "Enter target node: ";
    cin >> target_node;

    GraphTraversal obj;

    auto start_dfs = high_resolution_clock::now();
    vector<int> dfsTraversal = obj.dfsOfGraph(V, adj, start_node);
    auto stop_dfs = high_resolution_clock::now();
    auto duration_dfs = duration_cast<nanoseconds>(stop_dfs - start_dfs);

    cout << "DFS Traversal: ";
    for (int node : dfsTraversal)
    {
        cout << node << " ";
    }
    cout << endl;

    auto start_bfs = high_resolution_clock::now();
    vector<int> bfsTraversal = obj.bfsOfGraph(V, adj, start_node);
    auto stop_bfs = high_resolution_clock::now();
    auto duration_bfs = duration_cast<nanoseconds>(stop_bfs - start_bfs);

    cout << "BFS Traversal: ";
    for (int node : bfsTraversal)
    {
        cout << node << " ";
    }
    cout << endl;

    if (obj.pathExistsDFS(V, adj, start_node, target_node))
    {
        cout << "Path exists from " << start_node << " to " << target_node << " (DFS): Yes" << endl;
    }
    else
    {
        cout << "Path exists from " << start_node << " to " << target_node << " (DFS): No" << endl;
    }

    if (obj.pathExistsBFS(V, adj, start_node, target_node))
    {
        cout << "Path exists from " << start_node << " to " << target_node << " (BFS): Yes" << endl;
    }
    else
    {
        cout << "Path exists from " << start_node << " to " << target_node << " (BFS): No" << endl;
    }

    cout << "DFS Traversal Time: " << (double)duration_dfs.count() / 1e9 << " sec" << endl;
    cout << "BFS Traversal Time: " << (double)duration_bfs.count() / 1e9 << " sec" << endl;

    return 0;
}
