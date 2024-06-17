// Date: 17-06-2024
// Start Time: 22:22:27
// End Time  : 22:48:24
// Time Taken: 25 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://cses.fi/problemset/task/1681
// Rating: Easy
// Description: Simply count the number of paths from src to dst in a DAG
// Solved: Yes
// Learning: Used dfs for topological sorting and used the result from subproblem to calculte the ans

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

vi vis;
vi takes_me_to_last; // number of paths to reach node n form ith node
void dfs(int node, vvi &g)
{
    vis[node] = 1;
    for (auto nn : g[node])
    {
        if (!vis[nn])
        {
            dfs(nn, g);
        }
        takes_me_to_last[node] = (1LL * takes_me_to_last[node] + takes_me_to_last[nn]) % mod;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vis.assign(n, 0);
    takes_me_to_last.assign(n, 0);
    takes_me_to_last[n - 1] = 1;
    vvi g(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[--a].pb(--b);
    }
    // run a dfs
    dfs(0, g);
    cout << takes_me_to_last[0];
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