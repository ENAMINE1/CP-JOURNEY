// Date: 23-12-2025
// Start Time: 11:24:24
// End Time  : 11:34:53
// Time Taken: 10 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/problemset/problem/2167/D
// Rating: 1000
// Description: Find smallest number x such that gcd(ai,x) = 1
// Solved: No
// Learning: Implementation probelem ans also revised gcd and learnt that in the problem you should think the problems involving gcd or lcm, the numbers as product of powers of prime factors that will you give you insights

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
/***************************************************Main Function**************************************************/

// here b should be the smaller number among a and b
// TC : log(min(a, b))
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

/*
    Here for all numbers you need to find the element x such that gcd(ai, x) = 1 so complexity required should be less than n^2
    answer is always smallest prime that is not a prime factor of ai
    this can be calculated in less time because 2 * 3 * ... * 53 > 10 ^ 18 and if the number has all of these prime factors then return -1

    so for each ai you need to iterate through the primes from 2 to 53 to find whether they are a factor of ai
*/
void solve()
{
    int n;
    cin >> n;
    // TC O(n * 15);
    int ans = INT_MAX;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        long long curr;
        cin >> curr;
        for (auto prime : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53})
        {
            if (curr % prime != 0)
            {
                ans = min(ans, prime);
                flag = true;
                break;
            }
        }
    }
    if (!flag)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);

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
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}