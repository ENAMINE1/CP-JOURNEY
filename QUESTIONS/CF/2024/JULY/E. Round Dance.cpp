// Date: 17-07-2024
// Start Time: 17:48:31
// End Time  : 18:17:40
// Time Taken: 29 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/problemset/problem/1833/E
// Rating: 1600
// Description: Your task is to determine what the minimum and maximum number of round dances could be.
// Solved: No
// Learning: I saw that pattern that the number of cycles of length 2 was the number of chains

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
    int n;
    cin >> n;
    vector<int> v(n + 1), vis(n + 1);
    map<int, int> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        m[i] = v[i];
    }
    // counting the number of chains and cycles
    vector<int> st;
    vis[0] = 1;
    int cycles = 0, chain = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[v[i]] == i)
        {
            chain++;
        }
        if (!vis[i])
        {
            int last;
            if (st.empty())
            {
                st.push_back(i);
                vis[i] = 1;
                last = i;
            }
            while (m.count(st.back()) > 0)
            {
                m.erase(st.back());
                st.push_back(v[st.back()]);
                vis[v[st.back()]] = 1;
            }
            if (last == st.back())
            {
                // there is a cycle
                if (st.size() > 3)
                    cycles++;
            }
            st.clear();
        }
    }
    chain /= 2;
    debug(cycles, chain);
    cout << cycles + (chain > 0) << " " << cycles + chain << endl;
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