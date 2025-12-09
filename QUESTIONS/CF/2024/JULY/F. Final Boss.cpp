// Date: 03-07-2024
// Start Time: 13:06:47
// End Time  : 13:27:26
// Time Taken: 20 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/problemset/problem/1985/F
// Rating: 1500
// Description: Standard question on binary search
// Solved: No
// Learning: check function was important here also i learned that if i can perform an action in an interval of say x then in the duration of say t, i can perform the same action ((t-i)/x)+1 times.

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
#define int long long

/************************************************************************************************Main Function**************************************************/

int h, n;
bool check(int x, vector<pair<int, int>> &v)
{
    long long damage = 0;
    for (int i = 0; i < n; i++)
    {
        damage += (1LL * (x - 1) / v[i].second + 1) * v[i].first;
        if (damage >= h)
            return true;
    }
    return false;
}

void solve()
{
    cin >> h >> n;
    // first -> damage, second -> cooldown
    vector<pair<int, int>> attack(n);
    for (int i = 0; i < n; i++)
        cin >> attack[i].first;
    for (int i = 0; i < n; i++)
        cin >> attack[i].second;
    int hi = 1e11;
    int lo = 1;
    int ans = 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        if (check(mid, attack))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
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