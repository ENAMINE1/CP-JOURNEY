// Date: 16-06-2024
// Start Time: 10:58:32
// End Time  : 12:50:27
// Time Taken: 111 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/1900/problem/C
// Rating: 1300
// Description: Find the number of changes you need to make to the nodes to reach any leaf node in minimum changes
// Solved: Yes
// Learning: How by just changing the edge weights you can make the problem easier, if the node had a lable of 'L' then the edgeweight between the left child and the parent would be 0 and similarly for lable 'R' and for all other edges edge weight will be 1

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

// vvi tree;
// string s;
// vi dist;
// int ans = INT_MAX;

// current node, parent, distance, changes till now
// int dfs(int node, int pp, int d)
// {
//     dist[node] = d;
//     debug(node, tree[node][0], tree[node][1]);
//     if (tree[node][0] == -1 && tree[node][1] == -1)
//     {
//         // i have reached the leaf node
//         return 0;
//     }
//     else
//     {
//         int m = INT_MAX;
//         int l = INT_MAX, r = INT_MAX;
//         if (tree[node][0] != -1)
//             l = dfs(tree[node][0], node, d + 1);
//         if (tree[node][1] != -1)
//             r = dfs(tree[node][1], node, d + 1);
//         m = min(l, r);
//         if (s[node] == 'U')
//         {
//             return 1 + m;
//         }
//         else if (s[node] == 'L')
//         {
//             if (r < l)
//                 return 1 + r;
//             else
//                 return l;
//         }
//         else
//         {
//             if (l < r)
//                 return 1 + l;
//             else
//                 return r;
//         }
//     }
// }

vi dist;
vector<vpii> tree;
string s;
int dfs1(int node, int dd)
{
    debug(node);
    if (tree[node][0].first == -1 && tree[node][1].first == -1)
        return dd;
    dist[node] == dd;
    int ans = INT_MAX;
    for (auto [nn, cost] : tree[node])
    {
        if (nn != -1)
            ans = min(ans, dfs1(nn, dd + cost));
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n >> s;
    tree.clear();
    tree.resize(n);
    dist.clear();
    dist.resize(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (s[i] == 'L')
        {
            tree[i].pb({--a, 0});
            tree[i].pb({--b, 1});
        }
        else if (s[i] == 'R')
        {
            tree[i].pb({--a, 1});
            tree[i].pb({--b, 0});
        }
        else
        {
            tree[i].pb({--a, 1});
            tree[i].pb({--b, 1});
        }
    }
    // cout << dfs(0, -1, 0) << endl;
    cout << dfs1(0, 0) << endl;
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