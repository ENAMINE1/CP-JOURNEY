// Date: 29-07-2024
// Start Time: 21:14:04
// End Time  : 21:17:30
// Time Taken: 3 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://cses.fi/problemset/task/1619/
// Rating: Medium
// Description: Find the max no of people in a room at any point of time
// Solved: No
// Learning: used map to count the number of people at anytime in the room

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
    vector<pair<int, int>> t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int temp;
            cin >> temp;
            t.push_back({temp, j});
        }
    }
    sort(t.begin(), t.end());
    int ans = INT_MIN;
    int cnt = 0;
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i].second == 0)
            cnt++;
        else
            cnt--;
        ans = max(ans, cnt);
    }
    cout << ans;
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