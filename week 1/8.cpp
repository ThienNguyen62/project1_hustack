/*Evaluate expression only + operators
Given a string representing a math expression including operator +  and operands (positive integers). 
Compute the value Q of this expression.
Input
Line 1: contains the string representing the expression (number of operators is upto 10000)
Output
Write the value Q modulo 109+7 if the expression is mathematically correct in term of the syntax, 
and write NOT_CORRECT, otherwise
Example
Input
2+1+7+4
Output
14
Input
2+1+7+4 +
Output
NOT_CORRECT
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);

    const long long MOD = 1000000007;

    long long sum = 0;
    long long num = 0;
    bool hasDigit = false;

    for (char c : s) {
        if (isdigit(c)) {
            num = (num * 10 + (c - '0')) % MOD;
            hasDigit = true;
        }
        else if (c == '+') {
            // Không có số trước dấu +
            if (!hasDigit) {
                cout << "NOT_CORRECT";
                return 0;
            }

            sum = (sum + num) % MOD;
            num = 0;
            hasDigit = false;
        }
        else {
            // Gặp ký tự không hợp lệ, kể cả SPACE
            cout << "NOT_CORRECT";
            return 0;
        }
    }

    // Biểu thức rỗng hoặc kết thúc bằng +
    if (!hasDigit) {
        cout << "NOT_CORRECT";
        return 0;
    }

    sum = (sum + num) % MOD;

    cout << sum;

    return 0;
}
