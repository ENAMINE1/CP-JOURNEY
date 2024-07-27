// Date: 23-07-2024
// Start Time: 21:06:19
// End Time  : 22:12:51
// Time Taken: 66 minutes
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
    int n;
    cin >> n;
    vector<pair<long long, int>> v(n);
    for (auto &x : v)
    {
        cin >> x.first;
        x.second = 1;
    }
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        // debug(v[i], i);
        while (i < n && (log2l(v[i].first)) >= v[i-1].second *(log2l(v[i - 1].first)))
            i++;
        if (i < n && (log2l(v[i].first)) < v[i - 1].second * (log2l(v[i - 1].first)))
        {
            if(v[i].first == 1)
            {
                cout << -1 << endl;
                return;
            }
            long long y = ceil(v[i - 1].second * log2l(v[i - 1].first) / log2l(v[i].first));
            debug(y);
            y = 1LL << ((int)(ceil(log2l(y))));
            v[i].second = y;
            debug(y, v[i].first,v[i].second, v[i-1].first, v[i-1].second);
            cnt += log2l(y);
        }
    }
    cout << cnt << endl;
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