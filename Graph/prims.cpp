#include <bits/stdc++.h>
using namespace std;
// O(ElogV)

int main() {
    int V, E;
    cin >> V >> E;

    // {adjNode, weight}
    vector<vector<pair<int, int>>> adj(V);

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // {weight, {node, parent}}
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    > pq;

    vector<bool> visited(V, false);

    pq.push({0, {0, -1}});

    int mstCost = 0;

    vector<pair<int, int>> mstEdges;

    while (!pq.empty()) {

        int wt = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;

        pq.pop();

        if (visited[node]) continue;
        visited[node] = true;

        mstCost += wt;

        if (parent != -1) {
            mstEdges.push_back({parent, node});
        }

        for (auto it : adj[node]) {

            int adjNode = it.first;
            int edgeWt = it.second;

            if (!visited[adjNode]) {
                pq.push({edgeWt, {adjNode, node}});
            }
        }
    }

    cout << "Edges in MST:\n";

    for (auto edge : mstEdges) {
        cout << edge.first << " - " << edge.second << endl;
    }

    cout << "Total MST Cost = " << mstCost << endl;

    return 0;
  }