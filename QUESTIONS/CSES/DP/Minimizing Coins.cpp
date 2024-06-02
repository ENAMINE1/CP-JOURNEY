// Date: 27-05-2024
// Start Time: 21:38:10
// End Time  : 22:08:54
// Time Taken: 30 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://cses.fi/problemset/result/9373731/
// Rating: Medium
// Description: min no of coins required to achive the required sum (not a subset problem)
// Solved: YES
// Learning: what values to return when in base case

/***********************************************Pre Processor*********************************************/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#include "./lib/debug.h"
#else
#define debug(...) 42
#endif
/*********************************************Definition*************************************************/
#define endl '\n'
#define F(type, i, s, n, step) for (type i = s; (step) > 0 ? i < (n) : i > (n); i += (step))
#define FN(type, i, s, n, step) for (type i = s; (step) > 0 ? i <= (n) : i >= (n); i += (step))
#define pb push_back
// #define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef pair<char, int> pci;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
/******************************************Global Variables**********************************************/
const ll MAXM = 1e5;
const ll MAXV = 1e6;
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};
int mod = 1e9 + 7;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double EPS = 1e-9;
double PI = acos(-1);
vl factors[MAXM + 5];
/*********************************************Utility Functions******************************************/
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

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

vi coins;
int dp[MAXV + 5];
int total_sum;
// return me whether the sum can be achived or not
int rec(int sum)
{
    if (sum < 0)
        return 1e9;
    if (sum == 0)
    {
        return 0;
    }
    if (dp[sum] != -1)
        return dp[sum];
    int ans = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        ans = min(ans, 1 + rec(sum - coins[i]));
    }
    return dp[sum] = ans;
}
/*********************************************Main Function***********************************************/
void solve()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n >> total_sum;
    coins.resize(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    int ans = INT_MAX;
    if (rec(total_sum) <= 1e6)
    {
        cout << rec(total_sum);
    }
    else
        cout << -1;
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
// Checksum: af6a49cfe477d7b7dd65152a9c89f7830b09de2f883145c12b85390f553c1526
