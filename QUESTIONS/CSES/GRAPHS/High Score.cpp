// Date: 13-06-2024
// Start Time: 21:09:59
// End Time  : 21:36:32
// Time Taken: 26 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://cses.fi/problemset/task/1673
// Rating: Hard
// Description: Find the longest path to dest from src and if the longest path is absurly high then report -1
// Solved: No
// Learning: If there is a positive cycle in the graph then it dosent mean that the cost from src to dst will be very high but if the dest is reachable form any of the nodes in the cycle then to make my score max i will for sure go through the cycle to reach dst

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
vector<vpii> neighbours, reverse_neighbours;

vi vis;
void dfs(int node, vector<vpii> &graph)
{
    vis[node] = 1;
    for (auto [nn, cost] : graph[node])
    {
        if (!vis[nn])
            dfs(nn, graph);
    }
}

void solve()
{
    // reverse the edges to find the shortest path and negative cycle
    int n, m;
    cin >> n >> m;
    vis.clear();
    vis.resize(n, 0);
    neighbours.clear();
    neighbours.resize(n);
    reverse_neighbours.clear();
    reverse_neighbours.resize(n);
    for (int i = 0; i < m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        neighbours[--from].pb({--to, -cost});
        reverse_neighbours[to].pb({from, -cost});
    }
    // run bellman ford
    vector<ll> dist(n, 1e18);
    dist[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (auto nn : neighbours[j])
            {
                if (dist[j] < 1e18)
                    if (dist[nn.first] > dist[j] + nn.second)
                        dist[nn.first] = dist[j] + nn.second;
            }
        }
    }
    // check if negative cycle exists or not
    vi neg;
    for (int j = 0; j < n; j++)
    {
        for (auto nn : neighbours[j])
        {
            if (dist[j] != 1e18)
                if (dist[nn.first] > dist[j] + nn.second)
                    neg.pb(j);
        }
    }
    for (int i = 0; i < neg.size(); i++)
    {
        debug(neg[i]);
    }
    // now if i can reach any of the node form last node then report - 1;
    if (neg.size() > 0)
    {
        dfs(n - 1, reverse_neighbours);
        for (int i = 0; i < neg.size(); i++)
        {
            if (vis[neg[i]] == 1)
            {
                cout << -1;
                return;
            }
        }
    }
    cout << -dist[n - 1];
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