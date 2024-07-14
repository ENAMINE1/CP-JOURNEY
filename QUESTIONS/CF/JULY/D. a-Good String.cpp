// Date: 14-07-2024
// Start Time: 15:33:05
// End Time  : 17:24:30
// Time Taken: 111 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/problemset/problem/1385/D
// Rating: 1500
// Description: Find the minimum number of exchange required to make the string a-good
// Solved: Yes
// Learning: How to use dp and bitmask

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

// i need to exactly know how the string has been paritioned till now to get the mid index of the current substring to be partioned
int n;
int rec(int idx, string &s, int mid, int k)
{
    // calculate the number of exchanges required to flip each half of the string
    int l = mid - pow(2, idx - 1);
    int r = l + pow(2, idx) - 1;
    int mm = (l + r) / 2;
    // cout << l << " " << r << " " << mm << endl;
    int ans;
    int cnt1 = 0;
    // debug(char('a' + k - idx));
    for (int i = l; i <= mm; i++)
    {
        if (s[i] != 'a' + (k - idx))
            cnt1++;
    }
    int cnt2 = 0;
    for (int i = mm + 1; i <= r; i++)
    {
        if (s[i] != 'a' + (k - idx))
            cnt2++;
    }
    // debug(cnt1, cnt2, idx, l, r, mm);
    if (idx == 1)
    {
        int temp = 0;
        if ((s[mm] == 'a' + (k - idx) && s[mm + 1] == 'a' + (k - idx + 1)) || (s[mm] == 'a' + (k - idx + 1) && s[mm + 1] == 'a' + (k - idx)))
            temp = 0;
        else if (cnt1 == 0)
        {
            if (s[mm + 1] != 'a' + (k - idx + 1))
                temp = 1;
        }
        else
        {
            if (s[mm] == 'a' + (k - idx + 1))
            {
                if (s[mm + 1] != 'a' + (k - idx))
                    temp = 1;
            }
            else
            {
                if (s[mm + 1] == 'a' + (k - idx) || s[mm + 1] == 'a' + (k - idx) + 1)
                    temp = 1;
                else
                    temp = 2;
            }
        }
        return temp;
    }
    ans = rec(idx - 1, s, (l + mm) / 2 + 1, k) + cnt2;
    ans = min(rec(idx - 1, s, (mm + r) / 2 + 1, k) + cnt1, ans);
    return ans;
}

void solve()
{
    cin >> n;
    int k = log2(n);
    string s;
    cin >> s;
    if (n == 1)
    {
        if (s == "a")
            cout << 0 << endl;
        else
            cout << 1 << endl;
        return;
    }
    cout << rec(k, s, n / 2, k) << endl;
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