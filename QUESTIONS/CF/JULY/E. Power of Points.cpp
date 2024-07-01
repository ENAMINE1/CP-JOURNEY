// Date: 01-07-2024
// Start Time: 20:18:08
// End Time  : 20:28:26
// Time Taken: 10 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/1857/problem/E
// Rating: 1500
// Description: count the number of integers in a range
// Solved: No
// Learning: how to decompose the summation expression and use it

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
    vector<pair<int, int>> v(n + 1);
    vector<long long> temp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    vector<long long> pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = v[i].first;
        if (i > 1)
            pre[i] += pre[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        int s = v[i].first;
        temp[v[i].second] = n + 1LL * s * (2 * i - n) - pre[i] + (pre[n] - pre[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
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