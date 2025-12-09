// Date: 04-07-2024
// Start Time: 21:34:40
// End Time  : 21:52:43
// Time Taken: 18 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/1973/problem/B
// Rating: 1300
// Description:
// Solved: Yes
// Learning: Another faster way to solve the same problem in O(nlogA) time where A is the largest element in the array

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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    int ans = 1;
    for (int bit = 0; bit < 20; bit++)
    {
        vector<int> set_bit_count;
        set_bit_count.push_back(-1);
        for (int i = 0; i < n; i++)
        {
            if (v[i] >> bit & 1)
                set_bit_count.push_back(i);
        }
        set_bit_count.push_back(n);
        if (set_bit_count.size() > 2)
            for (int j = 1; j < set_bit_count.size(); j++)
                ans = max(ans, set_bit_count[j] - set_bit_count[j - 1]);
    }
    // basically what i did was to store the indices of the number in which the bits are set in the number and now i will just find the max difference between the indices of two numbers where the same bit is set again
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