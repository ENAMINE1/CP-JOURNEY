// Date: 09-01-2025
// Start Time: 19:34:55
// End Time  : 19:36:26
// Time Taken: 1 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
// Rating: Medium
// Description: Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.
// Solved: No
// Learning: There was an easier way to calculate the number of subarrays with all 1s in it

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
    class Solution
    {
    public:
        int minDays(vector<int> &v, int m, int k)
        {
            int n = v.size();
            int lo = 1;
            int hi = 1e9;
            int ans = -1;
            while (lo <= hi)
            {
                int mid = (lo + hi) / 2;
                // mid number of days have passed
                // sliding window of size k and count such windows where all the
                // flowers have bloomed
                bool b = false;
                int cnt = 0;
                int i = 0;
                int bouq = 0;
                for (int i = 0; i < n; i++)
                {
                    if (v[i] <= mid)
                        cnt++;
                    else
                        cnt = 0;
                    if (cnt == k)
                    {
                        bouq++;
                        cnt = 0;
                    }
                }
                b = bouq >= m;
                if (b)
                {
                    ans = mid;
                    hi = mid - 1;
                }
                else
                    lo = mid + 1;
            }
            return ans;
        }
    };
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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
    return 0;
}