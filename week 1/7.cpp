/*Count words
Given a Text, write a prorgam to count the number Q of words (ignore characters SPACE, TAB, LineBreak) of this Text

Input
The Text

Output
Write the number Q of words

Example
Input
Hanoi University Of Science and Technology
School of Information and Communication Technology


Output
12
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int count = 0;

    while (cin >> s) {
        count++;
    }

    cout << count;

    return 0;
}
