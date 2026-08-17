// Date: 14-08-2026
// Start Time: 10:03:59
// End Time  : 08:57:37
// Time Taken: -66 minutes
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
/***************************************************Main Function**************************************************/

vector<int> col;
vector<int> par;
vector<int> dp;

void dfs(int node, vector<vector<int>> &g, int parent)
{
    // mark it visited first time (denoted by colour 2)
    col[node] = 2;
    par[node] = parent;
    for (auto nn : g[node])
    {
        if (col[nn] == 1)
        {
            // visit the neighbour because it is unvisited
            dfs(nn, g, node);

            dp[node] += dp[nn];
            if (dp[nn] == 0)
            {
                cout << "Bridge: " << node << " - " << nn << endl;
            }
        }
        else if (col[nn] == 2 && nn != par[node])
        {
            // the neighbour has already been visited some time earlier and so we have a cycle
            dp[node]++;
            dp[nn]--;
        }
        else if (col[nn] == 3)
        {
            // the neighbour has already been visited but the direction of the edge does not form a cycle
        }
    }
    col[node] = 3;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    col.assign(n + 1, 1);
    par.assign(n + 1, -1);
    dp.assign(n + 1, 0);

    // take input of graph and convert it into adjacency list
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // bridge finding or finding how many cycles an edge is a part of
    dfs(1, g, -1);
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