#include<iostream>
#include<climits>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
public:
    vector<int>bfsOfGraph(int V, vector<int>adj[]){
        int visit[V];
        for(int i = 0; i < V; ++i) {
            visit[i] = 0;// as assume that all the node are 0 at first.
        }
        visit[0] = 1;// we visit 1st node so it is true .so make it with 1
        queue<int>q;
        q.push(0);//it is our source node 0 which we include in queue.
        vector<int>bfs;
        while(!q.empty()){
            int node = q.front();// then we put that 0 into queue. as front value.
            q.pop();// then we take out the 0 value.
            bfs.push_back(node);// and add to it in the bfs.

            for(int it : adj[node]){// we visit connected neighbour with this.
                if(!visit[it]){// do until we find it
                    visit[it] = 1;// if we found then true so 1
                    q.push(it);//then include the found neighbour into the bfs.
                }
            }
        }
        return bfs;
    }
};

int main() {
    Solution solver;

    int V = 5;
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[2].push_back(4);
    adj[3].push_back(1);
    adj[4].push_back(2);

    vector<int> result = solver.bfsOfGraph(V, adj);

    cout << "BFS Traversal: ";
    for(int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}