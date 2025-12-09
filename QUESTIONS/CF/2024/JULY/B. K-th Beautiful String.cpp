// Date: 05-07-2024
// Start Time: 22:17:55
// End Time  : 23:59:28
// Time Taken: 101 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/1328/problem/B
// Rating: 1300
// Description: Find the k string with 2 b's and rest a's in lexographically ordering
// Solved: No
// Learning: i was not able to find the index of leftmost b quick enough

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
    int n, k;
    cin >> n >> k;
    // here i iterate over all possible places the leftmost b can possibly be at
    string s(n, 'a');
    // reducing k by 1 then by 2 and then by 3 and so on is equivalent of adding 1 + 2+3 ... such that the sum exceedes of equals to the k
    for (int i = n - 2; i >= 0; i--)
    {
        if (n - 1 - i >= k)
        {
            s[i] = 'b';
            s[n - k] = 'b';
            break;
        }
        k -= n - 1 - i;
    }
    cout << s << endl;
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