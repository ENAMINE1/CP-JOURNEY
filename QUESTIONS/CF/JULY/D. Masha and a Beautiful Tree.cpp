// Date: 02-07-2024
// Start Time: 21:25:16
// End Time  : 23:46:26
// Time Taken: 141 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/1741/problem/D
// Rating: 1300
// Description: Find the number of swaps required to make the array sorted
// Solved: No
// Learning: Learned to to calculate the min and max values for each subtree in an array

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
int levels;

void solve()
{
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> mx(2 * n - 1), mn(2 * n - 1);
    for (int i = 0; i < n; i++)
    {
        mx[n - 1 + i] = v[i];
        mn[n - 1 + i] = v[i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        mx[i] = max(mx[2 * i + 1], mx[2 * i + 2]);
        mn[i] = min(mn[2 * i + 1], mn[2 * i + 2]);
    }
    bool ok = true;
    int ans = 0;
    for (int j = 0; j < n - 1; j++)
    {
        if (mx[j * 2 + 1] < mn[j * 2 + 2])
        {
        }
        else if (mx[j * 2 + 2] < mn[j * 2 + 1])
            ans++;
        else
            ok = false;
    }
    if (!ok)
        cout << -1 << endl;
    else
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