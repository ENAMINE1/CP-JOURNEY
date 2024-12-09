// Date: 09-12-2024
// Start Time: 12:56:35
// End Time  :
// Time Taken:
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

/************************************************************************************************Main Function**************************************************/

void solve()
{
    class Solution
    {
    public:
        vector<int> temp;
        vector<bool> isArraySpecial(vector<int> &n, vector<vector<int>> &q)
        {
            int len = n.size();
            temp.resize(len);
            int cnt = 0;
            for (int i = 0; i < len; i++)
            {
                if (i == 0 || !(abs(n[i] - n[i - 1]) & 1))
                    cnt++;

                temp[i] = cnt;
            }
            vector<bool> ans;
            for (int i = 0; i < q.size(); i++)
            {
                if (temp[q[i][0]] == temp[q[i][1]])
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