// Date: 15-05-2025
// Start Time: 15:52:07
// End Time  :
// Time Taken:
// Author: Shashwat Kumar
// QUESTION LINK: https://leetcode.com/problems/course-schedule-iv
// Rating: Medium
// Description: find all the ancestors of each node
// Solved: Kinda Yes
// Learning: Try reversing the edges and see the magic and also try reversing the direction of dfs.

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
        vector<int> vis;

        void dfs(int node, vector<vector<int>> &g, vector<int> ancestors, vector<set<int>> &vs)
        {
            vis[node] = 1;

            for (int nn : g[node])
            {
                if (!vis[nn])
                    dfs(nn, g, ancestors, vs);
                for (int a : vs[nn])
                    vs[node].insert(a);
                vs[node].insert(nn);
            }
        }

        vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &p, vector<vector<int>> &q)
        {
            // for each node i need to store all of its ancestors and answer the query

            // create the DAG
            vector<vector<int>> graph(n);
            for (auto el : p)
            {
                int from = el[1], to = el[0];
                graph[from].push_back(to);
            }

            vis.assign(n, 0);

            // vector of set to store the ancestors of each node
            vector<set<int>> vs(n);

            // dfs
            for (int i = 0; i < n; i++)
            {
                if (!vis[i])
                {
                    vector<int> ancestors;
                    dfs(i, graph, ancestors, vs);
                }
            }

            vector<bool> ans;
            for (int i = 0; i < q.size(); i++)
            {
                int from = q[i][0], to = q[i][1];
                if (vs[to].find(from) != vs[to].end())
                    ans.push_back(true);
                else
                    ans.push_back(false);
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