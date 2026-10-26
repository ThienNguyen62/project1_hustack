//2 Check Parenthesis
/*
Given a string containing only characters (, ), [, ] {, }. Write a program that checks whether the string is correct in expression.
Example
 ([]{()}()[]): correct
 ([]{()]()[]): incorrect
Input
One line contains the string (the length of the string is less than or equal to $10^6$)One line contains the string (the length of the string is less than or equal to 10
6
)
Output
Write 1 if the sequence is correct, and write 0, otherwise
Example
Input
(()[][]{}){}{}[][]({[]()})
Output
1
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) {
                cout << 0;
                return 0;
            }

            char t = st.top();
            st.pop();

            if ((c == ')' && t != '(') ||
                (c == ']' && t != '[') ||
                (c == '}' && t != '{')) {
                cout << 0;
                return 0;
            }
        }
    }

    cout << (st.empty() ? 1 : 0);
    return 0;
}
