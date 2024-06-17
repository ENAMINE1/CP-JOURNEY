// Date: 17-06-2024
// Start Time: 18:00:18
// End Time  : 19:36:24
// Time Taken: 86 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://cses.fi/problemset/task/1680/
// Rating: Hard
// Description: Find the topological ordering of a DAG and print the longest path from 1 to n
// Solved: Yes
// Learning: i had to find the longest path from 1 to n, instead what i was doing was to find the longest path and then longest path to n form any node.

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
vi ans;
void khan(vi &indegree, queue<int> &q, vvi &g)
{
    while (!q.empty())
    {
        auto node = q.front();
        ans.pb(node);
        q.pop();
        for (auto nn : g[node])
        {
            indegree[nn]--;
            if (indegree[nn] == 0)
                q.push(nn);
        }
    }
    if (ans.size() != n)
    {
        cout << "IMPOSSIBLE";
        return;
    }
    // the topo array is ans now
    vi dp(n, 1);
    int start_idx = -1;
    vi child(n, -1);
    vi does_this_node_take_me_to_last_node(n);
    does_this_node_take_me_to_last_node[n - 1] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (auto nn : g[ans[i]])
        {
            if (does_this_node_take_me_to_last_node[nn] == 1)
            {
                does_this_node_take_me_to_last_node[ans[i]] = 1;
                dp[ans[i]] = max(dp[ans[i]], 1 + dp[nn]);
                if (dp[ans[i]] == 1 + dp[nn])
                    child[ans[i]] = nn;
            }
        }
    }
    if (does_this_node_take_me_to_last_node[0] == 0)
    {
        cout << "IMPOSSIBLE";
        return;
    }
    cout << dp[0] << endl;
    start_idx = 0;
    while (start_idx != -1)
    {
        cout << start_idx + 1 << " ";
        start_idx = child[start_idx];
    }
}

void solve()
{
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
    // simply do the topolgical sort
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    // khans algorithm to do bfs
    khan(indegree, q, g);
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