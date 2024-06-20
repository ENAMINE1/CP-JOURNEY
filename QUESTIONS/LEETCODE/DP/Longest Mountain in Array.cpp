// Date: 20-06-2024
// Start Time: 22:18:33
// End Time  :
// Time Taken:
// Author: Shashwat Kumar
// QUESTION LINK: https://leetcode.com/problems/longest-mountain-in-array/description/
// Rating: Medium
// Description: find the longest mountain in the given array
// Solved: No
// Learning: How to use multiple passes to get the answer for each index and also how one pass can do the job as well

class Solution
{
public:
    int longestMountain(vector<int> &v)
    {
        int n = v.size();
        // this solution is in one pass
        int down = 0, up = 0, res = 0;
        for (int i = 1; i < v.size(); i++)
        {
            // view the if condition as if you are in a valley where down tells
            // you what is on your left that is if it is > 0 it means you have a
            // mountain on your left else a valley or a plain
            if (down && v[i - 1] < v[i] || v[i - 1] == v[i])
                down = up = 0;
            up += v[i - 1] < v[i];
            down += v[i - 1] > v[i];
            if (up && down)
                res = max(res, up + down + 1);
        }
        return res;
    }
};