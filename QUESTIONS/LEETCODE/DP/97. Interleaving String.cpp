// Date: 25-06-2024
// Start Time: 09:11:27
// End Time  : 09:35:35
// Time Taken: 24 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://leetcode.com/problems/interleaving-string/description/
// Rating: Medium Easy
// Description: find whether a string can be obtained by interleaving 2 strings but with a condition
// Solved: Yes
// Learning: practice on state formation IMPORTANT

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

int a, b, c;
int n = 0, m = 0;
string res;
int dp[101][101][3];
bool rec(int i, int j, int p, string s1, string s2, string s3)
{
    if (i == a && j == b)
    {
        if (abs(n - m) <= 1)
        {
            cout << res << " ";
            return true;
        }
        return false;
    }
    if (dp[i][j][p] != -1)
        return dp[i][j][p];
    bool ans = false;
    if (i < a)
    {
        // i can take the ith + 1element of s1
        if (s1[i] == s3[i + j])
        {
            if (p != 0)
                m++;
            res.push_back(s1[i]);
            ans |= rec(i + 1, j, 0, s1, s2, s3);
            res.pop_back();
            if (p != 0)
                m--;
        }
    }
    if (j < b)
    {
        if (s2[j] == s3[i + j])
        {
            if (p != 1)
                n++;
            res.push_back(s2[j]);
            ans |= rec(i, j + 1, 1, s1, s2, s3);
            res.pop_back();
            if (p != 1)
                n--;
        }
    }
    cout << res << " " << i << " " << j << " " << p << endl;
    // debug(n, m);
    return dp[i][j][p] = ans;
}

bool isInterleave(string s1, string s2, string s3)
{
    memset(dp, -1, sizeof(dp));
    a = s1.length();
    b = s2.length();
    c = s3.length();
    if (a + b != c)
        return false;
    return rec(0, 0, 2, s1, s2, s3);
}

void solve()
{
    string x, y, z;
    cin >> x >> y >> z;
    cout << isInterleave(x, y, z);
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