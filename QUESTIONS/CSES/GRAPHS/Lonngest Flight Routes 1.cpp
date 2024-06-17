// Date: 17-06-2024
// Start Time: 19:39:38
// End Time  : 21:47:10
// Time Taken: 127 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://cses.fi/problemset/task/1680
// Rating: Medium
// Description: Find the longest path from src to dst
// Solved: Yes
// Learning: You can use dijkstras algorithm for negative edge if there are only negative edges and no cycles as distacne is a monotonically decreasing function with more edges added to the path. So the learning is that dijkstras can be applied in case of monotonic distaces and no cycle present in case of negative cycle.

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

void dijkstra(vector<vpii> &g)
{
    int n = g.size();
    vi dist(n, 1e9);
    vi parent(n);
    parent[0] = -1;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push({0, 0});
    dist[0] = 0;
    while (!q.empty())
    {
        auto [dd, node] = q.top();
        q.pop();
        if (dist[node] < dd)
            continue;
        for (auto [nn, nn_cost] : g[node])
        {
            if (dist[nn] > dist[node] + nn_cost)
            {
                dist[nn] = dist[node] + nn_cost;
                q.push({dist[nn], nn});
                parent[nn] = node;
            }
        }
    }
    if (dist[n - 1] == 1e9)
    {
        cout << "IMPOSSIBLE";
        return;
    }
    cout << 1 + -dist[n - 1] << endl;
    int node = n - 1;
    vi ans;
    while (node != -1)
    {
        // cout << node + 1 << " ";
        ans.pb(node);
        node = parent[node];
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] + 1 << " ";
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vpii> g(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[--a].pb({--b, -1});
    }
    dijkstra(g);
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