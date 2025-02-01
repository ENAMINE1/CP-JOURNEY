// Date: 01-02-2025
// Start Time: 16:00:55
// End Time  :
// Time Taken:
// Author: Shashwat Kumar
// QUESTION LINK: https://leetcode.com/problems/permutations-ii
// Rating: Medium
// Description: Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
// Solved: Yes
// Learning: Got to learn how to take care of duplicates using the decision tree of the recursion that is any level of recusion you should choose from differnt unique numbers to go to next level of recusion thus each path giving you a unique permutation of the array

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
        vector<vector<int>> ans;
        int n;
        map<int, int> freq_map;

        void rec(int i, vector<int> &t)
        {
            if (i == n)
            {
                ans.push_back(t);
                return;
            }
            for (auto [a, b] : freq_map)
            {
                if (freq_map[a] > 0)
                {
                    freq_map[a]--;
                    t.push_back(a);
                    rec(i + 1, t);
                    t.pop_back();
                    freq_map[a]++;
                }
            }
        }

        vector<vector<int>> permuteUnique(vector<int> &v)
        {
            vector<int> t;
            n = v.size();
            for (int i = 0; i < n; i++)
            {
                freq_map[v[i]]++;
            }
            rec(0, t);
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