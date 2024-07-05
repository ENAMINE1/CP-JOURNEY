// Date: 05-07-2024
// Start Time: 09:55:34
// End Time  : 10:51:32
// Time Taken: 55 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/problemset/problem/1931/D
// Rating: 1300
// Description: find number of pairs in the array such that their sum is divisible by x and their difference is divisible by b
// Solved: No
// Learning: How to use map to store history that too with 2 simlutaneous condition

/****************************************************Pre Processor***************************************************/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#include "./lib/print.h"
#include "./lib/debug.h"
#else
#define debug(...) 42
#endif
#define endl '\n'

/***************************************************Main Function**************************************************/

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    map<pair<int, int>, long long> fr;
    long long cnt = 0;
    /*
    Since (ai+aj)modx=0 , it follows that (aimodx+ajmodx)modx=0 , which implies that aimodx+ajmodx is either x or 0
    . Therefore, for some j, this holds true if aimodx=(x−ajmodx)modx .

    Since (ai−aj)mody=0, it follows that aimody−ajmody=0, which implies that aimody=ajmody.

    Thus, for some fixed aj, all ai will fit the following criteria:
    i<j;
    ai mod x=(x−aj mod x)mod x;
    ai mod y=aj mod y.
    */
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        cnt += fr[{((a - temp % a) % a + a) % a, temp % b}];
        fr[{temp % a, temp % b}]++;
    }
    cout << cnt << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
#ifdef LOCAL
        std::cerr << "Case # " << i << endl;
        std::cout << "Case #" << i << endl;
#endif
        solve();
    }
    return 0;
}