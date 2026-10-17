/*
Given a string s[1…k] which is a sequence of characters taken from {‘a’, . . ., ‘z’}. Given a positive integer m, the hash code of s is defined by the formula:
H(s) =  (s[1]*256^(k-1) + s[2]*256^(k-2) + . . . + s[k]*256^0) mod m  (the contant integer m is a parameter)
Given a sequence of strings k1, k2, …, kn, compute the corresponding hash codes
Input
Line 1: n and m (1 <= n,m <= 100000)
Line i+1 (i = 1,2,…,n): contains the string ki (the length of each string is less than or equal to 200)
Output
Each line contains the corresponding hash code of n given strings
Example
Input
4 1000
a
ab
abc
abcd
Output
97
930
179
924*/

/*
bài này dùng bảng băm
cái khó là chuyển công thức thành thuật toán, không tràn số
cho một chuỗi s gồm k kí tự từ 'a' đến 'z'

mã băng được định nghĩa là 
H(s) = tổng từ i=1 đên k của (s[i]x 256^(k-1))

với s[i] là giá trị mã số kí tự tại vị trí i
k là độ dài chuỗi
256 là cơ số tính hash
m là số dương để lấy phần dư
H(s) là mã băm cuối cùng, từ 0 đến m-1






*/

// #include <iostream>
// #include<string>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n,m;
//     cin>>n>>m;
//     for (int i =0; i<n;i++)
//     {
//         string s;
//         cin>>s;
//         long long hash =0; // 0<= hash<=m<= 100000
//         for ( char c:s)
//         {
//             hash = (hash*256+c)%m;
//         }
//         cout<<hash<<'\n';
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<string, int> mp;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (mp.find(s) == mp.end()) {
            int h = 0;

            for (char c : s) {
                h = (h * 256 + c) % m;
            }

            mp[s] = h;
        }

        cout << mp[s] << '\n';
    }

    return 0;
}
