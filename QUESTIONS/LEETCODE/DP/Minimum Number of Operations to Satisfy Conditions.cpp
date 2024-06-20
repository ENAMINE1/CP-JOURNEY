
// Date: 20-06-2024
// Start Time: 16:50:30
// End Time  :
// Time Taken:
// Author: Shashwat Kumar
// QUESTION LINK: https://leetcode.com/problems/minimum-number-of-operations-to-satisfy-conditions/
// Rating: Medium
// Description: Find the minimum number of operations required to makk the column values same but different from the previoius column
// Solved: Yes
// Learning: How to prepocess the given data to reduce the time complexity of the problem

class Solution
{
public:
    int dp[1005][11];

    int rec(int col, int prev, vector<vector<int>> &changes,
            vector<vector<int>> &v)
    {
        int m = v[0].size();
        if (col == m)
            return 0;
        int ans = INT_MAX;

        if (dp[col][prev] != -1)
        {
            return dp[col][prev];
        }
        for (int i = 0; i < 10; i++)
        {
            if (i != prev)
            {
                ans = min(ans, rec(col + 1, i, changes, v) + changes[col][i]);
            }
        }
        return dp[col][prev] = ans;
    }

    int minimumOperations(vector<vector<int>> &v)
    {
        int n = v.size();
        int m = v[0].size();
        // i need to preprocess the number of changes required in a col to
        // achive a common number between 0 to 9 for each column for that i will
        // ned the frequency of each number in each column

        memset(dp, -1, sizeof(dp));

        vector<vector<int>> changes(m, vector<int>(10, 0)),
            freq(m, vector<int>(10, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                freq[j][v[i][j]]++;
            }
        }

        for (int col = 0; col < m; col++)
        {
            for (int target = 0; target < 10; target++)
            {
                changes[col][target] = n - freq[col][target];
            }
        }
        return rec(0, 10, changes, v);
    }
};