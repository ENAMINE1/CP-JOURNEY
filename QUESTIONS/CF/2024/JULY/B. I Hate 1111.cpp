// Date: 18-07-2024
// Start Time: 22:41:32
// End Time  : 23:11:10
// Time Taken: 29 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/1526/problem/B
// Rating: 1400
// Description: Can you make x by summing up some number of 11, 111, 1111, 11111,…    ?
// Solved: No
// Learning: brute force and observation of representing 11111... as 11*a + 111*b

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
    // if n can be represented as a sum of 11,111,1111,1111...
    // then it can ber represented as n = 11*a + 111*b
    // lets represetn b as 11*c + d
    // there are 11 possible values of d and the expression becomes as n = (a + 111*c)*11 + 111d
    // hence the job was to check whether n - 111*d is divisible by 11 or not
    for (int i = 0; i < 11; i++)
    {
        int diff = (n - 111 * i);
        if (diff >= 0 && diff % 11 == 0)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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