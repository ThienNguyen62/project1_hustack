/*Binary sequence generation
Given an integer n, write a program that generates all the binary sequences of length n in a lexicographic
order.
Input
Line 1: contains an integer n (1 <= n <= 20)
Output
Write binary sequences in a lexicographic ordder, eac sequence in a line

Example
Input
3
Output
000
001
010
011
100
101
110
111
*/
#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void generate(int pos) {
    if (pos == n) {
        cout << s << '\n';
        return;
    }

    s[pos] = '0';
    generate(pos + 1);

    s[pos] = '1';
    generate(pos + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    s.resize(n);
    generate(0);

    return 0;
}
