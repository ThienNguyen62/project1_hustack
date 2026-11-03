/*Generate all ways to represent N as the sum of positive integers
Given a positive integer N, generate all the ways to represent N as the sum of positive integers.
         N = x[1] + x[2] + . . . + x[k]  with 1 <= x[1] <= x[2] <= . . . <= x[k]

Input
Line 1: contains a positive integer N (1 <= N <= 20)

Output
Each line contains a sequence of positive integers sorted in non-decreasing order such that the sum is equal to N
(solutions are displayed in a lexicographic order)

Example
Input
4

Output 
1 1 1 1
1 1 2
1 3
2 2
4
*/

// phân tích N thành tổng các số nguyên dương - backtracking
/*
bài toán này thêm tự duy không phải lúc nào đệ quy cũng dùng pos +! la fdudr, đôi khi phải truyền thêm
trạng thái để kiểm soát những lựa chọn tiếp theo
*/
#include <iostream>
using namespace std;

int N;
int x[25];

void generate(int pos, int remaining, int minValue) {
    if (remaining == 0) {
        for (int i = 0; i < pos; i++) {
            if (i > 0) cout << " ";
            cout << x[i];
        }
        cout << '\n';
        return;
    }

    for (int v = minValue; v <= remaining; v++) {
        x[pos] = v;
        generate(pos + 1, remaining - v, v);
    }
}

int main() {
    cin >> N;
    generate(0, N, 1);
    return 0;
}
//