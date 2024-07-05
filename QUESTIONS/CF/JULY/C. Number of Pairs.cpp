// Date: 06-07-2024
// Start Time: 00:17:45
// End Time  : 00:25:43
// Time Taken: 7 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/problemset/problem/1538/C
// Rating: 1300
// Description: find the number of pairs that lie within some sum range
// Solved: Yes
// Learning: Ordered set came in handy again and remember just as in set you cannot do lower_bound() - s.begin()

/****************************************************Pre Processor***************************************************/
#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
    int n, l, r;
    cin >> n >> l >> r;
    ordered_set s;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (i > 0)
        {
            int lb = s.order_of_key(l - temp);
            int up = s.order_of_key(r - temp + 1);
            ans += up - lb;
        }
        s.insert(temp);
    }
    cout << ans << endl;
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