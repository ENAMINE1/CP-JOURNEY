// Date: 25-06-2024
// Start Time: 15:39:16
// End Time  :
// Time Taken:
// Author: Shashwat Kumar
// QUESTION LINK: https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/
// Rating: Medium
// Description: You are given an integer array prices representing the daily price history of a stock, where prices[i] is the stock price on the ith day. Return the number of smooth descent periods.
// Solved: Yes
// Learning: Stuffing the new way to count substrings, the main learnig is that suppost you have a number 54321 so the number of substrings = #(substrings of 5432) + #(substrings of 4321) + 1 (because of 54321 itself)

class Solution
{
public:
    long long getDescentPeriods(vector<int> &v)
    {
        int n = v.size();
        int cnt = 1;
        long long ans = 1;
        for (int i = 1; i < n; i++)
        {
            if (v[i] == v[i - 1] - 1)
                cnt++;
            else
                cnt = 1;
            ans += cnt;
        }
        return ans;
    }
};