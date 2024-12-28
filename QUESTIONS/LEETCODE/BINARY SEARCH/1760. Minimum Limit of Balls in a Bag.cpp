// Date: 27-12-2024
// Start Time: 21:45:46
// End Time  : 21:48:58
// Time Taken: 3 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag
// Rating: Medium
// Description: You are given an integer array nums where the ith bag contains nums[i] balls. You are also given an integer maxOperations. Your penalty is the maximum number of balls in a bag. You want to minimize your penalty after the operations.
// Solved: No
// Learning: Correct expression for calculating the number of operations required

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

int minimumSize(vector<int> &v, int k)
{
    int lo = 1;
    int hi = 1e9;
    int ans = -1;
    int n = v.size();
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        // check whether mid number of balls is the max size of each bag
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            // this was the key mistake that i did as the number of operations is not simply the sum of v[i]/mid
            // recall te az video that the correct expressions is ceil(v[i]/mid) - 1
            cnt += (v[i] + mid - 1) / mid - 1;
        }
        if (cnt <= k)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    cout << minimumSize(v, k);
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