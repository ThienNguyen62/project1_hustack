/* Sum Array
Given a sequence of integers a1, a2, ..., an. Compute the sum Q of elements of this sequence.
Input
Line 1: contains n (1 <= n <= 1000000)
Line 2: contains a1, a2, ..., an (-10000 <= ai <= 10000)
Output
Write the value of Q
Example
Input
4
3 2 5 4
Output
14*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long sum = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
    }

    cout << sum;

    return 0;
}
