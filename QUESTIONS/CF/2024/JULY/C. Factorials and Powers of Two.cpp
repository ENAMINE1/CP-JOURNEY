// Date: 15-07-2024
// Start Time: 14:39:04
// End Time  : 18:44:14
// Time Taken: 245 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/1646/problem/C
// Rating: 1500
// Description: You are given a positive integer n.Find the minimum number k such that n can be represented as the sum of k distinct powerful numbers, or say that there is no such k.
// Solved: No
// Learning: Bit masking and bruteforce

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

vector<long long> fact;
void solve()
{
    int start = 3;
    fact.push_back(6);
    while (fact.back() <= 1e12)
        fact.push_back(fact.back() * (++start));
    // cout << fact << endl;
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        int ans = INT_MAX;
        // i can break the number n into sum of some factorials and rest sum of powers of 2
        // here i choose some factorials and the accordingly choose powers of 2
        for (long long mask = 0; mask <= (1 << 14); mask++)
        {
            // here the bit representation of mask represents the numbers taken or not taken in the product
            long long x = 0;
            for (int i = 0; i < 14; i++)
            {
                // cout << ((mask & (1LL << (14 - i))) > 0);
                if (mask & (1LL << i))
                    x += fact[i];
            }
            // cout << endl;
            if (x <= n)
            {
                ans = min(ans, __builtin_popcountll(mask) + __builtin_popcountll(n - x));
                // cout << x << " " << n - x << " " << ans << endl;
            }
            else
                break;
        }
        cout << ans << endl;
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