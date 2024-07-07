// Date: 07-07-2024
// Start Time: 20:49:46
// End Time  : 21:36:47
// Time Taken: 47 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/1983/problem/C
// Rating: 1400
// Description: Find whether you can distribute an array to 3 people (continuous subarray)
// Solved: Yes
// Learning: Binary search and modulo arithmetic

/****************************************************Pre Processor***************************************************/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#include "./lib/debug.h"
#include "./lib/print.h"
#else
#define debug(...) 42
#endif
#define endl '\n'
#define int long long
/***************************************************Main Function**************************************************/

void solve()
{
    int n;
    cin >> n;
    vector<vector<long long>> v(3, vector<long long>(n));
    for (int j = 0; j < 3; j++)
        for (int i = 0; i < n; i++)
        {
            cin >> v[j][i];
            if (i > 0)
                v[j][i] += v[j][i - 1];
        }
    long long required_sum = (v[0][n - 1] + 2) / 3; // ceil
    debug(required_sum);
    vector<pair<int, int>> ans(3);
    for (int i = 0; i < 3; i++)
    {
        int l = lower_bound(v[i].begin(), v[i].end(), required_sum) - v[i].begin();
        for (int j = 1; j <= 2; j++)
        {
            int r = upper_bound(v[(i + j) % 3].begin(), v[(i + j) % 3].end(), v[0][n - 1] - required_sum) - v[(i + j) % 3].begin();
            debug(l, r, i, (i + j) % 3);
            if (r <= l)
                continue;
            else
            {
                int k;
                k = (j == 1) ? 1 : -1;
                debug((i + j + k) % 3);
                // it means that the next array is to be checked for the middle subarray
                if (v[(i + j + k) % 3][r - 1] - v[(i + j + k) % 3][l] >= required_sum)
                {
                    ans[i] = {1, l + 1};
                    ans[(i + j) % 3] = {r + 1, n};
                    ans[(i + j + k) % 3] = {l + 2, r};
                    for (int w = 0; w < 3; w++)
                    {
                        cout << ans[w].first << " " << ans[w].second << " ";
                    }
                    cout << endl;
                    return;
                }
                else
                    continue;
            }
        }
    }
    cout << "-1" << endl;
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