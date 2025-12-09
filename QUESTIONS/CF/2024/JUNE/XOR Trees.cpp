// Date: 16-06-2024
// Start Time: 09:55:55
// End Time  : 10:40:16
// Time Taken: 44 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/429/problem/A
// Rating: 1300
// Description: Find the number of flips required to make the current node value equal to desired node value
// Solved: No
// Learning: here flipping a node value meant all the subsequent levels' of same parity as current level nodes were also flipped which were a part of the subtree rooted at this node and hence i needed to start from the root and go towards the leaves

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

int ans = 0;

vi u, v;
vvi tree;
vi dist;
vi nodes;
// even filps -> flips done int previous even lvls
void dfs(int node, int curr_lvl, int parent, int even_flips, int odd_flips)
{
    dist[node] = curr_lvl;
    debug(node + 1, u[node], v[node], curr_lvl, even_flips, odd_flips);
    if (u[node] != v[node])
    {
        if (curr_lvl % 2 == 0)
        {
            if (even_flips % 2 == 0)
            {
                even_flips++;
                ans++;
                nodes.pb(node);
            }
        }
        else
        {
            if (odd_flips % 2 == 0)
            {
                odd_flips++;
                ans++;
                nodes.pb(node);
            }
        }
    }
    else
    {
        if (curr_lvl % 2 == 0)
        {
            if (even_flips % 2)
            {
                even_flips++;
                ans++;
                nodes.pb(node);
            }
        }
        else
        {
            if (odd_flips % 2)
            {
                odd_flips++;
                ans++;
                nodes.pb(node);
            }
        }
    }
    for (auto nn : tree[node])
    {
        if (nn != parent)
        {
            debug(even_flips, odd_flips);
            dfs(nn, curr_lvl + 1, node, even_flips, odd_flips);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    tree.resize(n);
    dist.resize(n);
    v.resize(n);
    u.resize(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[--a].push_back(--b);
        tree[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
        cin >> u[i];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    // run dfs and count the number of flips you need to make
    dfs(0, 0, -1, 0, 0);
    cout << ans << endl;
    for (int i = 0; i < nodes.size(); i++)
    {
        cout << nodes[i] + 1 << endl;
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