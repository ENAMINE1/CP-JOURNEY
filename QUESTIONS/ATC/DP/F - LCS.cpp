// Date: 14-06-2024
// Start Time: 22:52:15
// End Time  : 23: 30:23
// Time Taken: 38 min
// Author: Shashwat Kumar
// QUESTION LINK: https://atcoder.jp/contests/dp/tasks/dp_f
// Rating: Easy
// Description: Pring the longest common subsequence of 2 strings
// Solved: No
// Learning: How to print the subsequence

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int i = n, j = m;
    string ans;
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            ans.push_back(s[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
            j--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}
