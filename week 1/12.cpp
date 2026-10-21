/*List sequence of integer having 3 digits divisible by n
Given a positive integer n, find all integer having 3 digits which is divisible by n.
Input
Line 1: contains a positive integer n (1 <= n <= 999)
Output
Write the sequence of numbers found (elements are separated by a SPACE character)

Example
Input 
200

Output 
200 400 600 800
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 100; i <= 999; i++) {
        if (i % n == 0) {
            cout << i << " ";
        }
    }

    return 0;
}
