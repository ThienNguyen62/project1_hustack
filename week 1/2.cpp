/*
Given a sequence of integers a1, a2, ..., an. Perform a sequence of queries over this sequence including:
find-max: return the maximum element of the given sequence
find-min: return the minimum element of the given sequence 
sum: return the sum of the elements of the given sequence 
find-max-segment i j: return the maximum element of the subsequence from index i to index j (i <= j)

Input
The first block contains the information about the given sequence with the following format:
Line 1: contains a positive integer n (1 <= n <= 10000)
Line 2: contains n integers a1, a2, ..., an (-1000 <= ai <= 1000)
The first block is terminated by a character *
The second block contains a sequence of queries defined above, each query is in a line. The second block is terminated a 3 characters ***

Output
Write the result of each query in a corresponding line
 
Example
Input
5
1 4 3 2 5
*
find-max
find-min
find-max-segment 1 3
find-max-segment 2 5
sum
***

Output
5
1
4
5
15
*/


/*
mảng, vòng lặp, điều kiện, truy vấn
*/


/*
==================================================
Phân tích bài toán:
==================================================

Cho mảng gồm n số nguyên.

Cần xử lý 4 loại truy vấn:

1. find-max:
   Tìm giá trị lớn nhất của mảng.

2. find-min:
   Tìm giá trị nhỏ nhất của mảng.

3. sum:
   Tính tổng các phần tử.

4. find-max-segment i j:
   Tìm phần tử lớn nhất trong đoạn [i, j].

Lưu ý:
- Chỉ số mảng bắt đầu từ 1.
- Mảng không thay đổi sau khi nhập.
- Có thể có nhiều truy vấn.
- Dừng khi gặp "***".


==================================================
Ý tưởng giải thuật:
==================================================

Bước 1:
Nhập mảng gồm n phần tử.

Bước 2:
Duyệt mảng một lần để tính:
- Giá trị lớn nhất.
- Giá trị nhỏ nhất.
- Tổng các phần tử.

Bước 3:
Xây dựng Sparse Table để hỗ trợ truy vấn
giá trị lớn nhất trên một đoạn bất kỳ.

Định nghĩa:

st[k][i] là giá trị lớn nhất của đoạn bắt đầu
tại i và có độ dài 2^k.

Công thức:

st[k][i] = max(
    st[k-1][i],
    st[k-1][i + 2^(k-1)]
)

Bước 4:
Đọc lần lượt các truy vấn.

- find-max: xuất max đã tính.
- find-min: xuất min đã tính.
- sum: xuất tổng đã tính.
- find-max-segment: truy vấn Sparse Table.

Bước 5:
Kết thúc khi gặp "***".


==================================================
Độ phức tạp:
==================================================

Gọi n là số phần tử, q là số truy vấn.

Tiền xử lý:
- Thời gian: O(n log n).
- Bộ nhớ: O(n log n).

Mỗi truy vấn:
- find-max: O(1).
- find-min: O(1).
- sum: O(1).
- find-max-segment: O(1).

Tổng thời gian: O(n log n + q).

*/
#include<bits/stdc++.h>
using namespace std;

int main ()
{
    // tăng tốc độ nhập
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<int> a(n+1); // tạo vector có n phần tử
    int maxVal=INT_MIN;  // đảm bảo mọi giá trị hợp lệ trong mảng >= maxVal
    int minVal=INT_MAX;   // đảm bảo mọi giá trị hợp lệ trong mảng <= minVal
    long long total =0;
    
    for (int i =1;i<=n;i++)
    {
        cin >>a[i];
        maxVal = max(maxVal,a[i]);  // so sánh max hiện tại với phần tử vừa nhập
        minVal = min(minVal,a[i]);  // so sánh min hiện tại với phần tử với nhập
        total += a[i];
    }

    string s;
    cin>>s;

    while (cin>>s && s!= "***") // đọc thành công 1 chuỗi và chuỗi vừa đọc khác ***
    {
        if (s == "find-max")
        {
            cout<< maxVal <<'\n';
        }
        else if (s== "find-min")
        {
            cout<< minVal <<'\n';
        }
        else if (s == "sum")
        {
            cout<< total<<'\n';
        }
        else if (s=="find-max-segment")
        {
            int i,j; // nhập hai vị trí
            cin>>i>>j;
            int ans=a[i];
            for (int k =i+1;k<=j;k++)
            {
                ans = max(ans,a[k]);  // liên tục cập nhật ans
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}

/*
giải thích chương trình

ios::sync_with_stdio(false);
cin.tie(nullptr);
*/