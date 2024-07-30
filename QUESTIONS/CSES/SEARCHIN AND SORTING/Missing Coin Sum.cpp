// Date: 30-07-2024
// Start Time: 13:22:34
// End Time  : 13:29:17
// Time Taken: 6 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://cses.fi/problemset/task/2183/
// Rating: Medium
// Description: find the smallest sum that you cannot create with the given coins
// Solved: No
// Learning: when the constraint is large and you need to consider subsets then think of sorting and prefix sum or some other property

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

// this is basically a subset sum problem where you need to check for each i from 0 to max sum that whether you can create the sum or not
// here after sorting imagine we maintain a sum array
// say the input is 1 2 2 7 9
// so for every number we have two options take it or not take it in the sum
// 0 1 is the sum array after considering 1
// 0 1 2 3 after considering 2
// you will se that we have created all the numbers from 0 to x and if the next number is greater than x + 1 then we will not be able to create x + 1

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > sum + 1)
        {
            cout << sum + 1;
            return;
        }
        sum += v[i];
    }
    cout << sum + 1;
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