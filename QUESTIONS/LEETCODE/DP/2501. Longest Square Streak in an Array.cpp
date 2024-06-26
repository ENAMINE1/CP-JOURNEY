// Date: 26-06-2024
// Start Time: 13:19:28
// End Time  :
// Time Taken:
// Author: Shashwat Kumar
// QUESTION LINK: https://leetcode.com/problems/longest-square-streak-in-an-array/description/
// Rating: Medium
// Description: find the longest square subsequence
// Solved: Yes
// Learning: using second form but also got to know how to use constraints as here the recursion stack wont grow a lot

class Solution
{
public:
    // O(nlogn)
    int dp[100005];
    // returns me the longes subsequence starting from idx
    int rec(int idx, vector<int> &v)
    {
        if (dp[idx] != -1)
            return dp[idx];
        int ans = 1;
        int curr = v[idx];
        if (auto it = lower_bound(v.begin() + idx, v.end(), 1LL * curr * curr);
            it != v.end() && 1LL * curr * curr == *it)

        {
            ans += rec(it - v.begin(), v);
        }
        return dp[idx] = ans;
    }

    int longestSquareStreak(vector<int> &v)
    {
        sort(v.begin(), v.end());
        int n = v.size();
        memset(dp, -1, sizeof(dp));
        // start form idx 0 and find the pos of v[i] * v[i] if found  say j then
        // add 1 to the current length of the square streak and then recursively
        // find the pos of v[j] * v[j] and cotinue for each i you will at max go
        // in to the recusion stack for 6 or 7 steps
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, rec(i, v));
        }
        return (ans == 1) ? -1 : ans;
    }
};