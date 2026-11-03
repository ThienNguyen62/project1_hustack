/*Binary sequence generation
Given an integer n, write a program that generates all the binary sequences of length n in a lexicographic
order.
Input
Line 1: contains an integer n (1 <= n <= 20)
Output
Write binary sequences in a lexicographic ordder, eac sequence in a line

Example
Input
3
Output
000
001
010
011
100
101
110
111
*/
#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void generate(int pos) {
    if (pos == n) {
        cout << s << '\n';
        return;
    }

    s[pos] = '0';
    generate(pos + 1);

    s[pos] = '1';
    generate(pos + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    s.resize(n); // khởi tạo chuỗi n ký tự để có thể gán trực tiếp s[pos]
    generate(0);

    return 0;
}

/*
bài toán tạo ra dãy độ dài n có thể chia thành các bài toán nhỏ hơn
chọn giá trị tại vị trí hiện tại , sau đó tạo tiếp các vị trí còn lại

hàm generate (pos)
nếu pos == n thì toàn bộ vị trí từ 0 đến n-1 đã được gán

2 chương trình đệ quy
thử xem tại vị trí hiện tại và sinh rất cả dãy bắt đầu bằng tiến tố đọ
sau khi hoàn thành nó đổi vị trị hiện tại thành 1 và sinh các dãy còn lại


Mindset
n=3
0	000
1	001
2	010
3	011
4	100
5	101
6	110
7	111


generate(0)
│
├── s[0] = '0'
│   └── generate(1)
│       │
│       ├── s[1] = '0'
│       │   └── generate(2)
│       │       ├── s[2] = '0' → generate(3) → IN 000
│       │       └── s[2] = '1' → generate(3) → IN 001
│       │
│       └── s[1] = '1'
│           └── generate(2)
│               ├── s[2] = '0' → generate(3) → IN 010
│               └── s[2] = '1' → generate(3) → IN 011
│
└── s[0] = '1'
    └── generate(1)
        │
        ├── s[1] = '0'
        │   └── generate(2)
        │       ├── s[2] = '0' → generate(3) → IN 100
        │       └── s[2] = '1' → generate(3) → IN 101
        │
        └── s[1] = '1'
            └── generate(2)
                ├── s[2] = '0' → generate(3) → IN 110
                └── s[2] = '1' → generate(3) → IN 111



điểm mấu chốt. tại vị trí nào bạn cũng thực hiện một công việc giống nhau
chọn 1 trong hai vị trí 0 hoặc 1 cho vị trí hiện tại , rồi tiếp tục giải quyết vị trí tiếp theo

*/