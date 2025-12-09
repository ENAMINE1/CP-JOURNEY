// Date: 15-07-2024
// Start Time: 00:31:55
// End Time  : 01:09:29
// Time Taken: 37 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/1516/problem/B
// Rating: 1500
// Description: Find if you can make all elements of the array equal using the opreation of picking 2 adjacent elements;he then removes them and places a single integer in their place : their bitwise XOR.
// Solved: No
// Learning: Prefix xor and xor properties

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
    vector<int> prexor(n), v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        prexor[i] = v[i];
        if (i > 0)
            prexor[i] ^= prexor[i - 1];
    }
    // cerr << prexor << endl;
    // the funda here is that in the final array you will either end up with 2 elements that are equal or 3 elements, Why?
    // even if you end up with more than 3 elements that have equal value you can further reduce it to 2 elements if the pairity of numbers is even and to 3 numbers if pairity is odd
    // this is just another way of saying that the xor of the entire array is 0 if final number of elements is 2 but is not equivaluednt to say that the final xor is equal to some number and therefore we can reduce the array to some elements with equal value

    // // first i check whether i can reduce the array to 2 parts with equal xor or not
    // for (int i = 0; i < n - 1; i++)
    // {
    //     if (prexor[i] == (prexor[n - 1] ^ prexor[i]))
    //     {
    //         cout << "YES" << endl;
    //         return;
    //     }
    // }
    // // then i check for 3 paritions
    // for (int i = 0; i < n - 2; i++)
    // {
    //     for (int j = i + 1; j < n - 1; j++)
    //     {
    //         int x = prexor[i];
    //         int y = prexor[j] ^ prexor[i];
    //         int z = prexor[n - 1] ^ prexor[j];
    //         debug(x, y, z, i, j);
    //         if (x == y && y == z)
    //         {
    //             cout << "YES" << endl;
    //             return;
    //         }
    //     }
    // }
    // cout << "NO" << endl;

    // another approach is to check for 0 xor of the array this equivalent to partition the array into two subarrays with equal xor
    if (prexor[n - 1] == 0)
    {
        cout << "YES" << endl;
        return;
    }
    // ultimately the xor of 3 equal element is equal to the element therefor we check whether we can partion the sarray into odd sybarrays with equal xor
    int k = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        k ^= v[i];
        if (k == prexor[n - 1])
        {
            cnt++;
            k = 0;
        }
    }
    if (cnt > 2)
    {
        cout << "YES" << endl;
        return;
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