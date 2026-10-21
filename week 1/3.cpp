/*Compare money deposited of 2 periods
Cho dãy số nguyên a[1], a[2], . . ., a[n] trong đó a[i] là số tiền khách hàng gửi vào ngân hàng trong ngày i (i = 1, 2, . . ., n). Ta cần xử lý m truy vấn, mỗi truy vấn được biểu diễn bởi 4 chỉ số i1, j1, i2 và j2: kết quả của truy vấn bằng 1 nếu tổng số tiền khách hàng gửi trong giai đoạn từ ngày i1 đến ngày j1 nhỏ hơn tổng số tiền khách gửi trong giai đoạn từ ngày i2 đến ngày j2, ngược lại thì kết quả truy vấn bằng 0.

Input 
Dòng 1: chứa 3 số nguyên dương n  (1 <= n <= 100000)
Dòng 2: chứa n số nguyên a[1], a[2],  . . ., a[n] (1 <= a[i] <= 1000)
Dòng 3: chứa số nguyên dương m (1 <= m <= 1000000)
Dòng 3+k (k = 1, 2,. . ., m): chứa 4 số nguyên i1, j1, i2 và j2 là các tham số của truy vấn thứ k 

Output 
Dòng k (k = 1, . . ., m): ghi ra kết quả của truy vấn thứ k

Example 
Input
5
7 6 2 4 1
4
1 3 2 4
1 5 3 4
2 3 1 3
3 5 2 4

Output
0
0
1
1

Giải thích:
Truy vấn 1: tổng số tiền khách gửi trong giai đoạn từ ngày 1 đến ngày 3 là 7 + 6 + 2 = 15, tổng số tiền khách gửi trong giai đoạn từ ngày 2 đến ngày 4 là 6+2+4 = 12, kết quả truy vấn bằng 0 (vì 15 > 12)
Truy vấn 2: tổng số tiền khách gửi trong giai đoạn từ ngày 1 đến ngày 5 là 7 + 6 + 2 + 4 + 1 = 20, tổng số tiền khách gửi trong giai đoạn từ ngày 3 đến ngày 4 là 2+4 = 6, kết quả truy vấn bằng 0 (vì 20 > 6)

Tương tự như vậy đối với truy vấn 3 và 4.




*/
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long prefix[100005];

    prefix[0] = 0;

    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;

        prefix[i] = prefix[i - 1] + x;
    }

    int m;
    cin >> m;

    while (m--) {
        int i1, j1, i2, j2;

        cin >> i1 >> j1 >> i2 >> j2;

        long long sum1 = prefix[j1] - prefix[i1 - 1];
        long long sum2 = prefix[j2] - prefix[i2 - 1];

        if (sum1 < sum2)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }

    return 0;
}
