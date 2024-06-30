// Date: 30-06-2024
// Start Time: 00:15:29
// End Time  : 01:17:18
// Time Taken: 61 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://atcoder.jp/contests/abc314/tasks/abc314_d
// Rating: 585
// Description: Print the final string after some operations
// Solved: No
// Learning: Got to learn how to keep track of time in the case of queries [IMPORTANT]

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

/****************************************************Definition***************************************************/
#define endl '\n'
#define pb push_back
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repi(i, a, n) for (ll i = a; i < n; i++)
#define repii(i, a, n, b) for (ll i = a; i < n; i += b)
// #define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

/**************************************************Global Variables*************************************************/
const ll MAXM = 1e5;
const int mod = 1e9 + 7;
const int INF = 1e9 + 5;
const long long INFF = 1000000000000000005LL;
const double EPS = 1e-9;
const double PI = acos(-1);
vector<long> factors[MAXM + 5];
vpii dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

/**************************************************Utility Functions***********************************************/
void init()
{
    for (ll i = 1; i <= MAXM; i++)
    {
        for (ll j = i; j <= MAXM; j += i)
        {
            factors[j].pb(i);
        }
    }
}

int bin_pow(int base, int pow)
{
    int ans = 1;
    while (pow)
    {
        if (pow & 1)
        {
            ans = 1LL * ans * base % mod;
        }
        base = 1LL * base * base % mod;
        pow /= 2;
    }
    return ans;
}
/***************************************************Main Function**************************************************/

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    pair<int, int> last_op_time_and_type{1e9, 3};
    vector<pair<int, int>> last_char_update(n, {1e9, 0});
    while (q)
    {
        int t, x;
        char c;
        cin >> t >> x >> c;
        if (t != 1)
        {
            last_op_time_and_type = {q, t};
        }
        else
        {
            last_char_update[x - 1] = {q, c};
            s[x - 1] = c;
        }
        q--;
    }
    cerr << (last_char_update) << endl;
    cerr << last_op_time_and_type;
    if (last_op_time_and_type.second == 2)
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                if (last_char_update[i].first > last_op_time_and_type.first)
                    s[i] += 'a' - 'A';
        }
    else
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                debug(s[i]);
                if (last_char_update[i].first > last_op_time_and_type.first)
                    s[i] += -'a' + 'A';
            }
        }
    // for (int i = 0; i < s.length(); i++)
    // {
    //     cout << after[i];
    // }
    // cout << endl;
    cout << s;
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);

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
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}