// Date: 03-07-2024
// Start Time: 11:38:26
// End Time  : 11:43:57
// Time Taken: 5 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://cses.fi/problemset/task/1642/
// Rating: Easy
// Description: Find the indices of 4 numbers whose sum is equal to the required value
// Solved: No
// Learning: Learned how to enumberate over all the unique pairs in an array in a new way

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
    // the idea is similar to two sum to keep track of sum seen till now and store their indices to use later is ht left over sum is encountered
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    map<int, pair<int, int>> mm; // to find the left 2 indices with the left sum
    for (auto &x : v)
        cin >> x;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (mm.count(m - v[i] - v[j]) > 0)
            {
                int key = m - v[i] - v[j];
                cout << mm[key].first + 1 << " " << mm[key].second + 1 << " " << i + 1 << " " << j + 1;
                return;
            }
        }
        // this is the important part of inserting all the possible uniques pairs in the map where both the indices are less equal to i
        for (int j = 0; j < i; j++)
        {
            mm.insert({v[i] + v[j], {j, i}});
        }
    }
    cout << "IMPOSSIBLE";
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