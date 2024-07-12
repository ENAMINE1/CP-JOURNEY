// Date: 12-07-2024
// Start Time: 12:34:04
// End Time  : 12:49:46
// Time Taken: 15 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/1992/problem/E
// Rating: 1200
// Description: Find the number of pairs a and b such that n*a(in string) - b == n*a - b
// Solved: No
// Learning: here you had to just iterate over 10 possible values of b and need not append the string n a times

/****************************************************Pre Processor***************************************************/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#include "./lib/debug.h"
// #include "./lib/print.h"
#else
#define debug(...) 42
#endif
#define endl '\n'
/***************************************************Main Function**************************************************/

void solve()
{
    int n;
    cin >> n;
    string s = to_string(n);
    int sz = s.size();
    vector<pair<int, int>> v;
    // the catch here is that there are only few possible values of b as the maximum number of digits in a number n * a is 7 so we would choose those values of b after fixing a such that the characters in the ramining string are less than 8 in count and then check for the integer value of it

    // so instead of appending string s a times it is best to keep only few characters of the string because anyways the later characters will be deleted

    // here i append s 16 times just to be sure that the length of s > 8

    s += s, s += s, s += s, s += s;
    for (long long a = 1; a <= 10000; a++)
    {
        long long num = 0;
        // here i consider the first x characters in the string
        for (int x = 1; x <= min(sz * a, 10LL); x++)
        {
            num = num * 10 + s[x - 1] - '0';
            int b = sz * a - x;
            if (1LL * n * a - b == num && b != 0)
            {
                v.push_back({a, b});
            }
        }
    }
    cout << v.size() << endl;
    for (auto [a, b] : v)
        cout << a << " " << b << endl;
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