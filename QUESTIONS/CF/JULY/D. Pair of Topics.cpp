// Date: 06-07-2024
// Start Time: 00:37:21
// End Time  : 00:42:30
// Time Taken: 5 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/problemset/problem/1324/D
// Rating: 1400
// Description: find the number of pairs such that ai + aj > bi + bj
// Solved: Yes
// Learning: Yet another problem that was easily solved by ordered_Set

/****************************************************Pre Processor***************************************************/
#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#ifdef LOCAL
#include "./lib/print.h"
#include "./lib/debug.h"
#else
#define debug(...) 42
#endif
#define endl '\n'

typedef tree<
    int,
    null_type,
    less_equal<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
/************************************************************************************************Main Function**************************************************/

void solve()
{
    int n;
    cin >> n;
    ordered_set s;
    vector<pair<int, int>> v(n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
        cin >> v[i].first;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].second;
        if (i > 0)
        {
            ans += s.order_of_key(v[i].first - v[i].second);
        }
        s.insert(v[i].second - v[i].first);
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