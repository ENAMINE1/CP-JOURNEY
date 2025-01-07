// Date: 07-01-2025
// Start Time: 18:55:19
// End Time  :
// Time Taken:
// Author: Shashwat Kumar
// QUESTION LINK: https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position
// Rating: Hard
// Description: Return an array ans of length n, where ans[i] is the length of the longest obstacle course for index i as described above.
// Solved: No
// Learning: How to keep track of history and update it in a way to optimise the answer

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
        vector<int> longestObstacleCourseAtEachPosition(vector<int> &v)
        {
            vector<int> l;
            vector<int> ans;
            for (int i = 0; i < v.size(); i++)
            {
                if (l.empty() || v[i] >= l.back())
                {
                    l.push_back(v[i]);
                    ans.push_back(l.size());
                }
                else
                {
                    int idx = upper_bound(l.begin(), l.end(), v[i]) - l.begin();
                    l[idx] = v[i];
                    ans.push_back(idx + 1);
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