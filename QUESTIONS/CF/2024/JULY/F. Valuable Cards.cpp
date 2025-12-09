// Date: 12-07-2024
// Start Time: 14:23:04
// End Time  : 16:23:04
// Time Taken: 120 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/1992/problem/F
// Rating: 1400
// Description: Find the minimum number of segments such that the producht any subset of each segments is != x
// Solved: No
// Learning: this question was equal to subset product that is, whether there is a subset whose product is equal to the given product

/****************************************************Pre Processor***************************************************/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#include "./lib/debug.h"
#include "./lib/print.h"
#else
#define debug(...) 42
#endif
#define endl '\n'
/***************************************************Main Function**************************************************/

void solve()
{
    int n, x;
    cin >> n >> x;
    int cnt = 1;
    set s{x};
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        for (int el : s)
        {
            if (el % a)
                continue;
            if (el == a)
            {
                cnt++;
                // because i cannnot keep this element a in my set so keeping it in my next set means that i do not want an element x/a in it
                s = {x, x / a};
                break;
            }
            else if (el % a == 0)
            {
                s.emplace(el / a);
            }
        }
    }
    cout << cnt << endl;
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);

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
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}