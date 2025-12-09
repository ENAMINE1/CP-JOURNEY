// Date: 01-07-2024
// Start Time: 13:15:34
// End Time  : 14:42:41
// Time Taken: 87 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/contest/1857/problem/G
// Rating: 2000
// Description: Find the number of graphs possible with a given MST and max edge weight
// Solved: No
// Learning: How to use union find with template and there is no need of merge if you use union find on a tree and you may need to tweak bin_pow according to your needs

/****************************************************Pre Processor***************************************************/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#include "./lib/print.h"
#include "./lib/debug.h"
#else
#define debug(...) 42
#endif

/***************************************************Main Function**************************************************/
#define int long long
const int N = 2 * 1e5 + 5;
const int mod = 998244353;
int parent[N], sz[N];

int find(int x)
{
    if (x != parent[x])
        return parent[x] = find(parent[x]);
    return x;
}

int bin_pow(int a, int b)
{
    int ans = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            ans = (1LL * ans * a) % mod;
        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return ans;
}
void solve()
{
    int n, s;
    cin >> n >> s;
    fill(sz, sz + n + 1, 1);
    iota(parent, parent + n + 1, 0);
    vector<pair<int, pair<int, int>>> edgeList;
    for (int i = 0; i < n - 1; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        edgeList.push_back({cost, {--from, --to}});
    }
    sort(edgeList.begin(), edgeList.end());
    long long ans = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int x = edgeList[i].second.first;
        int y = edgeList[i].second.second;
        x = find(x);
        y = find(y);
        ans = (ans * bin_pow(s - edgeList[i].first + 1, 1LL * sz[x] * sz[y] - 1)) % mod;
        parent[y] = x;
        sz[x] += sz[y];
    }
    cout << ans << endl;
}

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

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