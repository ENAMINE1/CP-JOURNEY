// Date: 15-05-2025
// Start Time: 15:43:03
// End Time  :
// Time Taken:
// Author: Shashwat Kumar
// QUESTION LINK:https://leetcode.com/problems/course-schedule-iii
// Rating: Hard
// Description: Give cetain tasks with duration and deadline, complete max number of tasks
// Solved: No
// Learning: Greedily add all the tasks you can and replace current task if cannot be completed within the deadline with the longest task chosen till now, basically it ruled out the thought of trying all possible set of tasks

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
    class Solution
    {
    public:
        int scheduleCourse(vector<vector<int>> &courses)
        {
            // basically i will take all the courses till now and check if taking
            // the current course excess the deadline if yes then i will try to
            // replace the current course with the largest course taken till now and
            // check if the deadline exceeds or not if not then replce it and if yes
            // then do not take this course

            int n = courses.size();
            vector<pair<int, int>> vp;
            for (auto el : courses)
            {
                vp.push_back({el[1], el[0]});
            }
            sort(vp.begin(), vp.end());

            priority_queue<int> pq;
            int total_time = 0;
            for (int i = 0; i < n; i++)
            {
                if (total_time + vp[i].second <= vp[i].first)
                {
                    total_time += vp[i].second;
                    pq.push(vp[i].second);
                }
                else
                {
                    if (!pq.empty())
                    {
                        int max_course_time_till_now = pq.top();
                        if (vp[i].second < max_course_time_till_now)
                        {
                            pq.pop();
                            pq.push(vp[i].second);
                            total_time += (vp[i].second - max_course_time_till_now);
                        }
                    }
                }
            }
            return pq.size();
        }
    };
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