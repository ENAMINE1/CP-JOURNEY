// Date: 04-07-2024
// Start Time: 23:19:18
// End Time  : 23:50:13
// Time Taken: 30 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/1973/problem/C
// Rating: 1700
// Description: Find a permutation such that adding this per to a given permutation give max no of peaks in another array where a[i] = p[i] + q[i]
// Solved: No
// Learning: Observation is key as for any permutation we can generate a q which satisfies the condition and also assigning new values in q according the value in p was new learning

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
    vector<int> p(n);
    vector<pair<int, int>> good, bad;
    int max_el_idx;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        if (p[i] == n)
            max_el_idx = i;
    }
    // x basically tels me whether the max element is at odd index or even index
    int x = (max_el_idx) % 2;
    debug(x, max_el_idx);
    // if x is odd then i push all the elements in the even indices to bad array
    for (int i = x ^ 1; i < n; i += 2)
        bad.push_back({p[i], i});
    for (int i = x; i < n; i += 2)
        good.push_back({p[i], i});
    sort(good.begin(), good.end(), greater<pair<int, int>>());
    sort(bad.begin(), bad.end(), greater<pair<int, int>>());
    vector<int> q(n);
    // here i assign smaller values to bad array ensuring that there value is <= n
    int cv = 1;
    for (auto [_, ind] : bad)
        q[ind] = cv++;
    for (auto [_, ind] : good)
        q[ind] = cv++;
    for (int i = 0; i < n; i++)
    {
        cout << q[i] << " ";
    }
    cout << endl;
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