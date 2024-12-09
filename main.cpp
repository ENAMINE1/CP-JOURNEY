// Date: 10-08-2024
// Start Time: 15:30:11
// End Time  : 12:56:50
// Time Taken: -153 minutes
// Author: Shashwat Kumar
// QUESTION LINK:
// Rating:
// Description:
// Solved:
// Learning:

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

int rec(int sum, vector<int> &v)
{
    if (sum == 0)
        return 1;
    int n = v.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum - v[i] >= 0)
            ans += rec(sum - v[i], v);
    }
    return ans;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }

    vector<vector<int>> dp(x + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= x; i++)
    {
        dp[i][n] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= x; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i - v[j] >= 0)
                dp[i][j] += dp[i - v[j]][j + 1];
        }
    }
    cout << dp[x][n];
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
