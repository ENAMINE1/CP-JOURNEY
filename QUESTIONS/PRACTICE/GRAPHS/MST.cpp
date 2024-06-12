// Date: 12-06-2024
// Start Time: 11:38:15
// End Time  : 12:37:14
// Time Taken: 298 minutes
// Author: Shashwat Kumar
// QUESTION LINK:
// Rating:
// Description:
// Solved:
// Learning:

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

struct UnionFind
{
    int n, set_size, *parent, *rank;
    UnionFind() {}
    UnionFind(int a)
    {
        n = set_size = a;
        parent = new int[n + 1];
        rank = new int[n + 1];
        reset();
    }
    // path compression
    int find(int x)
    {
        if (x != parent[x])
            return parent[x] = find(parent[x]);
        return x;
    }
    // rank compression
    void merge(int x, int y)
    {
        if (parent[x] != parent[y])
        {
            int xroot = find(x);
            int yroot = find(y);
            if (xroot != yroot)
            {
                if (rank[xroot] >= rank[yroot])
                {
                    parent[yroot] = xroot;
                    rank[yroot] += rank[xroot];
                }
                else
                {
                    parent[xroot] = yroot;
                    rank[xroot] += rank[yroot];
                }
                set_size -= 1;
            }
        }
    }
    void reset()
    {
        set_size = n;
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int size()
    {
        return set_size;
    }
    void print()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i << " -> " << parent[i] << endl;
        }
    }
};
vector<vpii> g(MAXM + 5);
void solve()
{
    int n, m;
    cin >> n >> m;

    UnionFind u(n);
    // for kruskals algorithm we dont even need the adj list we just need the edge list
    vector<pair<int, pii>> edgelist;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // g[a].pb({b, c});
        // g[b].pb({a, c});
        edgelist.pb({c, {a, b}});
    }
    sort(edgelist.begin(), edgelist.end());
    ll mst_cost = 0;
    int cnt = 0;
    for (auto it : edgelist)
    {
        int x = it.second.first;
        int y = it.second.second;
        if (u.find(x) != u.find(y))
        {
            // they are not in same component
            cnt++;
            mst_cost += it.first;
            u.merge(x, y);
        }
    }

    // now the catch is that MST only exist for a connected graph
    if (cnt != n - 1)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << mst_cost << endl;
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