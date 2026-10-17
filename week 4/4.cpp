/*Sum pair of sequence equal to a number
Cho dãy a1, a2, ..., an trong đó các phần tử đôi một 
khác nhau và 1 giá trị nguyên dương M. Hãy đếm số Q 
các cặp (i,j) sao cho 1 <= i < j <= n và ai + aj = M.

Dữ liệu
Dòng 1: ghi n và M (1 <= n, M <= 1000000)
Dòng 2: ghi a1, a2, ..., an
Kết quả
Ghi ra giá trị Q
Ví dụ
Dữ liệu
5 6
5 2 1 4 3
Kết quả
2

*/

#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,M;
    cin>>n >>M;

    unordered_set<long long> seen;
    long long Q =0;

    for ( int i =0;i<n;i++)
    {
        long long x;
        cin >> x;
        if ( seen.count (M-x))
        {
            Q++;
        }
        seen.insert(x);
    }
    cout<<Q;
    return 0;
}
/*

cho n số nguyên khác nhau , đếm số cặp (i,j) sao cho i<j và a[i]+a[j]=M
mỗi cặp đếm 1 lần
a[j]= M-a[i]
dùng unordered_set để ghi nhớ các số đã suất hiện
tính M-x, kiểm tra số đó trong seen không, có thì Q++ và thêm x và seen

*/