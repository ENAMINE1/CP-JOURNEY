// Date: 23-12-2024
// Start Time: 20:47:11
// End Time  : 20:58:26
// Time Taken: 11 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/problemset/problem/1703/F
// Rating: 1300
// Description: You are given an array a1,a2,…an Count the number of pairs of indices 1≤i,j≤n such that ai<i<aj<j
// Solved: No
// Learning: How to modify the array before applying Binsearch

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

/************************************************************************************************Main Function**************************************************/

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    vector<int> a;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] < i)
        {
            long long idx = 1LL * (lower_bound(a.begin(), a.end(), v[i]) - a.begin());
            debug(idx, v[i], a);
            res += idx;
            a.push_back(i);
        }
    }
    cout << res << endl;
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