/*Binary sequences generation without consecutive 11
Given an integer n, write a program that generates all binary sequences without consecutive 11 in a lexicographic order.
Input
Line 1: contains an integer n (1 <= n <= 20)
Output
Write binary sequences in a lexicographic order, each sequence in a line
Example
Input
3
Output
000
001
010
100
101
*/

// in ra dãy nhị phân không có 2 số 1 liên tiếp
#include <iostream>
using namespace std;

int n;
int a[25];

void generate(int pos) {
    if (pos == n) {
        for (int i = 0; i < n; i++) {
            cout << a[i];
        }
        cout << '\n';
        return;
    }

    a[pos] = 0;
    generate(pos + 1);

    if (pos == 0 || a[pos - 1] == 0) {
        a[pos] = 1;
        generate(pos + 1);
    }
}

int main() {
    cin >> n;
    generate(0);
    return 0;
}
/*
nếu pos == 0 thì in dãy rồi trở về hàm gọi
thử đặt 0 tại pos và đệ quy
khi nhánh 0 hoàn tất, kiểm tra điền kiển và thử đặt 1
nếu hợp lệ, gán 1 rồi tiếp tục đề quy

bị chặn là không đi tiếp vào nhánh đó, không tin kết quả

a[0] = 0
  a[1] = 0
    a[2] = 0  → IN 000
    a[2] = 1  → IN 001
  a[1] = 1
    a[2] = 0  → IN 010
    a[2] = 1  → BỊ CHẶN
a[0] = 1
  a[1] = 0
    a[2] = 0  → IN 100
    a[2] = 1  → IN 101
  a[1] = 1    → BỊ CHẶN
*/