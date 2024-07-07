// Date: 07-07-2024
// Start Time: 21:55:09
// End Time  : 22:11:14
// Time Taken: 16 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/1983/problem/B
// Rating: 1100
// Description: find whether you can convert a matrix to b
// Solved: Yes
// Learning: brute force need practice as i was not able to think quickly

/****************************************************Pre Processor***************************************************/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#include "./lib/debug.h"
#include "./lib/print.h"
#else
#define debug(...) 42
#endif
#define endl '\n'
/***************************************************Main Function**************************************************/

int r, c;
bool can_change(vector<vector<int>> &a, vector<vector<int>> &b)
{
    for (int row = 0; row < r - 1; row++)
    {
        for (int col = 0; col < c - 1; col++)
        {
            int diff = (b[row][col] - a[row][col] + 3) % 3;
            if (diff)
            {
                a[row][col] = b[row][col];
                a[row][col + 1] = (a[row][col + 1] + (diff ^ 3)) % 3;
                a[row + 1][col] = (a[row + 1][col] + (diff ^ 3)) % 3;
                a[row + 1][col + 1] = (a[row + 1][col + 1] + diff) % 3;
            }
        }
        // debug(row, b[row][c - 1] ,a[row][c - 1]);
        if (b[row][c - 1] != a[row][c - 1])
            return false;
    }
    for (int i = 0; i < c; i++)
    {
        // debug(i, b[r - 1][i], a[r - 1][i]);
        if (b[r - 1][i] != a[r - 1][i])
            return false;
    }
    return true;
}

void solve()
{
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c)), b(r, vector<int>(c));
    for (int row = 0; row < r; row++)
    {
        string s;
        cin >> s;
        for (int col = 0; col < c; col++)
        {
            int temp = s[col] - '0';
            a[row][col] = temp;
        }
    }
    for (int row = 0; row < r; row++)
    {
        string s;
        cin >> s;
        for (int col = 0; col < c; col++)
        {
            int temp = s[col] - '0';
            b[row][col] = temp;
        }
    }
    if (can_change(a, b))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);

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
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}