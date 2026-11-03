/*Count number of sudoku solutions
Write a program to compute the number of sudoku solutions (fill the zero elements of a given partial sudoku table)
Fill numbers from 1, 2, 3, .., 9 to 9 x 9 table so that:
Numbers of each row are distinct
Numbers of each column are distinct
Numbers on each sub-square 3 x 3 are distinct
Input
Each line i (i = 1, 2, ..., 9) contains elements of the i
th
 row of the Sudoku table: elements are numbers from 0 to 9 (value 0 means the empty cell of the table)
Output
Write the number of solutions found

Example
Input
0 0 3 4 0 0 0 8 9
0 0 6 7 8 9 0 2 3
0 8 0 0 2 3 4 5 6
0 0 4 0 6 5 0 9 7
0 6 0 0 9 0 0 1 4
0 0 7 2 0 4 3 6 5
0 3 0 6 0 2 0 7 8
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
Output
64
*/

/*
bài toán đếm số lời giải soduku -backtracking + bitmask
khác bài nhị phân thì bài này nhiều nhánh hơn, mỗi ô chọn từ 1 đến 9
các điều kiện ràng buộc
9x9 gồm 81 ô
3 điều kiện là mỗi hàng không được trùng số từ 1 đến 9, mỗi cột không được trùng 
số, mỗi số trong ô vuông 3x3 không được trùng số

*/
#include <iostream>
using namespace std;

int a[9][9];
int rowMask[9], colMask[9], boxMask[9];
unsigned __int128 ans = 0;

void solve() {
    int bestR = -1, bestC = -1;
    int bestMask = 0;
    int minOptions = 10;

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (a[r][c] == 0) {
                int b = (r / 3) * 3 + c / 3;
                int mask = (~(rowMask[r] | colMask[c] | boxMask[b])) & 0x3FE;
                int cnt = __builtin_popcount(mask);

                if (cnt == 0)
                    return;

                if (cnt < minOptions) {
                    minOptions = cnt;
                    bestR = r;
                    bestC = c;
                    bestMask = mask;
                }
            }
        }
    }

    if (bestR == -1) {
        ans++;
        return;
    }

    int b = (bestR / 3) * 3 + bestC / 3;

    for (int d = 1; d <= 9; d++) {
        int bit = 1 << d;

        if (bestMask & bit) {
            a[bestR][bestC] = d;
            rowMask[bestR] |= bit;
            colMask[bestC] |= bit;
            boxMask[b] |= bit;

            solve();

            a[bestR][bestC] = 0;
            rowMask[bestR] ^= bit;
            colMask[bestC] ^= bit;
            boxMask[b] ^= bit;
        }
    }
}

void print128(unsigned __int128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }

    string s;

    while (x > 0) {
        s += char('0' + x % 10);
        x /= 10;
    }

    for (int i = s.size() - 1; i >= 0; i--)
        cout << s[i];
}

int main() {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            cin >> a[r][c];

            if (a[r][c] != 0) {
                int d = a[r][c];
                int bit = 1 << d;
                int b = (r / 3) * 3 + c / 3;

                if ((rowMask[r] & bit) ||
                    (colMask[c] & bit) ||
                    (boxMask[b] & bit)) {
                    cout << 0;
                    return 0;
                }

                rowMask[r] |= bit;
                colMask[c] |= bit;
                boxMask[b] |= bit;
            }
        }
    }

    solve();
    print128(ans);

    return 0;
}
/*
ý tưởng : thay vì duyệt từng hàng, cột , ô vuông 3x3 để kiểm tra xem số có bị trùng hay không
ta dùng các bit để lưu những số đã xuất hiện
int mask = (~(rowMask[r] | colMask[c] | boxMask[b])) & 0x3FE;
 | để gộp tất cả các số xuất hiển ở hàng , cột, ô 3x3
 ~ để đảo bit, lấy những số chưa xuất hiện
 dùng &0x3fe để chỉ giữ các bit từ 1 đến 9

*/