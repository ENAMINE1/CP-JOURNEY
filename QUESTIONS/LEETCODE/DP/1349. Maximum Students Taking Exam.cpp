// Date: 08-07-2024
// Start Time: 15:45:13
// End Time  : 22:50:14
// Time Taken: 425 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://leetcode.com/problems/maximum-students-taking-exam/description/
// Rating: Medium
// Description: Find the places where you can seat a studen so that they cannot cheat in an exam
// Solved: Yes
// Learning: Leraned about digit dp, right now it is recurssive so gave TLE

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
vector<vector<int>> possible_config;
int b = 0;
int mm, nn;
void rec(int r, int c, vector<vector<int>> &con, int &a)
{
    if (r == mm + 1)
    {
        b = max(b, a);
        return;
    }
    if (c == nn + 1)
        rec(r + 1, 1, con, a);
    else
    {
        if (!(con[r][c - 1] == 1 || con[r - 1][c - 1] == 1 || con[r - 1][c + 1] == 1) && con[r][c] == 0)
        {
            debug(r, c);
            cerr << con[r - 1] << endl;
            con[r][c] = 1;
            a++;
            rec(r, c + 1, con, a);
            a--;
            con[r][c] = 0;
        }
        rec(r, c + 1, con, a);
    }
}

int maxStudents(vector<vector<char>> &seats)
{
    int m = seats.size();
    mm = m;
    int n = seats[0].size();
    nn = n;
    vector<vector<int>> room(m + 2, vector<int>(n + 2));
    possible_config.assign(m + 2, vector<int>(n + 2));
    for (int i = 0; i < m + 2; i++)
    {
        room[i][0] = room[i][n + 1] = 2;
        if (i == 0 || i == m + 1)
        {
            for (int k = 1; k <= n; k++)
                room[i][k] = 2;
        }
        else
        {
            for (int k = 0; k < n; k++)
            {
                if (seats[i - 1][k] == '.')
                    room[i][k + 1] = 0;
                else
                    room[i][k + 1] = 2;
            }
        }
        possible_config[i] = room[i];
    }
    int ans = 0;
    rec(1, 1, possible_config, ans);
    cout << b;
    return b;
}
void solve()
{
    int m, n;
    cin >> m >> n;
    vector<vector<char>> seats(m, vector<char>(n));
    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            cin >> seats[r][c];
        }
    }
    maxStudents(seats);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
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