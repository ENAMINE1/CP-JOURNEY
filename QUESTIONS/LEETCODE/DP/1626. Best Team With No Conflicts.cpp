// Date: 11-07-2024
// Start Time: 10:46:15
// End Time  : 12:46:15
// Time Taken: 120 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://leetcode.com/problems/best-team-with-no-conflicts
// Rating: Medium
// Description: find a team with max score such that the team does not have any conflict
// Solved: Yes
// Learning: you just needed the index of the last chosen player in the team after you sorted the array

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

class Solution
{
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        int n = scores.size();

        if (n == 1)
        {
            return scores[0];
        }

        vector<pair<int, int>> vp(n);
        for (int i = 0; i < n; i++)
        {
            vp[i] = {ages[i], scores[i]};
        }

        sort(vp.begin(), vp.end());
        int maxi = 0;
        vector<int> dp(n);
        for (int i = 0; i < n; i++)
        {
            dp[i] = vp[i].second;
            for (int j = i - 1; j >= 0; j--)
            {
                if (vp[i].second >= vp[j].second)
                {
                    dp[i] = max(dp[i], dp[j] + vp[i].second);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
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