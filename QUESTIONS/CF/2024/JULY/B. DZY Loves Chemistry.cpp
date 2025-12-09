// Date: 06-07-2024
// Start Time: 13:09:46
// End Time  : 13:52:24
// Time Taken: 42 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/445/problem/B
// Rating: 1400
// Description: Find the number of components using DSU
// Solved: No
// Learning: how to use dsu to find the number components

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
int parent[51];
int sz[51];

int find(int x)
{
    if (parent[x] != x)
        return parent[x] = find(parent[x]);
    return x;
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (sz[x] >= sz[y])
    {
        parent[y] = x;
        sz[y] += sz[x];
    }
    else
    {
        parent[x] = y;
        sz[x] += sz[y];
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        merge(a, b);
    }
    long long ans = 1LL << n;
    for (int i = 0; i < n; i++)
    {
        if (parent[i] == i)
            ans /= 2;
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