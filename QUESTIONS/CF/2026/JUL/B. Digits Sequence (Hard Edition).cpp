// Date: 24-07-2026
// Start Time: 9:22:17
// End Time  : 10:38:49
// Time Taken: 76 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/problemset/problem/1177/B
// Rating: 1800
// Description: Find the Kth digit in an infinite sequence of numbers
// Solved: Yes
// Learning: Counting problems can also involve Binary seracg

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

vector<long long> bin_pow(19);
pair<long long, bool> check(long long x, long long k)
{
    //    count the number of digits that appear before x
    long long temp = x;
    int digits = 0;
    long long cnt = 0;
    // (O(18))
    while ((temp /= 10) != 0)
    {
        digits++;
        cnt += (__int128)digits * 9 * bin_pow[digits - 1];
        // debug(temp, digits, cnt);
    }
    digits++;
    cnt += digits * (x - bin_pow[digits - 1] + 1);
    // debug(x, cnt);
    return {cnt, cnt >= k};
}

void solve()
{
    long long k;
    cin >> k;
    long long lo = 1;
    long long hi = 1e18;
    long long ans = 1;
    long long num = 1;
    bin_pow[0] = 1;
    for (int i = 1; i < 19; i++)
    {
        bin_pow[i] = 10 * bin_pow[i - 1];
    }
    while (lo <= hi)
    {
        long long mid = lo + (hi - lo) / 2;
        debug(mid);
        pair<long long, bool> cc = check(mid, k);
        if (cc.second)
        {
            ans = cc.first;
            num = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    // (ans - k)th character from right of num
    long long digits = ans - k;
    debug(ans, k, digits);
    int aa = num % 10;
    while (digits)
    {
        num /= 10;
        aa = num % 10;
        digits--;
    }
    cout << aa;
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);

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
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}