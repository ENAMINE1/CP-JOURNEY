// Date: 18-06-2024
// Start Time: 12:01:03
// End Time  : 12:19:20
// Time Taken: 18 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://www.hackerrank.com/contests/goc-cdc-series-30/challenges/good-and-beautiful
// Rating: Medium
// Description: Find the subsequence with max sum where the subsequence should not consist of consecutive integers
// Solved: No
// Learning: I coudnt see how to use dp in the problem.

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

void solve()
{
    int n;
    cin >> n;
    ll a[n];
    ll dp[n + 1];
    rep(i, n)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    // dp[n] is set to 0 to handel upper_bound and lower_bound
    dp[n] = 0;
    dp[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        // two possible cases i take the ith element in my sum or not
        // CASE 1
        // if i take the current element then it is optimal to take all occurance of it to maximize the sum
        int idx1 = lower_bound(a, a + n, a[i] + 1) - a;
        int idx2 = upper_bound(a, a + n, a[i] + 1) - a;
        int freq = idx1 - i;
        ll ans = a[i] * freq + dp[idx2];
        ans = max(ans, dp[idx1]);
        dp[i] = ans;
    }
    cout << dp[0];
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