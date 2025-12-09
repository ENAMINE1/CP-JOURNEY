// Date: 16-06-2024
// Start Time: 21:35:35
// End Time  : 21:49:03
// Time Taken: 13 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/problemset/problem/1857/D
// Rating: Medium
// Description: Find the number and the nodes which are connected to all the other nodes
// Solved: No
// Learning: there is an edge between 2 nodes u and v if a[u] - b[u] <= a[v] - b[v] so basically find the count of elements which have this metric as the maximum and return them

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
    vi a(n), b(n), idx(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        idx[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        b[i] = a[i] - b[i];
    }
    sort(idx.begin(), idx.end(), [&b](int x, int y) -> bool
         { return b[x] > b[y]; });
    // now i have the index sorted in the descending order
    for (int i = 0; i < n; i++)
    {
        // cout << idx[i] << " " << b[idx[i]] << endl;
        debug(idx[i], b[idx[i]]);
    }
    vi ans;
    int i = 0;
    while (i < n && b[idx[i]] == b[idx[0]])
    {
        ans.pb(idx[i]);
        i++;
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
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