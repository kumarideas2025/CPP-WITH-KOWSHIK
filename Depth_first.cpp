#include<iostream>
#include<climits>
#include<stack>
#include<algorithm>
#include<vector>


using namespace std;

class Solution {
private://we use it as only can access by dfs not by outer any call. 
    void dfs(int node, vector<int> adj[], int vis[], vector<int>& ls) {// dfs works as recursion so that so we did not travel whole grape. so for memory consumption use private.
        vis[node] = 1;// visit as off now.
        ls.push_back(node);// include it in the list
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, ls);// if neighbour is not visited then call all as recursively.
            }
        }
    }
public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};// assume that all th elements are 0.
        int start = 0;
        vector<int> ls;// to store dfs element create an array.
        dfs(start, adj, vis, ls);
        return ls;// return that vector with visiting all nodes.
    }
};

int main() {
    int V = 5;
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(0); 

    Solution obj;
    vector<int> dfsTraversal = obj.dfsOfGraph(V, adj);

    cout << "DFS Traversal: ";
    for (int node : dfsTraversal) {
        cout << node << " ";
    }
    cout << endl; 

    return 0;
}