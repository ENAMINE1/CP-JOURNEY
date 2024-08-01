// Date: 01-08-2024
// Start Time: 17:00:22
// End Time  : 17:05:04
// Time Taken: 4 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://leetcode.com/problems/number-of-matching-subsequences/description/
// Rating: Medium
// Description: Find the number of strings which are a subsequence of a given string
// Solved: No
// Learning: Learned to keep track of the indices of characters of a string and use binary search to optimise on finding a string as a subsequence

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
    int m;
    cin >> m;
    string s;
    cin >> s;
    vector<string> w(m);
    for (int i = 0; i < m; i++)
    {
        cin >> w[i];
    }
    int n = s.size();
    // store the index of occurance of each character in the string s
    vector<vector<int>> aa(26);

    for (int i = 0; i < n; i++)
    {
        aa[s[i] - 'a'].push_back(i);
    }

    for (int i = 0; i < 26; i++)
    {
        aa[i].push_back(n);
    }
    int cnt = 0;
    for (auto i : w)
    {
        int x = -1;
        // find the index of the character in the string i in string s
        for (auto j : i)
        {
            x = *upper_bound(aa[j - 'a'].begin(), aa[j - 'a'].end(), x);
            if (x == n)
                break;
        }
        if (x < n)
        {
            cnt++;
        }
    }
    cout << cnt;
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

/*

Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
Example 2:

Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2


*/