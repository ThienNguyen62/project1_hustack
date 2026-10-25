/*k-Subsequence even
Given a sequence of integers a1, a2, . . ., an. A k-subsequence is define to be a sequence 
of k consecutive elements: ai, ai+1, . . ., ai+k-1. The weight of a k-subsequence is the sum of its elements.
Given positive integers k and m. Compute the number Q of k-subsequences such that the weight is even.
Input
Line 1: contains 2 positive integers n, k (1 <= n <= 100000, 1 <= k <= n/2)
Line 2: contains a1, a2, . . ., an. (1 <= ai <= 10000)
Output
Write the value Q
Example
Input
6  3
2 4 5 1 1 2 
Output
2
*/

/*
cho một số dãy gồm n số nguyên
k là dãy con các k phần tử luên tiếp trong dãy ban đầu
yêu cầu tính số lượng Q các dãy con gồm đúng k phần tử liên tiế sao cho
tổng các phần tử của dãy con là một số chẵn
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    // tạo ra dãy có kích thước xác định khi chương trình chạy
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long sum = 0;
    int Q = 0;

    // Tổng của k phần tử đầu tiên
    for (int i = 0; i < k; i++) {
        sum += a[i];
    }
    // tổng chẵn thì tăng nhóm hợp lệ lên 1
    if (sum % 2 == 0)
        Q++;

    // Trượt cửa sổ sang phải
    for (int i = k; i < n; i++) {
        sum = sum - a[i - k] + a[i]; // tổng mới bằng tổng cũ - số bị bỏ rơi + số được thêm

        if (sum % 2 == 0)
            Q++;
    }

    cout << Q;

    return 0;
}

/*
xét nhóm k phần tử liên tiếp
tôi cần một biến sum để lưu tổng của nhóm đang xét
tôi cần tính tổng nhóm đầu tiên bằng vòng lặp từ 0 đến k-1
muốn xét nhóm tiếp theo phải bỏ một phần tử cũ và thêm một phần tử mới
tôi dùng vòng lặp từ i =k đến i<n để lần lượt thêm các phần tử mới
sau mỗi lần có tổng , kiểm tra sum %2 == 0 để tăng Q
*/
