/*
Convert a TEXT to Upper-Case
Given a TEXT, write a program that converts the TEXT to upper-case. 

Input
The TEXT

Output
The TEXT in which characters are converted into upper-case

Example 
Input 
Hello John,
How are you?

Bye,

Output 
HELLO JOHN,
HOW ARE YOU?

BYE, 
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;

    while (getline(cin, s)) {
        for (char &c : s) {
            c = toupper((unsigned char)c);
        }

        cout << s << '\n';
    }

    return 0;
}
