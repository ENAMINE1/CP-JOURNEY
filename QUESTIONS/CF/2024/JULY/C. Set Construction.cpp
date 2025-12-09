// Date: 03-07-2024
// Start Time: 17:39:59
// End Time  : 17:55:47
// Time Taken: 15 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/1761/problem/C
// Rating: 1400
// Description: Distribute a permutation to nodes in a graph such that each child is a propersubset of the parent and not connected nodes are not a subset of each other
// Solved: No
// Learning: Read the question properly and also in this question there was an observation that each set will contain the idx of the set in the set

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
    int n;
    cin >> n;
    set<int> ans[n + 1];
    for (int i = 1; i <= n; i++)
    {
        string temp;
        cin >> temp;
        // this is important as i am pushing the idx in the answer
        ans[i].insert(i);
        for (int j = 0; j < n; j++)
        {
            // process the string
            if (temp[j] == '1')
            {
                ans[j + 1].insert(i);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i].size() << " ";
        for (auto it : ans[i])
            cout << it << " ";
        cout << endl;
    }
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