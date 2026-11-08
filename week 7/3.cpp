/*
Max Flow
Khó
Given a network G = (V, E) which is a directed weighted graph. Node s is the source and node t is the target. c(u,v) is the capacity of the arc (u,v). Find the maximum flow on G.
Input
•Line 1: two positive integers N and M (1 <= N <= 10
4
, 1 <= M <= 10
6
)
•Line 2: contains 2 positive integers s and t
•Line i+2 (I = 1,. . ., M): contains two positive integers u and v which are endpoints of i
th
 arc
Output
  Write the value of the max-flow found
Example
Input
7 12
6 7
1 7 7
2 3 6
2 5 6
3 1 6
3 7 11
4 1 7
4 2 4
4 5 5
5 1 4
5 3 4
6 2 8
6 4 10
Output
17
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Edge {
    int to;
    int rev;
    ll cap;
};

int N, M, s, t;

vector<vector<Edge>> adj;
vector<int> level, ptr;

// Thêm cạnh xuôi và cạnh ngược
void addEdge(int u, int v, ll c) {
    int revU = adj[u].size();
    int revV = adj[v].size();

    adj[u].push_back({v, revV, c});
    adj[v].push_back({u, revU, 0});

    // Xử lý đúng cả trường hợp u == v
    if (u == v)
        adj[u][revU].rev++;
}

// BFS tạo đồ thị tầng
bool bfs() {
    fill(level.begin(), level.end(), -1);

    queue<int> q;
    q.push(s);
    level[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (const Edge& e : adj[u]) {
            if (e.cap > 0 && level[e.to] == -1) {
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
        }
    }

    return level[t] != -1;
}

// DFS đẩy luồng
ll dfs(int u, ll pushed) {
    if (pushed == 0)
        return 0;

    if (u == t)
        return pushed;

    for (int& i = ptr[u]; i < (int)adj[u].size(); i++) {
        Edge& e = adj[u][i];

        if (e.cap <= 0 ||
            level[e.to] != level[u] + 1)
            continue;

        ll flow = dfs(e.to, min(pushed, e.cap));

        if (flow == 0)
            continue;

        e.cap -= flow;
        adj[e.to][e.rev].cap += flow;

        return flow;
    }

    return 0;
}

ll maxFlow() {
    ll ans = 0;
    const ll INF = LLONG_MAX;

    while (bfs()) {
        fill(ptr.begin(), ptr.end(), 0);

        while (true) {
            ll pushed = dfs(s, INF);

            if (pushed == 0)
                break;

            ans += pushed;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    cin >> s >> t;

    adj.resize(N + 1);
    level.resize(N + 1);
    ptr.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        addEdge(u, v, c);
    }

    if (s == t) {
        cout << 0 << '\n';
        return 0;
    }

    cout << maxFlow() << '\n';

    return 0;
}
