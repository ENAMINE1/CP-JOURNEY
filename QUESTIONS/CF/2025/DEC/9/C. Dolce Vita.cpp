// Date: 09-12-2025
// Start Time: 14:44:36
// End Time  : 16:18:16
// Time Taken: 93 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/1671/problem/C
// Rating: 1200
// Description: You have n shops, each selling one pack of sugar per day. Shop i sells a pack for aᵢ + (day − 1) coins on day day (price increases by 1 each day). Your daily budget is x coins, and leftover money cannot be carried over. Each day you buy as many packs as possible without exceeding x. Eventually, all packs will cost more than x, so you must stop. Find the total number of sugar packs you can buy before that happens.
// Solved: No
// Learning: Problems where the input vector is changing then you need to look for other approaches rather than iterating over the vector

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
/***************************************************Main Function**************************************************/

void solve()
{
    long long n, x;
    cin >> n >> x;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    debug(v);
    for (int i = 0; i < n; i++)
    {
        if (i)
            v[i] += v[i - 1];
    }
    debug(v);
    vector<int> days(n + 1);
    // days[i] represents how many days can I buy first i items starting from day 1
    for (int i = 0; i < n; i++)
    {
        if (x - v[i] < 0)
            break;
        days[i] = (x - v[i]) / (i + 1) + 1;
    }
    // days[i] - days[i + 1] represents how many days you can buy exactly i items
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (days[i] == 0)
            break;
        ans += (days[i] - days[i + 1]) * (i + 1);
    }
    cout << ans << endl;
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);

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
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}