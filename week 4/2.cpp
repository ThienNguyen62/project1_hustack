/*
Cho dãy số nguyên A1, A2, . . . , An với mỗi số nguyên Ai kiểm tra xem có số Aj nào bằng Ai hay không với j<i.
Input
Dòng đầu chứa số n (1≤n≤100,000)
Dòng hai chứa nn số nguyên A1, A2, ..., An (1≤Ai≤1000,000,000)
Output
Ghi ra n dòng, dòng thứ i in ra 1 nếu tồn tại Aj=Ai với j<i, ngược lại in ra 0.
Example
input
5
1 4 3 1 4
output
0
0
0
1
1

*/

/*
cho dãy a[i] kiểm tra vị trí j đã từng xuất hiện phần tử có giá trị 
bằng a[i] hay chưa
có in 1, không in 0*/
// #include<bits/stdc++.h>
// using namespace std;

// int main ()
// {
//     int n;
//     cin>>n;
//     vector <int> a(n);
//     for (int i =0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     for (int i =0;i<n;i++)
//     {
//         int found =0;
//         for ( int j =0; j<i;j++)
//         {
//             if(a[j]==a[i])
//             {
//                 found =1;
//                 break;
//             }
//         }
//         cout<<found<<'\n';
//     }
//     return 0;
// }
/*
kiểm tra vị trí i, j là các phần tử đứng trước j
giả xử ko có phần tử trùng found =0
so sánh 2 giá trị, thấy trung thì dừng*/

// dùng bảng băm

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<int> seen;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (seen.count(x)) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }

        seen.insert(x);
    }

    return 0;
}


/*
bảng băm lưu các giá trị không trùng nhau
hỗ trợ kiểm tra các phần tử có tồn tại không
*/