/*k-Subsequence even
Given a sequence of integers a1, a2, . . ., an. A k-subsequence is define to be a sequence of k consecutive elements: ai, ai+1, . . ., ai+k-1. The weight of a k-subsequence is the sum of its elements.
Given positive integers k and m. Compute the number Q of k-subsequences such that the weight is even.
Input
Line 1: contains 2 positive integers n, k (1 <= n <= 100000, 1 <= k <= n/2)
Line 2: contains a1, a2, . . ., an. (1 <= ai <= 10000)
Output
Write the value Q
Example
Input
6  3
2 4 5 1 1 2 
Output
2
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long sum = 0;
    int Q = 0;

    // Tổng của k phần tử đầu tiên
    for (int i = 0; i < k; i++) {
        sum += a[i];
    }

    if (sum % 2 == 0)
        Q++;

    // Trượt cửa sổ sang phải
    for (int i = k; i < n; i++) {
        sum = sum - a[i - k] + a[i];

        if (sum % 2 == 0)
            Q++;
    }

    cout << Q;

    return 0;
}
