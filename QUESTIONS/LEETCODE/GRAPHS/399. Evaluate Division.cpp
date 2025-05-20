// Date: 20-05-2025
// Start Time: 07:55:05
// End Time  : 08:55:49
// Time Taken:
// Author: Shashwat Kumar
// QUESTION LINK: https://leetcode.com/problems/evaluate-division/
// Rating: Medium
// Description: You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable. You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.
// Solved: No
// Learning: Finding to which category the problem belongs what the critical part and then using the values v[i] as edge weights was alog important step which i missed

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
        double dfs(int node, int dest, vector<vector<pair<int, double>>> &graph)
        {
            vis[node] = 1;
            if (node == dest)
            {
                return 1;
            }
            for (auto [nn, wt] : graph[node])
            {
                if (!vis[nn])
                {
                    double retval = dfs(nn, dest, graph);
                    if (retval > 0)
                    {
                        return wt * retval;
                    }
                }
            }
            return -1;
        }

        vector<double> calcEquation(vector<vector<string>> &e, vector<double> &v,
                                    vector<vector<string>> &q)
        {
            // hashing the strings to numbers
            map<string, int> mp;
            int seed = 0;
            for (int i = 0; i < e.size(); i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    string num = e[i][j];
                    if (mp.find(num) == mp.end())
                    {
                        mp.insert({num, seed});
                        seed++;
                    }
                }
            }

            // map crated successfully
            // for(auto it = mp.begin(); it!= mp.end(); it++)
            // {
            //     cout<<it->first<<" "<<it->second<<endl;
            // }

            // creating the graph
            int n = mp.size();
            vector<vector<pair<int, double>>> graph(n);
            for (int i = 0; i < e.size(); i++)
            {
                string from = e[i][0];
                string to = e[i][1];
                double wt = v[i];
                if (mp.find(from) == mp.end() || mp.find(to) == mp.end())
                    continue;
                graph[mp[from]].push_back({mp[to], wt});
                graph[mp[to]].push_back({mp[from], 1LL / wt});
            }

            vector<double> ans;
            for (int i = 0; i < q.size(); i++)
            {
                string num = q[i][0]; // numerator
                string den = q[i][1];
                if (mp.find(num) == mp.end() || mp.find(den) == mp.end())
                    ans.push_back(-1);
                else
                {
                    vis.assign(n, 0);
                    ans.push_back(dfs(mp[num], mp[den], graph));
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