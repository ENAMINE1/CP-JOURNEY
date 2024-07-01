// Date: 01-07-2024
// Start Time: 18:17:25
// End Time  : 19:06:40
// Time Taken: 49 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://atcoder.jp/contests/dp/tasks/dp_s
// Rating: Medium
// Description: find the number of integers in a range divisble by x
// Solved: No 
// Learning: DIGIT DP

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

string s;
int d;
const int mod = 1e9 + 7;
int dp[10005][2][105];
int rec(int idx, int hi, int rem)
{
    if (idx == s.length())
    {
        if (rem == 0)
            return 1;
        return 0;
    }
    if (dp[idx][hi][rem] == -1)
    {
        int ans = 0;
        int lolim = 0;
        int hilim = 9;
        if (hi == 1)
            hilim = s[idx] - '0';
        debug(hilim);
        for (int i = lolim; i <= hilim; i++)
        {
            int nhi = hi;
            if (i != s[idx] - '0')
                nhi = 0;
            int nrem = (rem + i) % d;
            ans = (ans + rec(idx + 1, nhi, nrem)) % mod;
        }
        dp[idx][hi][rem] = ans;
    }
    return dp[idx][hi][rem];
}

void solve()
{
    cin >> s >> d;
    debug(s, d);
    memset(dp, -1, sizeof(dp));
    cout << (rec(0, 1, 0) - 1 + mod) % mod;
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);

    int t = 1;
    // cin >> t;
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