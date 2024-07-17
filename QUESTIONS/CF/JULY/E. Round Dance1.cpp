// Date: 17-07-2024
// Start Time: 18:27:33
// End Time  : 18:59:23
// Time Taken: 31 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/problemset/problem/1833/E
// Rating: 1600
// Description: Your task is to determine what the minimum and maximum number of round dances could be.
// Solved: NO
// Learning: DSU had less TC and even less space complexity

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

class DSU
{
    int n, size;
    vector<int> rank, parent;

public:
    DSU(int a)
    {
        reset(a);
    };

    int find(int x)
    {
        // debug(x);
        if (x != parent[x])
            return parent[x] = find(parent[x]);
        return x;
    }

    bool merge(int a, int b)
    {
        int aroot = find(a);
        int broot = find(b);
        if (aroot != broot)
        {
            size--;
            if (rank[aroot] > rank[broot])
            {
                rank[aroot] += rank[broot];
                parent[broot] = aroot;
            }
            else
            {
                rank[broot] += rank[aroot];
                parent[aroot] = broot;
            }
            return true;
        }
        return false;
    }

    void reset(int a)
    {
        n = a;
        size = a;
        rank.assign(n + 1, 0);
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    DSU dsu(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        dsu.merge(i, v[i]);
    }
    // now i have all the components seperate from each other
    vector<bool> check(n + 1);
    for (int i = 1; i <= n; i++)
    {
        // marking the componets as chain
        if (v[v[i]] == i)
        {
            check[dsu.find(i)] = true;
        }
    }
    int chain = 0, cycle = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == dsu.find(i))
        {
            if (check[i])
                chain++;
            else
                cycle++;
        }
    }
    cout << cycle + (chain > 0) << " " << cycle + chain << endl;
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