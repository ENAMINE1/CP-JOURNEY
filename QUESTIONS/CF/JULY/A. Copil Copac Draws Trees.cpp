// Date: 02-07-2024
// Start Time: 14:24:00
// End Time  : 17:24:23
// Time Taken: 180 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/1830/problem/A
// Rating: 1400
// Description: Find how many paases through the edge list is rquired to create the tree
// Solved: No
// Learning: How to maintain the history or count of pases [IMPORTANT]

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

const int N = (int)1e6 + 5;
map<pair<int, int>, int> m;
int dfs(int node, int pp, int pass, int idx, vector<vector<int>> &g)
{
    debug(node + 1, pp + 1);
    int ans = pass;
    for (int nn : g[node])
    {
        if (nn != pp)
        {
            int i = m[{node, nn}];
            // debug(i, idx, node+1, nn+1, pass);
            ans = max(ans, dfs(nn, node, pass + (i < idx), i, g));
            debug(ans);
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int from, to;
        cin >> from >> to;
        g[--from].push_back(--to);
        g[to].push_back(from);
        m[{from, to}] = i + 1;
        m[{to, from}] = i + 1;
    }
    cout << dfs(0, -1, 1, 0, g) << endl;
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