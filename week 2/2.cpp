/*Binary sequences generation without consecutive 11
Given an integer n, write a program that generates all binary sequences without consecutive 11 in a lexicographic order.
Input
Line 1: contains an integer n (1 <= n <= 20)
Output
Write binary sequences in a lexicographic order, each sequence in a line
Example
Input
3
Output
000
001
010
100
101
*/
#include <iostream>
using namespace std;

int n;
int a[25];

void generate(int pos) {
    if (pos == n) {
        for (int i = 0; i < n; i++) {
            cout << a[i];
        }
        cout << '\n';
        return;
    }

    a[pos] = 0;
    generate(pos + 1);

    if (pos == 0 || a[pos - 1] == 0) {
        a[pos] = 1;
        generate(pos + 1);
    }
}

int main() {
    cin >> n;
    generate(0);
    return 0;
}
