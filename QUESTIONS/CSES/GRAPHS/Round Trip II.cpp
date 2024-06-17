// Date: 17-06-2024
// Start Time: 15:54:55
// End Time  : 16:20:35
// Time Taken: 25 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://cses.fi/problemset/task/1678
// Rating: Medium
// Description: Print the cycle in a directed graph
// Solved: No
// Learning: Using stack to keep track of nodes in my path and detect cycle

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

stack<int> r;
vi vis;
vi in_stack;
bool dfs(int node, vvi &g)
{
    vis[node] = 1;
    r.push(node);
    in_stack[node] = 1;
    for (auto nn : g[node])
    {
        if (!vis[nn])
        {
            if (dfs(nn, g))
                return true;
        }
        // now if the node is visited or cycle was not detected along the neighbour nn
        if (in_stack[nn])
        {
            // the node in the stack
            // i push the curr node again because i want a cycle to print
            r.push(nn);
            return true;
        }
    }
    r.pop();
    in_stack[node] = 0;
    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vis.clear();
    vis.resize(n);
    in_stack.clear();
    in_stack.resize(n);
    vvi g(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[--a].pb(--b);
    }
    // i have the adj list
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, g))
            {
                // store the elements of the stack in a vector then reverse it and print it
                vi ans;
                int last = r.top();
                r.pop();
                ans.pb(last);
                while (r.top() != last)
                {
                    ans.pb(r.top());
                    r.pop();
                }
                ans.pb(r.top());
                reverse(ans.begin(), ans.end());
                cout << ans.size() << endl;
                for (int i = 0; i < ans.size(); i++)
                {
                    cout << ans[i] + 1 << " ";
                }
                return;
            }
        }
    }
    cout << "IMPOSSIBLE";
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