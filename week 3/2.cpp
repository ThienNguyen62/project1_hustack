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
/*
chuỗi hợp lệ phải thỏa mãn
- mỗi dấu mở phải có dấu đóng tương ứng
- dấu ngoặc phải đóng đúng loại
- các cặp ngoặc phải lồng nhau đúng thứ tự
- không được có dấu mở hoặc đóng dư
in ra 1 nếu hợp lệ, ngược lại in o
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> st;  // khởi tạo stack

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) {
                cout << 0;
                return 0;
            }

            char t = st.top(); // lấy dấu mở gần nhất
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
/*
stack là cấu trúc theo nguyên tắc lifo
3 thao tác 
st.push ()
st.top ()
st.pop ()
st.empty()


chương trình nhập chuỗi s và tạo 1 stack rỗng st
duyệt từng kí tự trong chuỗi bằng for
nếu gặp dấu mở ( [ { đưa vào stack bằng st.push (c) để ghi nhớ
nếu gặp dấu đống ) ] }
+ stack rỗng in ra 0 để kết thức
+ stack không rỗng thì lấy dấu mở trên đỉnh bằng top (), sau đó so sánh
+ nếu 2 dấu không khớp, in ra 0, kết thúc
+ nếu khớp thì tiếp tục duyệt
sau khi duyệt hết chuỗi
stack rỗng tất cả ghép đúng in ra 1
stack còn phần tử có dấu mở được được đóng*/