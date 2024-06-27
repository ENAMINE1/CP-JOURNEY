// Date: 27-06-2024
// Start Time: 22:38:08
// End Time  : 22:47:00
// Time Taken: 9 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://atcoder.jp/contests/arc139/tasks/arc139_a
// Rating: Easy
// Description: find the next number divisible than a power of 2 but not divisible by the next power of 2
// Solved: Yes
// Learning: whenever you are told about trailing zeros you should think about that the number is divisible by 2 raised to the poswer of # of trailing zeros. also got to know about a very trivial case that is when you are required to find the next number divisible by x greater than y then it is simply ((y/x) + 1) * x and now if i add another constraint that the number should not be divisible by say z*x then simiply check whether the number say p, p%(x*z)!= 0

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
    vector<int> t(n);
    rep(i, n)
            cin >>
        t[i];
    debug(t[0]);
    long long curr = 1LL << t[0];
    for (int i = 1; i < n; i++)
    {
        long long temp = (curr / (1LL << t[i]) + 1) * (1LL << t[i]);
        if (temp % (1LL << (t[i] + 1)) == 0)
            temp += (1LL << t[i]);
        curr = temp;
    }
    cout << curr << endl;
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