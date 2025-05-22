// Date: 22-05-2025
// Start Time: 14:22:03
// End Time  : 14:22:03
// Time Taken:
// Author: Shashwat Kumar
// QUESTION LINK: https://leetcode.com/problems/redundant-connection
// Rating: Medium
// Description: given a tree and an extra edge report the last edge that results in a cycle
// Solved: No
// Learning: you need to sometimes check for different parent before merging

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

void solve()
{
    class Solution
    {
    public:
        vector<int> rank;
        vector<int> par;

        int find(int a)
        {
            // cout << par[a] << " " << a << endl;
            if (par[a] != a)
            {
                return par[a] = find(par[a]);
            }
            return a;
        }

        bool merge(int a, int b)
        {
            int x = find(a);
            int y = find(b);
            // cout << "inside merge function" << " ";
            // cout << x << " " << y << endl;

            if (x != y)
            {
                if (rank[x] >= rank[y])
                {
                    par[y] = x;
                    rank[x] += rank[y];
                }
                else
                {
                    par[x] = y;
                    rank[y] += rank[x];
                }
                return true;
            }
            return false;
        }

        vector<int> findRedundantConnection(vector<vector<int>> &edges)
        {
            // the job is to identify the last edge in a cycle
            // dfs can find a cycle but where to start not defined so you will need
            // to check which edge in the cycle appears last in the edgelist
            // provided so O(V + E) + edges.size() ^ 2 so basically O(n ^ 2) so can
            // pass

            // the problem of first or last in a graph

            // plain union find problem
            int n = edges.size();

            rank.assign(n, 1);
            par.resize(n);
            iota(par.begin(), par.end(), 0);
            // for (auto el : par) {
            //     cout << el << " ";
            // }
            // cout << endl;
            // cout << endl;

            vector<int> ans;
            for (auto v : edges)
            {
                int a = --v[0];
                int b = --v[1];
                if (!merge(a, b))
                {
                    // cout << "inside main" << endl;
                    // cout << a << " " << par[a] << endl;
                    // cout << b << " " << par[b] << endl;
                    ans = {++a, ++b};
                    break;
                }
            }
            return ans;
        }
    };
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