/*Mã đi tuần
A knight starts from a cell (r, c) (row r and column c) in a chessboard of size NxN (rows and columns are indexed from 1, 2, ..., N). Each cell of a chessboard has an integer: G_{r,c} is the integer at the cell row r column c (1 <= r,c <= N). It wants to move to some cells (each cell is visited exactly once) of the chessboard. Find the route for the knight so that the sum of integers in cells of the route is maximal.

Input
Line 1: contains 3 integers N, r and c (1 <= N <= 10, 1 <= r,c <= N)
Line i+1 (i = 1, 2, ..., N): contains the ith row of the matrix G

Output
Write the sum of the numbers of the cells visited by the knight in the route found.

Example
Input
4 1 1 
3  4  8  7    
0  3  0  0   
2  0 -10 0  
0 -4  0 10    


Output
31

Explanation: the route found is: (1,1) (2,3) (4,4) (3,2) (1,3) (3,4) (2,2) (1,4)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, sr, sc;
vector<vector<long long>> G;
vector<vector<int>> adj;
vector<bool> visited;
long long bestSum;

long long upperBound(int start, long long currentSum) {
    vector<bool> seen(N * N, false);
    queue<int> q;

    q.push(start);
    seen[start] = true;

    long long bound = currentSum;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (visited[v] || seen[v])
                continue;

            seen[v] = true;
            q.push(v);

            int r = v / N;
            int c = v % N;

            if (G[r][c] > 0)
                bound += G[r][c];
        }
    }

    return bound;
}

int availableDegree(int u) {
    int cnt = 0;

    for (int v : adj[u]) {
        if (!visited[v])
            cnt++;
    }

    return cnt;
}

void dfs(int u, long long currentSum) {
    bestSum = max(bestSum, currentSum);

    if (upperBound(u, currentSum) <= bestSum)
        return;

    vector<int> candidates;

    for (int v : adj[u]) {
        if (!visited[v])
            candidates.push_back(v);
    }

    sort(candidates.begin(), candidates.end(), [&](int a, int b) {
        int ra = a / N, ca = a % N;
        int rb = b / N, cb = b % N;

        long long va = G[ra][ca];
        long long vb = G[rb][cb];

        if ((va >= 0) != (vb >= 0))
            return va >= 0;

        int da = availableDegree(a);
        int db = availableDegree(b);

        if (da != db)
            return da < db;

        return va > vb;
    });

    for (int v : candidates) {
        visited[v] = true;

        int r = v / N;
        int c = v % N;

        dfs(v, currentSum + G[r][c]);

        visited[v] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> sr >> sc;

    G.assign(N, vector<long long>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> G[i][j];
    }

    int total = N * N;
    adj.assign(total, {});

    int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            int u = r * N + c;

            for (int k = 0; k < 8; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < N && nc >= 0 && nc < N)
                    adj[u].push_back(nr * N + nc);
            }
        }
    }

    sr--;
    sc--;

    int start = sr * N + sc;

    visited.assign(total, false);
    visited[start] = true;

    bestSum = G[sr][sc];

    dfs(start, G[sr][sc]);

    cout << bestSum;

    return 0;
}
//