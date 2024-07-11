// Date: 11-07-2024
// Start Time: 14:16:10
// End Time  : 15:16:10
// Time Taken: 60 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://leetcode.com/problems/domino-and-tromino-tiling
// Rating: Medium
// Description: Find the number of ways you can tile a floor using given tiles
// Solved: No
// Learning: Got to know about a new satate paramete, very very IMPORTANT

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
const int mod = 1e9 + 7;
class Solution
{
public:
    int dp[1005][2];
    // the gap_left parameter is to find whether gap is left in the previous row
    int rec(int idx, bool gap_left, int n)
    {
        if (idx > n)
            return 0;
        if (idx == n)
            return !gap_left;
        if (dp[idx][gap_left])
            return dp[idx][gap_left];
        if (gap_left)
        {
            // there are two ways to fill the previous gap
            return dp[idx][gap_left] =
                       (1LL * rec(idx + 1, false, n) + rec(idx + 1, true, n)) %
                       mod;
        }
        return dp[idx][gap_left] = (1LL * rec(idx + 1, false, n) + rec(idx + 2, false, n) + 2LL * rec(idx + 2, true, n)) % mod;
    }

    int numTilings(int n) { return rec(0, 0, n); }
};
void solve()
{
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