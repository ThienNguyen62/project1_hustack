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
#include<bits/stdc++.h>
using namespace std;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<int> a(n+1);
    int maxVal=INT_MIN;
    int minVal=INT_MAX;
    long long total =0;
    
    for (int i =1;i<=n;i++)
    {
        cin >>a[i];
        maxVal = max(maxVal,a[i]);
        minVal = min(minVal,a[i]);
        total += a[i];
    }

    string s;
    cin>>s;

    while (cin>>s && s!= "***")
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
            int i,j;
            cin>>i>>j;
            int ans=a[i];
            for (int k =i+1;k<=j;k++)
            {
                ans = max(ans,a[k]);
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