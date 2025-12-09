// Date: 07-07-2024
// Start Time: 10:24:04
// End Time  : 11:24:07
// Time Taken: 60 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/1675/problem/D
// Rating: 1300
// Description: Find the minimal set of paths such that each node appears in only one path
// Solved: Yes
// Learning: From each leaf we will climb up the tree until we meet a vertex already visited. Having met such a vertex, start a new path from the next leaf.

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
/***************************************************Main Function**************************************************/

void solve()
{
    int n;
    cin >> n;
    vector<int> b(n + 1);
    vector<bool> leaf(n + 1, true);
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        leaf[b[i]] = false;
    }

    if (n == 1)
    {
        cout << "1\n1\n1\n\n";
        return;
    }

    vector<int> paths[n + 1];
    vector<bool> used(n + 1, false);
    int color = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!leaf[i])
            continue;
        used[i] = true;
        paths[color].emplace_back(i);

        int v = i;
        while (b[v] != v && !used[b[v]])
        {
            v = b[v];
            used[v] = true;
            paths[color].emplace_back(v);
        }
        color++;
    }

    cout << color << '\n';
    for (auto &path : paths)
    {
        if (path.empty())
            continue;
        cout << (int)path.size() << '\n';
        reverse(path.begin(), path.end());
        for (auto &v : path)
            cout << v << ' ';
        cout << '\n';
    }
    cout << '\n';
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