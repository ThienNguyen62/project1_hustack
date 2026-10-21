/*Evaluate expression contains + * operand
Given a string representing a math expression including operator + and * and operands which are positive integers. Compute the value Q of this expression.
Input
Line 1: contains the string representing the expression (number of operators is upto 10000)
Output
Write the value Q modulo 10
9
+7 if the expression is mathematically correct in term of the syntax, and write NOT_CORRECT, otherwise
Example
Input
5+7*3*10*10
Output
2105
Input
5*+ 7*3*10*10
Output
NOT_CORRECT
*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const long long MOD = 1000000007;

int main() {
    string s;
    getline(cin, s);

    if (s.empty()) {
        cout << "NOT_CORRECT";
        return 0;
    }

    long long result = 0;
    long long product = 1;
    int i = 0;
    int n = s.size();
    bool expectNumber = true;

    while (i < n) {
        if (expectNumber) {
            if (!isdigit(s[i])) {
                cout << "NOT_CORRECT";
                return 0;
            }

            long long num = 0;
            bool positive = false;

            while (i < n && isdigit(s[i])) {
                if (s[i] != '0')
                    positive = true;

                num = (num * 10 + (s[i] - '0')) % MOD;
                i++;
            }

            if (!positive) {
                cout << "NOT_CORRECT";
                return 0;
            }

            product = (product * num) % MOD;
            expectNumber = false;
        } else {
            if (s[i] == '*') {
                expectNumber = true;
                i++;
            } else if (s[i] == '+') {
                result = (result + product) % MOD;
                product = 1;
                expectNumber = true;
                i++;
            } else {
                cout << "NOT_CORRECT";
                return 0;
            }
        }
    }

    if (expectNumber) {
        cout << "NOT_CORRECT";
        return 0;
    }

    result = (result + product) % MOD;

    cout << result;

    return 0;
}
