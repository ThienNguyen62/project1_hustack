/*Convert hh:mm:ss to seconds
Given a time moment which is a string under the format hh:mm:ss (in which hh (0 <= hh <= 23) is the hour, mm (0 <= mm <= 59) is the minute, and ss (0 <= ss <= 59) is the second). Convert this time moment in seconds (result = hh*3600 + mm*60 + ss).
Input
Line 1: contains a string s representing the time moment.  
Output
if s is not under the format hh:mm:ss, then write INCORRECT. Otherwise, write value converted.

Example
Input
13:05:26

Output
47126


Input
13:05:6

Output
INCORRECT 

Input
13:05 26

Output
INCORRECT
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    // Kiểm tra độ dài và vị trí dấu :
    if (s.length() != 8 || s[2] != ':' || s[5] != ':') {
        cout << "INCORRECT";
        return 0;
    }

    // Kiểm tra các ký tự còn lại phải là chữ số
    int pos[] = {0, 1, 3, 4, 6, 7};

    for (int i : pos) {
        if (!isdigit(s[i])) {
            cout << "INCORRECT";
            return 0;
        }
    }

    // Chuyển sang số
    int hh = (s[0] - '0') * 10 + (s[1] - '0');
    int mm = (s[3] - '0') * 10 + (s[4] - '0');
    int ss = (s[6] - '0') * 10 + (s[7] - '0');

    // Kiểm tra phạm vi
    if (hh > 23 || mm > 59 || ss > 59) {
        cout << "INCORRECT";
        return 0;
    }

    // Chuyển sang giây
    cout << hh * 3600 + mm * 60 + ss;

    return 0;
}
