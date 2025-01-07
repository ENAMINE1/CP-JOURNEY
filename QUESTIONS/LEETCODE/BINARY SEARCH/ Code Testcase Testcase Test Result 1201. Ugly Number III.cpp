// Date: 29-12-2024
// Start Time: 23:24:24
// End Time  : 23:41:38
// Time Taken: 17 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://leetcode.com/problems/ugly-number-iii
// Rating: Medium
// Description: Find the nth number divisible by either a , b, c
// Solved: No
// Learning: thora maths laga lo bhai

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

int nthUglyNumber(int n, int A, int B, int C)
{
    int lo = 0;
    int hi = 2e9;
    int ans = -1;
    long a = long(A), b = long(B), c = long(C);
    long ab = a * b / __gcd(a, b);
    long bc = b * c / __gcd(b, c);
    long ac = a * c / __gcd(a, c);
    long abc = a * bc / __gcd(a, bc);
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        int cnt = mid / a + mid / b + mid / c - mid / ab - mid / bc - mid / ac + mid / abc;
        debug(cnt, mid, lo, hi);
        if (cnt >= n)
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
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    cout << nthUglyNumber(n, a, b, c);
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