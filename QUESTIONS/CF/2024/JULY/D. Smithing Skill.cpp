// Date: 02-07-2024
// Start Time: 12:51:22
// End Time  :
// Time Taken:
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/1989/problem/D
// Rating: 1900
// Description: Find the max score you can get by forging wepons and melting them back
// Solved: No
// Learning: How to eleminate useless swords and how to choose correct swords [IMPORTANT]

/****************************************************Pre Processor***************************************************/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "./lib/print.h"
#include "./lib/debug.h"
#else
#define debug(...) 42
#endif
#define endl '\n'

/****************************************************Main Function**************************************************/
const int N = 1e6 + 5;
int dp[N];
void solve()
{
    int n, m;
    cin >> n >> m;
    memset(dp, 0, sizeof(dp));
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].second;
        a[i].second = a[i].first - a[i].second;
    }
    sort(a.begin(), a.end());
    vector<pair<int, int>> b;
    // removing useless swords j such that a[j] >= a[i] and a[j] - b[j] >= a[i] - b[i];
    for (int i = 0; i < n; i++)
    {
        if (b.empty() || a[i].second < b.back().second)
            b.push_back({a[i].first, a[i].second});
    }
    // if the amount of metal available is less than 1e6 then we precompute the score that can be obtained because the max value of metal used in any forging a[i] is less than 1e6
    int curr = 0;
    for (int i = 1; i < N; i++)
    {
        // here i is the amount of meatal available
        // find the sword with the largest meatal requirement less than equal to i and least meatal used
        while (curr < b.size() && b[curr].first <= i)
            curr++;
        if (curr)
            dp[i] = dp[i - b[curr - 1].second] + 2;
    }
    // now considering the case when the available metal is > 1e6
    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        int c;
        cin >> c;
        if (c >= b.back().first)
        {
            // i will forge the last sword as many times as possible
            ans += 1LL * (c - b.back().first) / (b.back().second) * 2;
            c = b.back().first + ((c - b.back().first) % (b.back().second));
            // if i forge it one more time the avilable metal will become less than the required metal for the last sword
            ans += 2;
            c -= b.back().second;
        }
        ans += dp[c];
    }
    cout << ans << endl;
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