// Date: 17-06-2024
// Start Time: 22:54:40
// End Time  : 23:18:27
// Time Taken: 23 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://cses.fi/problemset/task/1681
// Rating: Easy
// Description: Simply count the number of paths from src to dst in a DAG
// Solved: Yes
// Learning: How to use Topological sort to remove unnecessary node from the graph which will lie to the left of the desired node as the root of the DAG using topological sorting twice

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

void khans(vi &indegree, vvi &g)
{
    int n = g.size();
    queue<int> q;
    // first topological sort to remove nodes which are to the left of node 0
    for (int i = 1; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto nn : g[node])
        {
            if (nn != 0)
            {
                indegree[nn]--;
                if (indegree[nn] == 0)
                    q.push(nn);
            }
        }
    }
    // now all the nodes which were suppose to be on the left of node 0 in topological sort have indegree 0
    q.push(0);
    // cnt keeps track of the number of paths to last node
    vi cnt(n);
    cnt[0] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto nn : g[node])
        {
            debug(node, nn);
            indegree[nn]--;
            cnt[nn] = (cnt[nn] + cnt[node]) % mod;
            if (indegree[nn] == 0)
                q.push(nn);
        }
    }
    cout << cnt[n - 1];
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vvi g(n);
    vi indegree(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[--a].pb(--b);
        indegree[b]++;
    }
    khans(indegree, g);
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