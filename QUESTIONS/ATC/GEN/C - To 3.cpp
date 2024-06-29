// Date: 29-06-2024
// Start Time: 23:47:48
// End Time  : 23:58:39
// Time Taken: 10 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://atcoder.jp/contests/abc182/tasks/abc182_c
// Rating: 300
// Description: find the number of digits to remove to make the number divisible by 3
// Solved: No
// Learning: learned how to think in the case of remianders and count of digits with a specific remainder

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
    long long n;
    cin >> n;
    long long temp = n;
    long long sum = 0;
    int cnt1 = 0, cnt2 = 0;
    vector<int> digits;
    while (temp)
    {
        int d = temp % 10;
        sum += d;
        if (d % 3 == 1)
            cnt1++;
        if (d % 3 == 2)
            cnt2++;
        digits.push_back(d);
        temp /= 10;
    }
    int len = digits.size();
    if (sum % 3 == 0)
    {
        cout << 0;
        return;
    }
    else if (len == 1)
        cout << -1;
    else
    {
        if (sum % 3 == 1)
        {
            // if single digit num
            if (cnt1 > 0)
                cout << 1;
            else
            {
                // need to remove two numbers whose remainder with 3 is 2
                if (len == 2)
                    cout << -1;
                else
                {
                    if (cnt2 > 1)
                        cout << 2;
                    else
                        cout << -1;
                }
            }
        }
        else
        {
            if (cnt2 > 0)
                cout << 1;
            else
            {
                if (len == 2)
                    cout << -1;
                else
                {
                    if (cnt1 > 1)
                        cout << 2;
                    else
                        cout << -1;
                }
            }
        }
    }
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