// Date: 04-07-2024
// Start Time: 18:00:04
// End Time  : 21:17:59
// Time Taken: 197 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/1973/problem/B
// Rating: 1300
// Description: Find the smallerst subarray length such that any subarray of the length will have same range OR
// Solved: No
// Learning: binary search was used and was tough to spot and also bit - manipulation was used

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

int n;
bool check(int x, vector<int> &v)
{
    // for each sub array of length x find the range xor and compare it with the first 1st subarray
    vector<int> bit_count(20);
    // O(x)
    // basically counting the number of integers which have the i the bit set
    int or1 = 0;
    for (int bit = 0; bit < 20; bit++)
    {
        for (int i = 0; i < x; i++)
        {
            if (v[i] >> bit & 1)
                bit_count[bit]++;
            if (bit == 0)
                or1 |= v[i];
        }
    }
    int or2 = or1;
    for (int i = x; i < n; i++)
    {
        for (int bit = 0; bit < 20; bit++)
        {
            if ((v[i - x] >> bit) & 1)
            {
                bit_count[bit]--;
                if (bit_count[bit] == 0)
                {
                    or1 -= 1 << bit;
                }
            }
            if ((v[i] >> bit) & 1)
            {
                bit_count[bit]++;
                or1 |= 1 << bit;
            }
        }
        if (or1 != or2)
            return false;
    }
    return true;
}
#define ll long long
void solve()
{
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int lo = 1;
    int hi = n;
    int ans = n;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        debug(hi, lo, mid);
        if (check(mid, v))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
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