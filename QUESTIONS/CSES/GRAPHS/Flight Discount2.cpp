// Date: 13-06-2024
// Start Time: 20:19:05
// End Time  : 20:44:18
// Time Taken: 25 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://cses.fi/problemset/task/1195
// Rating: Hard
// Description: Find the shortest cost path form src to dest
// Solved: No
// Learning: here i had to use dijkstra's algorithm twice to find the smallest distance to all the nodes form node 1 and node n and then for each edge in the graph is there was a path from 1 to n using that edge i reduced the cost of the edge to half and then calculated the path cost and found the min of all the cost. ANOTHER IMPORTANT THING TO NOTE WAS TO PROCESS A NODE ONLY ONCE OTHERWISE I HADE TLE BECAUSE I HAVE ALREADY FOUND OUT THE MIN DISTACNCE TO THE NODE ---- AND THERE ARE TWO METHODS TO DO IT === LOOK CODE 

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
vector<vpii> neighbours, reverse_neighbours;
vi vis;
// returns the min distance form src to all the nodes in the graph
vector<ll> dij(int src, vector<vpii> graph)
{
    vis.clear();
    vis.resize(graph.size(), 0);
    vector<ll> ans(graph.size(), INT64_MAX);
    ans[src] = 0;
    priority_queue<pair<ll, int>> q;
    q.push({0, src});
    while (!q.empty())
    {
        auto node = q.top();
        q.pop();
        // if(-node.first != ans[node.second]){
        //     continue;
        // }
        if (vis[node.second])
            continue;
        vis[node.second] = 1;
        for (auto nn : graph[node.second])
        {
            if (ans[nn.first] > ans[node.second] + nn.second)
            {
                ans[nn.first] = ans[node.second] + nn.second;
                q.push({-ans[nn.first], nn.first});
            }
        }
    }
    return ans;
}

void solve()
{
    cin >> n >> m;
    neighbours.clear();
    reverse_neighbours.clear();
    neighbours.resize(n);
    reverse_neighbours.resize(n);
    for (int i = 0; i < m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        neighbours[--from].pb({--to, cost});
        reverse_neighbours[to].pb({from, cost});
    }

    // use dijkstra's algo to find the min distance to all nodes from 1 and from n th node
    vector<ll> start_cost = dij(0, neighbours);
    vector<ll> end_cost = dij(n - 1, reverse_neighbours);
    ll ans = INT64_MAX;
    for (int i = 0; i < n; i++)
    {
        for (auto nn : neighbours[i])
        {
            if (start_cost[i] == INT64_MAX || end_cost[nn.first] == INT64_MAX)
                continue;
            ans = min(ans, start_cost[i] + nn.second / 2 + end_cost[nn.first]);
        }
    }
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