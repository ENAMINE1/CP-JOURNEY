// Date: 16-07-2024
// Start Time: 13:00:06
// End Time  : 16:13:44
// Time Taken: 193 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/problemset/problem/520/B
// Rating: 1400
// Description: get m from n using 2 operations in min number of steps
// Solved: No
// Learning: Using bfs and not to use dp or recursion in this case because to solve a problem into 2 porblem you had to solve the subproblem again and again which lead to stack overflow

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
int n, m;
vector<long long> dist;
void bfs(vector<vector<int>> &g)
{
    dist.assign(20010, INT_MAX);
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto nn : g[node])
        {
            // debug(nn, node);
            if (dist[nn] > dist[node] + 1)
            {
                dist[nn] = dist[node] + 1;
                q.push(nn);
            }
        }
    }
    cout << dist[m] << endl;
}

void solve()
{
    cin >> n >> m;
    // add edges to the 2 values reachable from a number
    vector<vector<int>> g(20010);
    for (int i = 1; i < 10005; i++)
    {
        if (i > 1)
            g[i].push_back(i - 1);
        g[i].push_back(2 * i);
    }
    for (int i = 1005; i < 20010; i++)
    {
        g[i].push_back(i - 1);
    }
    bfs(g);
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