/*All pair shortest paths
Trung bình
Given a directed graph G = (V, E) in which V = {1, 2, ..., n} is the set of nodes, and w(u,v) is the weight 
(length) of the arc(u,v). Compute d(u,v) - the length of the shortest path from u to v in G, for all u,v in V.

Input
Line 1: contains 2 positive integers n and m (1 <= n,m <= 10000)
Line i+1 (i = 1, 2, ..., m): contains 3 positive integers u, v, w in which w is the weight of the arc (u,v)
 (1 <= w <= 1000)
Output
Line i (i = 1, 2, ..., n): wirte the ith row of the matrix d (if there is not any path from node i to 
node j, then d(i,j) = -1)
Example
Input
4 9 
1 2 9 
1 3 7 
1 4 2 
2 1 1 
2 4 5 
3 4 6 
3 2 2 
4 1 5 
4 2 8
Output
0 9 7 2  
1 0 8 3  
3 2 0 5  
5 8 12 0*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = LLONG_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
    }

    for (int s = 1; s <= n; s++) {
        vector<ll> dist(n + 1, INF);

        priority_queue<
            pair<ll, int>,
            vector<pair<ll, int>>,
            greater<pair<ll, int>>
        > pq;

        dist[s] = 0;
        pq.push({0, s});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[u]) continue;

            for (auto [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        for (int v = 1; v <= n; v++) {
            if (dist[v] == INF)
                cout << -1;
            else
                cout << dist[v];

            if (v < n) cout << ' ';
        }

        cout << '\n';
    }

    return 0;
}
