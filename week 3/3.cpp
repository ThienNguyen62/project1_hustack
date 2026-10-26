//3 Evaluate add - mul - parenthesis expression
/*
Given a string representing a math expression including operator + and * and operands which are positive integer and parentheses. Compute the value Q of this expression.
Input
Line 1: contains the string representing the expression (number of operators is upto 10000)
Output
Write the value Q modulo 10
9
+7 if the expression is mathematically correct in term of the syntax, and write NOT_CORRECT, otherwise
Example
Input
(2+4*10)*(5) + 7
Output
217

Input
((2+4*10)*(5) + 7
Output
NOT_CORRECT

*/

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
string s;
int pos = 0;
bool valid = true;

void skipSpaces() {
    while (pos < (int)s.size() && isspace(s[pos]))
        pos++;
}

long long expression();

long long factor() {
    skipSpaces();

    if (pos >= (int)s.size()) {
        valid = false;
        return 0;
    }

    if (s[pos] == '(') {
        pos++;
        long long val = expression();
        skipSpaces();

        if (pos >= (int)s.size() || s[pos] != ')') {
            valid = false;
            return 0;
        }

        pos++;
        return val;
    }

    if (!isdigit(s[pos])) {
        valid = false;
        return 0;
    }

    long long val = 0;

    while (pos < (int)s.size() && isdigit(s[pos])) {
        val = (val * 10 + s[pos] - '0') % MOD;
        pos++;
    }

    return val;
}

long long term() {
    long long val = factor();

    while (valid) {
        skipSpaces();

        if (pos >= (int)s.size() || s[pos] != '*')
            break;

        pos++;
        long long next = factor();
        val = val * next % MOD;
    }

    return val;
}

long long expression() {
    long long val = term();

    while (valid) {
        skipSpaces();

        if (pos >= (int)s.size() || s[pos] != '+')
            break;

        pos++;
        long long next = term();
        val = (val + next) % MOD;
    }

    return val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    getline(cin, s);

    long long ans = expression();
    skipSpaces();

    if (!valid || pos != (int)s.size())
        cout << "NOT_CORRECT";
    else
        cout << ans;

    return 0;
}
