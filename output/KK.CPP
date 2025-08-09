#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> zoneNameToId;
map<int, string> idToZoneName;

void initializeZoneMappings() {
    zoneNameToId["Admission Office(1)"] = 0;
    zoneNameToId["AB-4(2)"] = 1;
    zoneNameToId["Food Court(3)"] = 2;
    zoneNameToId["Gym(4)"] = 3;
    zoneNameToId["Medical Center(5)"] = 4;
    zoneNameToId["Engineering Building(6)"] = 5;
    zoneNameToId["Green Garden(7)"] = 6;
    zoneNameToId["Center Mosque(8)"] = 7;
    zoneNameToId["AB-1(9)"] = 8;
    zoneNameToId["Innovation Lab(10)"] = 9;
    zoneNameToId["Rowsorara Hall(11)"] = 10;
    zoneNameToId["YKSG-2(12)"] = 11;
    zoneNameToId["Transport(13)"] = 12;
    zoneNameToId["YKSG-1(14)"] = 13;

    for (auto const& [name, id] : zoneNameToId) {
        idToZoneName[id] = name;
    }
}

class Solution {
public:
    void recursiveBfsHelper(int V, const vector<int> adj[], vector<int>& visited, queue<int>& q, vector<string>& bfsResult) {
        if (q.empty()) {
            return;
        }

        int node = q.front();
        q.pop();
        bfsResult.push_back(idToZoneName[node]);

        for (int neighbor : adj[node]) {
            if (visited[neighbor] == 0) {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }

        recursiveBfsHelper(V, adj, visited, q, bfsResult);
    }

    vector<string> bfsOfGraphRecursive(int V, vector<int> adj[], int startNodeId) {
        vector<int> visited(V, 0);
        queue<int> q;
        vector<string> bfsResult;

        q.push(startNodeId);
        visited[startNodeId] = 1;

        recursiveBfsHelper(V, adj, visited, q, bfsResult);
        return bfsResult;
    }
};

int main() {
    initializeZoneMappings();

    Solution solver;

    int V = 14;
    vector<int> adj[V];

    adj[zoneNameToId["Admission Office(1)"]].push_back(zoneNameToId["AB-4(2)"]);
    adj[zoneNameToId["Admission Office(1)"]].push_back(zoneNameToId["Green Garden(7)"]);

    adj[zoneNameToId["AB-4(2)"]].push_back(zoneNameToId["Admission Office(1)"]);
    adj[zoneNameToId["AB-4(2)"]].push_back(zoneNameToId["Food Court(3)"]);
    adj[zoneNameToId["AB-4(2)"]].push_back(zoneNameToId["Gym(4)"]);

    adj[zoneNameToId["Food Court(3)"]].push_back(zoneNameToId["AB-4(2)"]);
    adj[zoneNameToId["Food Court(3)"]].push_back(zoneNameToId["Gym(4)"]);
    adj[zoneNameToId["Food Court(3)"]].push_back(zoneNameToId["Medical Center(5)"]);
    adj[zoneNameToId["Food Court(3)"]].push_back(zoneNameToId["Center Mosque(8)"]);

    adj[zoneNameToId["Gym(4)"]].push_back(zoneNameToId["AB-4(2)"]);
    adj[zoneNameToId["Gym(4)"]].push_back(zoneNameToId["Food Court(3)"]);
    adj[zoneNameToId["Gym(4)"]].push_back(zoneNameToId["Medical Center(5)"]);
    adj[zoneNameToId["Gym(4)"]].push_back(zoneNameToId["Engineering Building(6)"]);

    adj[zoneNameToId["Medical Center(5)"]].push_back(zoneNameToId["Food Court(3)"]);
    adj[zoneNameToId["Medical Center(5)"]].push_back(zoneNameToId["Gym(4)"]);
    adj[zoneNameToId["Medical Center(5)"]].push_back(zoneNameToId["YKSG-2(12)"]);

    adj[zoneNameToId["Engineering Building(6)"]].push_back(zoneNameToId["Gym(4)"]);
    adj[zoneNameToId["Engineering Building(6)"]].push_back(zoneNameToId["YKSG-2(12)"]);

    adj[zoneNameToId["Green Garden(7)"]].push_back(zoneNameToId["Admission Office(1)"]);
    adj[zoneNameToId["Green Garden(7)"]].push_back(zoneNameToId["Center Mosque(8)"]);
    adj[zoneNameToId["Green Garden(7)"]].push_back(zoneNameToId["Transport(13)"]);

    adj[zoneNameToId["Center Mosque(8)"]].push_back(zoneNameToId["Food Court(3)"]);
    adj[zoneNameToId["Center Mosque(8)"]].push_back(zoneNameToId["Green Garden(7)"]);
    adj[zoneNameToId["Center Mosque(8)"]].push_back(zoneNameToId["AB-1(9)"]);

    adj[zoneNameToId["AB-1(9)"]].push_back(zoneNameToId["Center Mosque(8)"]);
    adj[zoneNameToId["AB-1(9)"]].push_back(zoneNameToId["Innovation Lab(10)"]);
    adj[zoneNameToId["AB-1(9)"]].push_back(zoneNameToId["Transport(13)"]);

    adj[zoneNameToId["Innovation Lab(10)"]].push_back(zoneNameToId["AB-1(9)"]);
    adj[zoneNameToId["Innovation Lab(10)"]].push_back(zoneNameToId["Rowsorara Hall(11)"]);

    adj[zoneNameToId["Rowsorara Hall(11)"]].push_back(zoneNameToId["Innovation Lab(10)"]);
    adj[zoneNameToId["Rowsorara Hall(11)"]].push_back(zoneNameToId["YKSG-2(12)"]);

    adj[zoneNameToId["YKSG-2(12)"]].push_back(zoneNameToId["Medical Center(5)"]);
    adj[zoneNameToId["YKSG-2(12)"]].push_back(zoneNameToId["Engineering Building(6)"]);
    adj[zoneNameToId["YKSG-2(12)"]].push_back(zoneNameToId["Rowsorara Hall(11)"]);

    adj[zoneNameToId["Transport(13)"]].push_back(zoneNameToId["Green Garden(7)"]);
    adj[zoneNameToId["Transport(13)"]].push_back(zoneNameToId["AB-1(9)"]);
    adj[zoneNameToId["Transport(13)"]].push_back(zoneNameToId["YKSG-1(14)"]);

    adj[zoneNameToId["YKSG-1(14)"]].push_back(zoneNameToId["Transport(13)"]);

    int medicalCenterId = zoneNameToId["Medical Center(5)"];
    vector<string> reachableZones = solver.bfsOfGraphRecursive(V, adj, medicalCenterId);

    cout << "Reachable zones from Medical Center(5) (BFS Traversal Order):" << endl;
    for (const string& zone : reachableZones) {
        cout << zone << endl;
    }
    cout << endl;

    return 0;
}
