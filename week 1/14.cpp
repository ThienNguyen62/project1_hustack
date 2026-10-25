/* Solve degree-2 polynomial equation
Given an equation ax^2 + bx + c = 0. Find solution to the given equation.
Input
Line 1 contains 3 integers a, b, c 
Output
Write NO SOLUTION if the given equation has no solution 
Write x0 (2 digits after the decimal point) if the given equation has one solution x0 
Write x1 and x2 with x1 < x2 (2 digits after the decimal point) if the given equation
 has two distinct solutions x1, x2 

Example
Input 
1 1 8
Output 
NO SOLUTION 


Input 
1 -2 1
Output
1.00

Input 
1 -7 10
Output 
2.00 5.00
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    // Trường hợp phương trình bậc nhất
    if (a == 0) {
        if (b == 0) {
            cout << "NO SOLUTION";
        } else {
            double x = -c / b;
            cout << fixed << setprecision(2) << x;
        }
        return 0;
    }

    // Phương trình bậc hai
    double delta = b * b - 4 * a * c;

    if (delta < 0) {
        cout << "NO SOLUTION";
    }
    else if (delta == 0) {
        double x = -b / (2 * a);
        cout << fixed << setprecision(2) << x;
    }
    else {
        double x1 = (-b - sqrt(delta)) / (2 * a);
        double x2 = (-b + sqrt(delta)) / (2 * a);

        if (x1 > x2)
            swap(x1, x2);

        cout << fixed << setprecision(2) << x1 << " " << x2;
    }

    return 0;
}
