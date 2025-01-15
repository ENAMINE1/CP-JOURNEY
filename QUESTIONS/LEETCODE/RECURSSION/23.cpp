// Date: 13-01-2025
// Start Time: 19:44:16
// End Time  :
// Time Taken:
// Author: Shashwat Kumar
// QUESTION LINK: https://leetcode.com/problems/merge-k-sorted-lists
// Rating: Hard
// Description: Merge k sorted list
// Solved: Yes
// Learning: Using priority queue to manage the smallest number on top after each iteration

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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Compare
{
public:
    bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int n = lists.size();
        struct ListNode root;
        struct ListNode *curr = &root;
        root.next = NULL;

        priority_queue<ListNode *, vector<ListNode *>, Compare> pq;
        for (int i = 0; i < n; i++)
        {
            if (lists[i] != NULL)
                pq.push(lists[i]);
        }
        while (!pq.empty())
        {
            curr->next = pq.top();
            curr = curr->next;
            ListNode *temp = (pq.top())->next;
            pq.pop();
            if (temp != NULL)
                pq.push(temp);
        }
        return root.next;
    }
};

void solve()
{
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