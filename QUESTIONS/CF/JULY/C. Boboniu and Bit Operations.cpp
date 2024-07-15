// Date: 15-07-2024
// Start Time: 11:55:13
// End Time  : 12:29:04
// Time Taken: 33 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/problemset/problem/1395/C
// Rating: 1600
// Description: Boboniu gives you two sequences of non-negative integers a1,a2,…,an and b1,b2,…,bm. For each i (1≤i≤n), you're asked to choose a j (1≤j≤m) and let ci=ai&bj, where & denotes the bitwise AND operation. Note that you can pick the same j for different i's.Find the minimum possible c1|c2|…|cn, where | denotes the bitwise OR operation.
// Solved: No
// Learning: Brute force over the values of the answer

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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    vector<int> c(n, INT_MAX);
    for (int k = 0; k < (1 << 9); k++)
    {
        // here k is the probable answer
        int ans = true;
        for (int i = 0; i < n; i++)
        {
            bool found = false;
            for (int j = 0; j < m; j++)
            {
                c[i] = a[i] & b[j];
                if ((c[i] | k) == k)
                {
                    found = true;
                    break;
                }
            }
            ans = ans && found;
        }
        if (ans)
        {
            cout << k << endl;
            return;
        }
    }
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