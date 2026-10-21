/*Compute C_k_n
Given two positive integers k and n. Compute C(k,n) which is the number of ways to select k objects from a given set of n objects.
Input
Line 1: two positive integers k and n (1 <= k,n <= 999)
Output
Write te value C(k,n) modulo 10
9
+7.
Example
Input
3  5
Output
10
*/
#include <iostream>
using namespace std;

const long long MOD = 1000000007;

int main() {
    int k, n;
    cin >> k >> n;

    if (k > n) {
        cout << 0;
        return 0;
    }

    long long C[1000] = {0};
    C[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j >= 1; j--) {
            C[j] = (C[j] + C[j - 1]) % MOD;
        }
    }

    cout << C[k];

    return 0;
}
