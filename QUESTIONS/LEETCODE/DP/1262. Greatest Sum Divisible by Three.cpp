// Date: 10-07-2024
// Start Time: 17:15:15
// End Time  : 18:15:15
// Time Taken: 60 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://leetcode.com/problems/greatest-sum-divisible-by-three/
// Rating: Medium
// Description: Find the largest sum with the elements of the array whose sum is divisible by 3
// Solved: No
// Learning: Learned to keep mod in the state rather than the sum till now and return the sum from the function to optimise time complexity

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
    const int N = 4e4 + 5;
    class Solution
    {
    public:
        int dp[N][4];
        // here rec returns me the max sum you can obtain from array starting from
        // element at idx i
        long long rec(int idx, int mod, vector<int> &v)
        {
            int n = v.size();
            if (idx >= n)
            {
                if (mod == 0)
                    return 0;
                return INT_MIN;
            }
            if (dp[idx][mod] != -1)
                return dp[idx][mod];
            // either i will take the number in the sum or i will not
            return dp[idx][mod] =
                       max(rec(idx + 1, (v[idx] + mod) % 3, v) + v[idx],
                           rec(idx + 1, mod, v));
        }

        int maxSumDivThree(vector<int> &v)
        {
            memset(dp, -1, sizeof(dp));
            return (rec(0, 0, v) > 0) ? dp[0][0] : 0;
        }
    };
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