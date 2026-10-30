/*Week 6 - Store & Search Graphs
Trung bình
Back Tracking
GRAPH
HASH
Two undirected graphs G1 = (V1, E1) and G2 = (V2,E2) have the same structure (G1 and G2 are isomorphic) if and only if there exists a bijective function f: V1 -> V2 such that (u,v) in E1 iff (f(v), f(v)) in E2.
Given a sequence of undirected graph G = g1, g2, . . ., gN. Perform K queries to check whether or not a given graph hk (k = 1, 2, . . ., K) is present in G (there exists a graph of G which has the same structure with hk).
Input
The input consists of 2 blocks:
	The first blocks are N graphs with the format:
	Line 1: contains a positive integer N (1 <= N <= 10000)
	Subsequent lines contain the information about n graphs g1, g2, . . ., gN with the format:
	Line 1: contains 2 integer n and m which are the number of nodes and edges of the graph
	Line i+1 (i = 1, 2, ..., m): contains 2 integer u and v which are endpoints of an edge of the graph 
	The first block is terminated with a line containing #
	The second block are K graphs in the queries with the format:
	Line 1: contains 2 integer n and m which are the number of nodes and edges of the graph
	Line i+1 (i = 1, 2, ..., m): contains 2 integer u and v which are endpoints of an edge of the graph 


Output
Line k (k = 1, 2, ..., K): contains 1 if the graph hk is present in G, and contains 0, otherwise

Example
Input 
4
3 3
1 2
1 3
2 3
4 4
1 2
2 3
3 4
1 4
4 5
1 2
1 3
2 3
2 4
3 4
4 5
1 2
1 3
1 4
2 4
3 4
#
3
3 2
1 2
1 3
4 5
1 3
1 4
2 3
2 4
3 4
4 4
1 2
1 3
2 4
3 4

Output
0
1
1
*/

#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int n, m;
    vector<vector<unsigned char>> adj;
    vector<int> deg;

    void read() {
        cin >> n >> m;

        adj.assign(n, vector<unsigned char>(n, 0));
        deg.assign(n, 0);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;

            if (!adj[u][v]) {
                adj[u][v] = adj[v][u] = 1;

                if (u == v) {
                    deg[u] += 2;
                } else {
                    deg[u]++;
                    deg[v]++;
                }
            }
        }

        int edges = 0;
        for (int u = 0; u < n; u++) {
            edges += deg[u];
        }
        m = edges / 2;
    }

    string getKey() const {
        vector<int> d = deg;
        sort(d.begin(), d.end());

        string key = to_string(n) + "|" + to_string(m);

        for (int x : d) {
            key += "|" + to_string(x);
        }

        return key;
    }
};

bool backtrack(
    const Graph &a,
    const Graph &b,
    const vector<int> &order,
    vector<int> &mapping,
    vector<bool> &used,
    int pos
) {
    if (pos == a.n) return true;

    int u = order[pos];

    for (int v = 0; v < b.n; v++) {
        if (used[v]) continue;
        if (a.deg[u] != b.deg[v]) continue;
        if (a.adj[u][u] != b.adj[v][v]) continue;

        bool valid = true;

        for (int i = 0; i < pos; i++) {
            int x = order[i];
            int y = mapping[x];

            if (a.adj[u][x] != b.adj[v][y]) {
                valid = false;
                break;
            }
        }

        if (!valid) continue;

        mapping[u] = v;
        used[v] = true;

        if (backtrack(a, b, order, mapping, used, pos + 1)) {
            return true;
        }

        mapping[u] = -1;
        used[v] = false;
    }

    return false;
}

bool isomorphic(const Graph &a, const Graph &b) {
    if (a.n != b.n || a.m != b.m) {
        return false;
    }

    if (a.getKey() != b.getKey()) {
        return false;
    }

    vector<int> order(a.n);
    iota(order.begin(), order.end(), 0);

    sort(order.begin(), order.end(), [&](int x, int y) {
        if (a.deg[x] != a.deg[y]) {
            return a.deg[x] > a.deg[y];
        }
        return x < y;
    });

    vector<int> mapping(a.n, -1);
    vector<bool> used(b.n, false);

    return backtrack(a, b, order, mapping, used, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    unordered_map<string, vector<Graph>> stored;

    for (int i = 0; i < N; i++) {
        Graph g;
        g.read();

        stored[g.getKey()].push_back(move(g));
    }

    string separator;
    cin >> separator;  // Read '#'

    int K;
    cin >> K;

    for (int i = 0; i < K; i++) {
        Graph h;
        h.read();

        string key = h.getKey();
        bool found = false;

        auto it = stored.find(key);

        if (it != stored.end()) {
            for (const Graph &g : it->second) {
                if (isomorphic(g, h)) {
                    found = true;
                    break;
                }
            }
        }

        cout << (found ? 1 : 0) << '\n';
    }

    return 0;
}
