// Date: 22-12-2025
// Start Time: 15:01:12
// End Time  : 15:11:36
// Time Taken: 10 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/1775/problem/B
// Rating: 1300
// Description: Find two different subsequences a and b of the original array, for which f(a)=f(b), where f(x) is the bitwise OR of all of the numbers in the sequence x.
// Solved: NO
// Learning: Thinking in terms of bits (see code)

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

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> input;
    map<int, int> freq;
    // take input
    for (int i = 0; i < n; i++)
    {
        int set_bit_count;
        cin >> set_bit_count;
        vector<int> num;
        for (int j = 0; j < set_bit_count; j++)
        {
            int bit;
            cin >> bit;
            num.push_back(bit);
            freq[bit]++;
        }
        input.push_back(num);
    }
    /*
    if for any number i find that all of its bits have freq >= 2 over all numbers then one subsequene can be set of all numbers and other can be again set of all numbers but excluding the current number

    also if every number has a bit set such that no other number has that bit set then either we dont use that number in both the sub sequence or use it in both

    now if every number has such a unique bit set then we cannot create 2 subsequence such that they have same or
    */
    for (auto number : input)
    {
        int flag = 1;
        for (auto set_bit : number)
        {
            if (freq[set_bit] == 1)
            {
                flag = 0;
                break;
            }
        }
        // if all the bits of the current number have freq > 1
        if (flag == 1)
        {
            cout << "YES" << endl;
            return;
        }
    }
    // it means that all numbers have a unique bit and in that case i cannot create 2 subsequence having same OR
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