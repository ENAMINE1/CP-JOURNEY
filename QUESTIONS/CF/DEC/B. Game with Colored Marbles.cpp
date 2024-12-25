// Date: 24-12-2024
// Start Time: 10:21:16
// End Time  : 10:34:08
// Time Taken: 12 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/problemset/problem/2042/B
// Rating: 900
// Description: Alice wants to maximize her score at the end of the game. Bob wants to minimize it. Both players play optimally
// Solved: No
// Learning: The question may be set is a way that you would not need DP

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
    vector<int> v(n);
    map<int, int> mp;
    for (auto &x : v)
    {
        cin >> x;
        mp[x]++;
    }
    long long ans = 0;
    int one = 0;
    for (auto [color, freq] : mp)
    {
        if (freq == 1)
            one++;
        else
            ans++;
    }
    ans += (one + 1) / 2 * 2;
    cout << ans << endl;
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