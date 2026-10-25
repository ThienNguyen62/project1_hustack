/* Extract Year, Month, Date from a String YYYY-MM-DD
Given a date which is a string under the format YYYY-MM-DD (in which YYYY is the year, 
MM is the month (the month í from 1 to 12), and DD is the date (the date is from 1 to 31)). 
Extract the year, month and date.
Input
Line 1: contains a string s  
Output
if s is not under the format YYYY-MM-DD, then write INCORRECT. Otherwise, write year, month, 
and date separated by a SPACE character

Example
Input
2023-10-04
Output
2023 10 4


Input
2023-10-4
Output
INCORRECT 

Input
2023-10 04
Output
INCORRECT
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    //nhập chuỗi
    string s;
    getline(cin, s);

    // Kiểm tra độ dài và vị trí dấu -
    if (s.length() != 10 || s[4] != '-' || s[7] != '-') {
        cout << "INCORRECT";
        return 0;
    }

    // Kiểm tra các vị trí còn lại phải là chữ số
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7)
            continue;

        if (!isdigit(s[i])) {
            cout << "INCORRECT";
            return 0;
        }
    }

    // Tách năm, tháng, ngày
    // stoi là chuyển chuỗi thành số nguyên
    int year = stoi(s.substr(0, 4));
    int month = stoi(s.substr(5, 2));
    int day = stoi(s.substr(8, 2));

    // Kiểm tra phạm vi
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        cout << "INCORRECT";
        return 0;
    }

    cout << year << " " << month << " " << day;

    return 0;
}

/*
phân tích chuỗi
vị trí 0-3 là YYYY
vị trí 5-6 là MM
vị trí 8-9 là DD

validate chuỗi có đúng độ dài và dấu phân cách không
parse chuyển chuỗi thành số
cần in ra kết quả theo định dạng nào
*/
