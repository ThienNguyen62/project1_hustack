/*Count words
Given a Text, write a prorgam to count the number Q of words (ignore characters SPACE, TAB, LineBreak) 
of this Text

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

/*
đếm số từ in ra số lượng từ Q , ngoài space, tab, và linebreak
một từ là một chuỗi ký tự liên tiếp
đọc được một từ thì tăng lên 1
không cần viết chương trình bỏ qua space,tab,linebreak vì cin duyệt theo từ
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
