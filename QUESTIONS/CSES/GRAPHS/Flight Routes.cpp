// Date: 14-06-2024
// Start Time: 15:12:06
// End Time  : 21:04:21
// Time Taken: 352 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://cses.fi/problemset/task/1196
// Rating: Hard
// Description: Find the k shortest path to a node
// Solved: No
// Learning: keeping a priority queue for each node to keep track of the k shortest path form src to it, what i was doing wrong was to find the shortest distance to all interediate nodes and use them to find the k shortest path to the dst node but in that case i missed other possibilities of longer distances to intermediate nodes

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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vpii> g(n);
    for (int i = 0; i < m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        g[--from].pb({--to, cost});
    }
    // the main thing to do is to find the k shortest path to all the nodes and use them to find the k shortest path to all other nodes
    // keep track of best k paths to node i
    priority_queue<ll> best_k_dist[n];
    priority_queue<pair<ll, int>> q;
    best_k_dist[0].push(0);
    q.push({0, 0});
    while (!q.empty())
    {
        auto [node_cost, node] = q.top();
        q.pop();
        // to find the k shortest path to a dst node we try to find at most k shortes path to all other nodes and use these intermediate path to find out the k shortest path to the dst node
        if (node == 0)
        {
            debug(-node_cost, best_k_dist[node].top());
        }
        // this part is important to look because it may appear that we are not considering more than one path to node but actually if node is the neighbour of any other node then its entry is added to best_k_dist[node] priority queue
        if (-node_cost > best_k_dist[node].top())
            continue;
        for (auto [nn, edge_cost] : g[node])
        {
            // if the distance to nn is smaller than the
            if (best_k_dist[nn].size() < k)
            {
                best_k_dist[nn].push(-node_cost + edge_cost);
                q.push({-(-node_cost + edge_cost), nn});
            }
            else
            {
                if (-node_cost + edge_cost < best_k_dist[nn].top())
                {
                    best_k_dist[nn].pop();
                    best_k_dist[nn].push(-node_cost + edge_cost);
                    q.push({-(-node_cost + edge_cost), nn});
                }
            }
        }
    }
    vector<ll> ans;
    while (!best_k_dist[n - 1].empty())
    {
        ans.pb(best_k_dist[n - 1].top());
        best_k_dist[n - 1].pop();
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
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