// Date: 11-12-2025
// Start Time: 20:23:46
// End Time  : 13:21:25
// Time Taken: -422 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/2176/problem/C
// Rating: 1200
// Description: You are given n coins with given denominations and must perform exactly k picks (for each 𝑘 = 1 … 𝑛 k=1…n). You place picked coins into a bag, but whenever the bag’s total sum becomes even, it is immediately emptied. Your final score is the sum remaining in the bag after all k actions. For each  𝑘 k, determine the maximum possible final score by choosing the order and selection of coins optimally.
// Solved: No
// Learning: Think a littel bit more it was easy

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
/***************************************************Main Function**************************************************/

/*
    can you always keep the intermediate value odd?
    if no odd denominations then return 0
    if atleast one odd then return sum of all k - 1 even numbers and one odd

    what if number of even numbers is < k - 1?
        then i need to first choose odd numbers till the number of even coins is >= k - 1
*/
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    vector<long long> e, o;
    e.push_back(0);
    for (int i = 0; i < n; i++)
    {
        if (v[i] & 1)
            o.push_back(v[i]);
        else
            e.push_back(v[i]);
    }
    if (o.size() == 0)
    {
        for (int i = 0; i < n; i++)
        {
            cout << 0 << " ";
        }
        cout << endl;
        return;
    }
    int mx = o[0];
    int even_len = e.size();
    int odd_len = o.size();
    for (int i = 1; i < even_len; i++)
    {
        e[i] += e[i - 1];
    }
    for (int i = odd_len - 2; i >= 0; i--)
    {
        o[i] += o[i + 1];
    }
    for (int k = 1; k <= n; k++)
    {
        // i need to choose k coins -> 1 odd and rest even
        debug(k, even_len, odd_len);
        if (even_len >= k)
            cout << mx + e[k - 1] << " ";
        else
        {
            // compute the k - odd_len sum of odd vector
            // TODO:
            int to_take = k - even_len;
            long long ans;
            debug(to_take);
            if (o[odd_len - to_take] % 2)
                to_take++;
            debug(to_take);
            if (to_take == odd_len || to_take == k)
                ans = 0;
            else
            {
                ans = mx + e[k - 1 - to_take];
            }
            cout << ans << " ";
        }
    }
    cout << endl;
    return;
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