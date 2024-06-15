// Date: 15-06-2024
// Start Time: 15:43:34
// End Time  : 15:47:46
// Time Taken: 4 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://leetcode.com/problems/minimum-height-trees/description/
// Rating: Medium
// Description: Find the node which kept as src in the tree result in min height tree
// Solved: Yes
// Learning: Run  bfs form every node and find the height of the tree and report the ones which result in the minimum height trees

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

vector<int> dist;

int bfs(int src, vector<vector<int>> &g, int n)
{
    dist.clear();
    dist.resize(n + 1, 1e9);
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto nn : g[node])
        {
            if (dist[nn] > dist[node] + 1)
            {
                dist[nn] = dist[node] + 1;
                q.push(nn);
            }
        }
    }
    int height = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (auto nn : g[i])
        {
            height = max(height, dist[nn]);
        }
    }
    return height;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        // g[v[i][0]].push_back(v[i][1]);
    }
    vector<int> min_height_nodes;
    int min_height = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int src = i;
        int curr_height = bfs(src, g, n);
        cout << curr_height << " " << i << endl;
        if (curr_height < min_height)
        {
            min_height = curr_height;
            min_height_nodes.clear();
            min_height_nodes.push_back(src);
        }
        else if (curr_height == min_height)
        {
            min_height_nodes.push_back(src);
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
