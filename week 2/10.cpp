/*Permutation generation
Given an integer n, write a program to generate all permutations of 1, 2, ..., n in a lexicalgraphic order (elements of a permutation are separated by a SPACE character).
Example
Input 
3
Output
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 1 2 
3 2 1 
*/

/*
sinh hoán vị từ 1 đến n theo thứ tự từ điển tăng dần
giống bài nhị phân nhưng mỗi phần từ có thể chọn 1 đến n, mỗi giá trị chỉ
dùng đúng 1 lần */

#include<bits/stdc++.h>
using namespace std;
int n;
int a[20];
bool used[20];

void generate (int pos)
{
    if (pos == n)
    {
        for (int i =0;i<n;i++)
        {
            cout<<a[i]<<" ";

        }
        cout<<'\n';
        return;
    }
    for (int x=1 ;x<=n;x++)
    {
        if (used[x])
        {
        continue; // nếu x đã xuất hiện trong hoán vị, bỏ qua số đó
        }
        a[pos] = x;
        used [x]= true; // chọn x vào vị trí hiện tại và đánh dấu đã xử dụng
        generate(pos +1);
        used[x]=false; // khi nhánh đệ quy hoàn tất, bỏ đánh dấu để có thể xự dụng x trong một hoán bị khác
    }
    
}
int main() {
    cin >> n;
    generate(0);
    return 0;
}
/*
Chọn 1
  Chọn 2
    Chọn 3 → In 123
    Quay lui
  Quay lui
  Chọn 3
    Chọn 2 → In 132
    Quay lui
  Quay lui
Quay lui

Chọn 2
  ...
sử dụng backtracking nghĩ mình đang xây dựng cái gì
mỗi bước mình quyết định điều gì
có những lựa chọn nào
sau khi chọn mình sẽ làm gì*/

/*
void backtrack(int pos) {
    if (da_hoan_thanh) {
        // In hoặc đếm lời giải
        return;
    }

    for (int x : cac_lua_chon) {
        if (khong_hop_le(x))
            continue;

        // CHỌN
        cap_nhat_trang_thai(x);

        // ĐỆ QUY
        backtrack(pos + 1);

        // HOÀN TÁC
        khoi_phuc_trang_thai(x);
    }
}
*/











// // cách 2 dùng hàm có sẵn của thư viện algorithm, biến dãy hiện tại thành hoán ví kế tiếp theo thứ tự từ điển

// #include <iostream>
// #include <algorithm>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;

//     int a[20];

//     for (int i = 0; i < n; i++)
//         a[i] = i + 1;

//     do {
//         for (int i = 0; i < n; i++) {
//             if (i > 0) cout << " ";
//             cout << a[i];
//         }
//         cout << '\n';
//     } while (next_permutation(a, a + n));

//     return 0;
// }
/*
hàm tìm từ phải sáng trái vị trí đầu tiên i sao cho a[i]<a[i+1]
tìm từ phải sang trái phẩn tử đầu tiên lớn hơn a[i] , rồi hoán đổi
hai phần tử
đảo ngược đoạn phía sau vị trí i 

Dãy ban đầu:   1 3 2
Tìm i:         1 < 3  (i = 0)
Đổi 1 với 2:   2 3 1
Đảo phần sau:  2 1 3
*/