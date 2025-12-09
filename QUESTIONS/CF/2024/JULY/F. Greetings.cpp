// Date: 05-07-2024
// Start Time: 14:58:17
// End Time  : 16:16:09
// Time Taken: 77 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/1915/problem/F
// Rating: 1500
// Description: Find how many many people cross people on their right
// Solved: Yes
// Learning: got to know about Ordered set to use the feature of finding the position of an element in a set in O(log(n)) time

/****************************************************Pre Processor***************************************************/
#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Define the ordered set with order statistics
typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

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
    // int n;
    // cin >> n;
    // vector<pair<int, int>> a(n);
    // vector<int> b(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i].first >> b[i];
    //     a[i].second = i;
    // }
    // set<int> s;
    // sort(a.begin(), a.end());
    // long long ans = 0;
    // while (!a.empty())
    // {
    //     auto [right_most_element, pos] = a.back();
    //     s.insert(b[pos]);
    //     ans += distance(s.begin(), s.lower_bound(b[pos]));
    //     a.pop_back();
    // }
    // cout << ans << endl;
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> b[i];
        a[i].second = i;
    }

    ordered_set s;
    sort(a.begin(), a.end());
    long long ans = 0;

    while (!a.empty())
    {
        auto [right_most_element, pos] = a.back();
        s.insert(b[pos]);

        // Use order_of_key to find the position in O(log n)
        ans += s.order_of_key(b[pos]);

        a.pop_back();
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