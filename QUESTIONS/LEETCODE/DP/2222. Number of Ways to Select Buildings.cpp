// Date: 08-07-2024
// Start Time: 12:11:10
// End Time  : 13:40:39
// Time Taken: 89 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://leetcode.com/problems/number-of-ways-to-select-buildings/description/
// Rating: Medium
// Description: find the numebr of ways of choosing 010 or 101 from a binary string
// Solved: Yes
// Learning: Decompose the bigger statement to an easier problem just as the description

/****************************************************Pre Processor***************************************************/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#include "./lib/debug.h"
#include "./lib/print.h"
#else
#define debug(...) 42
#endif
#define endl '\n'
/***************************************************Main Function**************************************************/

// string a;
// long long dp[100005][3][4];
// long long rec(int idx, int last_chosen, int left, string &s)
// {
//     // debug(idx, left, last_chosen);
//     int n = s.length();
//     if (idx == n)
//     {
//         if (left == 0)
//         {
//             // cout << a << endl;
//             return 1;
//         }
//         return 0;
//     }
//     if (left == 0)
//     {
//         // cout << a << endl;
//         return 1;
//     }
//     if (dp[idx][last_chosen][left] == -1)
//     {
//         long long ans = 0;
//         if (s[idx] - '0' != last_chosen)
//         {
//             a.push_back(s[idx]);
//             // cout << a << endl;
//             ans += rec(idx + 1, s[idx] - '0', left - 1, s);
//             a.pop_back();
//         }
//         ans += rec(idx + 1, last_chosen, left, s);
//         dp[idx][last_chosen][left] = ans;
//     }
//     return dp[idx][last_chosen][left];
// }

// long long numberOfWays(string s)
// {
//     memset(dp, -1, sizeof(dp));
//     return rec(0, 2, 3, s);
// }

long long numberOfWays(string s)
{
    int n = s.size();
    int cnt0 = 0;
    for (char &c : s)
        cnt0 += c == '0';
    int cnt1 = n - cnt0;
    int c0 = 0, c1 = 0;
    long long ans = 0;
    for (char &c : s)
    {
        if (c == '0')
        {
            // c1 is the count of number of 1 on my left and rest on my right
            ans += c1 * (cnt1 - c1);
            ++c0;
        }
        else
        {
            // same here for number of 0s on my left and rest 0s on my right
            ans += c0 * (cnt0 - c0);
            ++c1;
        }
    }
    return ans;
}
void solve()
{
    string s;
    cin >> s;
    cout << numberOfWays(s) << endl;
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