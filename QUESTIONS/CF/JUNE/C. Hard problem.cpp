// Date: 24-06-2024
// Start Time: 23:51:15
// End Time  : 00:33:11
// Time Taken: 40 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/706/problem/C
// Rating: 1600
// Description: Find the cost of total number of string reversals
// Solved: Yes
// Learning: nothing

/****************************************************Pre Processor***************************************************/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#ifdef LOCAL
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

int n;
vector<string> v;
vector<int> cost;

long long dp[1000005][2];
ll rec(int idx, int rev)
{
    if (idx == n)
    {
        return 0;
    }
    if (dp[idx][rev] != -1)
        return dp[idx][rev];
    string temp = v[idx - 1];
    if (rev)
    {
        reverse(temp.begin(), temp.end());
    }
    string curr = v[idx];
    debug(temp, rev, curr, idx);
    long long ans = 0;
    if (curr >= temp)
    {
        reverse(curr.begin(), curr.end());
        if (curr >= temp)
            ans = min(rec(idx + 1, 0), cost[idx] + rec(idx + 1, 1));
        else
            ans = rec(idx + 1, 0);
    }
    else
    {
        reverse(curr.begin(), curr.end());
        if (curr >= temp)
            ans = cost[idx] + rec(idx + 1, 1);
        else
            ans = 1e18;
    }
    return dp[idx][rev] = ans;
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    v.assign(n, "");
    cost.assign(n, 0);
    rep(i, n)
            cin >>
        cost[i];
    rep(i, n)
            cin >>
        v[i];

    long long ans = min(rec(1, 0), cost[0] + rec(1, 1));
    if (ans >= (long long)1e16)
        cout << -1;
    else
        cout << ans;
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