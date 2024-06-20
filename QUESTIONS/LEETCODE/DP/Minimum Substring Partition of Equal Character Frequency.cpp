// Date: 20-06-2024
// Start Time: 17:57:19
// End Time  :
// Time Taken:
// Author: Shashwat Kumar
// QUESTION LINK: https://leetcode.com/problems/minimum-substring-partition-of-equal-character-frequency/
// Rating: Medium
// Description: Find the minimum number of balanced substring partitions
// Solved: No
// Learning: How to go through each and every combinatinos effectively

class Solution
{
public:
    int dp[1005];
    bool check(map<int, int> &freq)
    {
        if (freq.size() == 0)
            return true;
        int req_f = freq.begin()->second;
        for (auto it : freq)
        {
            if (it.second != req_f)
                return false;
        }
        return true;
    }

    int rec(int i, string &s)
    {
        int n = s.length();
        if (i == n)
        {
            return 0;
        }
        if (dp[i] != -1)
            return dp[i];
        int ans = INT_MAX;
        map<int, int> m;
        for (int j = i; j < n; j++)
        {
            m[s[j]]++;
            // if i find a balanced substring form i to j then
            if (check(m))
            {
                ans = min(ans, 1 + rec(j + 1, s));
            }
        }
        return dp[i] = ans;
    }

    int minimumSubstringsInPartition(string s)
    {
        // the idea is to check for all possible balanced substrings and the
        // look for balanced substrings in the leftover array and report the min
        memset(dp, -1, sizeof(dp));
        return rec(0, s);
    }
};