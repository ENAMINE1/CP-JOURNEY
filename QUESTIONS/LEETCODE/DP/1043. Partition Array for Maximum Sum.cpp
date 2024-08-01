// Date: 01-08-2024
// Start Time: 21:18:39
// End Time  : 21:50:39
// Time Taken: 32 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://leetcode.com/problems/partition-array-for-maximum-sum/
// Rating: Medium
// Description: Find the max sum of the array by replacing the elements in the array with the max element in a subarray
// Solved: No
// Learning: Enumerating all subarrays

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

nt dp[505];

int rec(int l, vector<int> &arr, int k)
{
    int n = arr.size();
    int cur_mx = 0;
    if (dp[l] == -1)
    {
        int ans = 0;
        for (int i = l; i < min(n, l + k); i++)
        {
            cur_mx = max(cur_mx, arr[i]);
            ans = max(ans, (i - l + 1) * cur_mx + rec(i + 1, arr, k));
        }
        dp[l] = ans;
    }
    return dp[l];
}

void solve(vector<int> &arr, int k)
{
    memset(dp, -1, sizeof(dp));
    cout << rec(0, arr, k);
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