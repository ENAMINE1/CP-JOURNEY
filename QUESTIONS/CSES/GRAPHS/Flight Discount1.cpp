// Date: 13-06-2024
// Start Time: 15:20:40
// End Time  : 19:08:07
// Time Taken: 227 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://cses.fi/problemset/task/1195
// Rating: Hard
// Description: Find the path from 1 to n such that you can reduce the cost of an edge in the path by half
// Solved: Yes
// Learning: How to use dfs and maintain the longest or most expensive edge in the path

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

int n, m;
vector<vpii> g;
vi vis;
vi path;
void dfs(int node, int pp, ll path_len, int max_dist, ll &ans)
{
    vis[node] = 1;
    path.pb(node);
    int temp = max_dist;
    debug(temp);
    if (node == n - 1)
    {
        // for (int i = 0; i < path.size(); i++)
        // {
        //     cout << path[i] + 1 << "->";
        // }
        // cout << endl;
        // cout << path_len << " " << max_dist << "->" << path_len - max_dist + max_dist / 2 << endl;
        ans = min(ans, path_len - max_dist + max_dist / 2);
    }
    for (auto nn : g[node])
    {
        if (!vis[nn.first])
        {
            max_dist = max(max_dist, nn.second);
            dfs(nn.first, node, path_len + nn.second, max_dist, ans);
            max_dist = temp;
        }
    }
    // for (int i = 0; i < path.size(); i++)
    // {
    //     cout << path[i] + 1 << "->";
    // }
    // cout << endl;
    path.pop_back();
    vis[node] = 0;
}

void solve()
{
    cin >> n >> m;
    g.clear();
    vis.clear();
    vis.resize(n);
    g.resize(n);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].pb({b, c});
    }
    // we simply run a dfs and find all paths from 1 to n
    ll ans = LLONG_MAX;
    dfs(0, -1, 0, 0, ans);
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