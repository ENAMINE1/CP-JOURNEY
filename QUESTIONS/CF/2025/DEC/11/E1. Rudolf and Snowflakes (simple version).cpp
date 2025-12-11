// Date: 11-12-2025
// Start Time: 13:01:45
// End Time  : 14:13:38
// Time Taken: 71 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/1846/problem/E1
// Rating: 1300
// Description: Check whether the GP sum is equal to a given number where you are free to choose the numebr of elements in the gp and also the first element of gp
// Solved: YES with a little help
// Learning: I was getting overflow so learned to tackel that and some times there are easier ways of doing things like computing the gp instead of using the custom bin_pow which lead to overflow

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

long long INF = 1e18;

long long bin_pow(long long a, int b)
{
    debug(a, b);
    long long ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    debug(ans);
    return ans;
}

long long gp(int a, int n)
{
    // basically calculating the gp
    long long curr = 1;
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (curr > INF / a)
            return -1;
        curr *= a;
        if (INF - curr < ans)
            return -1;
        ans += curr;
    }
    return ans;
}

bool check(int k, int depth, int n)
{
    long long val = gp(k, depth);
    if (val == -1)
        return true;
    return val >= n;
}

void solve()
{
    int n;
    cin >> n;
    if (n < 7)
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        for (int depth = 2; depth <= 20; depth++)
        {
            int lo = 2;
            int hi = 1000;
            int ans = hi;
            while (lo <= hi)
            {
                long long k = (lo + hi) / 2;
                debug(k, depth);
                if (check(k, depth, n))
                {
                    ans = k;
                    hi = k - 1;
                }
                else
                    lo = k + 1;
            }
            // if k and depth mathches n then break;
            if (gp(ans, depth) == n)
            {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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