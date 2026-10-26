//9 WATER JUGS
/*
here are two jugs, a-litres jug and b-litres jug (a, b are positive integers). There is a pump with unlimited water. Given a positive integer c, how to get exactly c litres.
Input
   Line 1: contains positive integers a,   b,  c  (1 <= a, b, c <= 900)
Output
  write the number of steps or write -1 (if no solution found)
Example

Input
6  8  4
Output
4

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    if (c > max(a, b) || c % gcd(a, b) != 0) {
        cout << -1;
        return 0;
    }

    vector<vector<int>> dist(a + 1, vector<int>(b + 1, -1));
    queue<pair<int, int>> q;

    q.push({0, 0});
    dist[0][0] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        int d = dist[x][y];

        if (x == c || y == c) {
            cout << d;
            return 0;
        }

        int t1 = min(x, b - y);
        int t2 = min(y, a - x);

        vector<pair<int, int>> next = {
            {a, y},
            {x, b},
            {0, y},
            {x, 0},
            {x - t1, y + t1},
            {x + t2, y - t2}
        };

        for (auto [nx, ny] : next) {
            if (dist[nx][ny] == -1) {
                dist[nx][ny] = d + 1;
                q.push({nx, ny});
            }
        }
    }

    cout << -1;
    return 0;
}
