// Date: 19-07-2024
// Start Time: 08:01:02
// End Time  : 08:38:00
// Time Taken: 36 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/problemset/problem/455/A
// Rating: 1500
// Description: find the max score that you can get by deleting some elements form the array
// Solved: Yes
// Learning: read the question carefully

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

long long dp[2][100005];

long long rec(int idx, int deleted, vector<int> &g, map<int, int> &freq)
{
    if (idx < 0)
        return 0;
    long long ans = INT_MIN;
    if (dp[deleted][idx] == -1)
    {
        if (deleted == 1 && g[idx] == g[idx + 1] - 1)
            ans = rec(idx - 1, 0, g, freq);
        else
            ans = max(rec(idx - 1, 1, g, freq) + 1LL * g[idx] * freq[g[idx]], rec(idx - 1, 0, g, freq));
        dp[deleted][idx] = ans;
    }
    return dp[deleted][idx];
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> freq;
    vector<int> g;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        freq[v[i]]++;
    }
    for (auto [key, val] : freq)
        g.push_back(key);
    int m = g.size();
    cout << rec(m - 1, 0, g, freq);
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