// Date: 13-07-2024
// Start Time: 10:32:35
// End Time  : 15:38:49
// Time Taken: 306 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/476/problem/B
// Rating: 1300
// Description: Find the probabitlity of reaching required destination if +ve and -ve moves can be performed
// Solved: No
// Learning: practice of dp with bitmasking

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

int num = 0;
int denom = 0;
int dp[15][1050];
set<int> ss;
// rec tells you the number of ways you can reach the required destination if you start form index i and have already taken bits moves where 1 represents +ve and 0 represents -ve direction
int rec(int idx, int bits, string &s, int req_pos)
{
    // base case
    int n = s.length();
    if (idx == n)
    {
        // process the bits of the number and find the final pos and compare it with req_pos
        int digits = n;
        // debug(bits, digits);
        int pos = 0;
        int x = __builtin_popcount(bits);
        pos += x;
        pos -= digits - x;
        // debug(pos, req_pos);
        if (pos == req_pos)
            return 1;
        return 0;
    }
    // debug(idx, bits, n);
    if (dp[idx][bits] != -1)
        return dp[idx][bits];
    int ans = 0;
    if (s[idx] == '?')
    {
        ans = rec(idx + 1, bits | 1 << (n - idx - 1), s, req_pos) +
              rec(idx + 1, bits, s, req_pos);
    }
    else if (s[idx] == '+')
        ans = rec(idx + 1, bits | 1 << (n - idx - 1), s, req_pos);
    else
        ans = rec(idx + 1, bits, s, req_pos);
    return dp[idx][bits] = ans;
}

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    int len = s1.length();
    int req_pos = 0;
    int q_count = 0;
    for (int i = 0; i < len; i++)
    {
        if (s1[i] == '+')
            req_pos++;
        else
            req_pos--;
        if (s2[i] == '?')
            q_count++;
    }
    denom += pow(2, q_count);
    memset(dp, -1, sizeof(dp));
    cout << setprecision(15) << (double)rec(0, 0, s2, req_pos) / denom << endl;
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