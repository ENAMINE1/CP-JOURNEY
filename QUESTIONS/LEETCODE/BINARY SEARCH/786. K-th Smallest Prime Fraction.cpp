// Date: 26-12-2024
// Start Time: 20:34:54
// End Time  : 11:51:46
// Time Taken: -523 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://leetcode.com/problems/k-th-smallest-prime-fraction
// Rating: Medium
// Description: You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.
// Solved: No
// Learning: How to find the numerator and denominator and not just the kth smalles fraction

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

vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
{
    int n = arr.size();
    double lo = 0;
    double hi = 1.0;
    double ans = -1;
    const double epsilon = 1e-9; // Small value to handle precision
    double max_fraction = 0;
    vector<int> rv = {1, 1};
    while (hi - lo > epsilon)
    {
        double mid = (double(lo + hi)) / 2;
        int total = 0;
        double mx = 0;
        vector<int> temp(2);
        for (int j = 0; j < n; j++)
        {
            // count the number of fractions less than equal to mid
            int cnt = upper_bound(arr.begin(), arr.end(), arr[j] * mid) - arr.begin();
            total += cnt;
            debug(arr[cnt], arr[j], mx, cnt, j);
            if (cnt)
            {
                if (static_cast<double>(arr[cnt - 1]) / arr[j] > mx)
                {
                    mx = static_cast<double>(arr[cnt - 1]) / arr[j];
                    temp = {arr[cnt - 1], arr[j]};
                }
            }
        }
        if (total >= k)
        {
            if (total == k)
            {
                ans = mid;
                rv = temp;
            }
            hi = mid;
        }
        else
            lo = mid;
        debug(total, mid, lo, hi);
    }
    cout << ans << endl;
    cout << rv << endl;
    return rv;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    kthSmallestPrimeFraction(v, k);
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