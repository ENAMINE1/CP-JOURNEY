// Date: 15-07-2024
// Start Time: 09:43:47
// End Time  : 11:05:08
// Time Taken: 81 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/1661/problem/B
// Rating: 1300
// Description: Find the minimum number of operations to make the number divisible by 32768
// Solved: No
// Learning: i had to simply loop for all the possible values of number of operations

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
const int N = 32768;
long long rec(int x)
{
    int ans = INT_MAX;
    for (int i = 0; i <= 15; i++)
    {
        for (int j = 0; j <= 15; j++)
        {
            if ((int)((x + i) * pow(2, j)) % N == 0)
            {
                ans = min(ans, i + j);
            }
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        cout << rec(v[i]) << " ";
    }
    cout << endl;
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