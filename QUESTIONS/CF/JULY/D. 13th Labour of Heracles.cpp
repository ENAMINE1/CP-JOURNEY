// Date: 07-07-2024
// Start Time: 19:05:44
// End Time  : 19:28:48
// Time Taken: 23 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/problemset/problem/1466/D
// Rating: 1500
// Description: find the max value of k colouring of the graph where each verted has a value
// Solved: No
// Learning: i had to think form the base case when we use only one colour and then build up the solution form that [IMPORTANT]

/****************************************************Pre Processor***************************************************/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#include "./lib/debug.h"
#include "./lib/print.h"
#else
#define debug(...) 42
#endif
#define endl '\n'
/***************************************************Main Function**************************************************/

/*
    first i thought that it will be difficult to assign edges a random color between 1 and n-1 and then to add the contribution of each node in a connected component of a color

    the main thing to ovserve was that it did not matter which edges we count in what component of a colour but what matters is how many times is node counted in different subgraphs since it is the vertices which have weights assigned to them.

    the strategy is to try to get the node with the heighest value and try changing the colour of one of the edges from the node if it has more than one edge. what this will do is that now we will have two components with the same node in each of them but different coloured components (basically you can imagine that we detached one of its subtrees and added the same node to this subtree) and hence the value of the k colouring will increase by the value of the max node.

    we will do this till all the edges are coloured differently and then we will move on to the 2nd largest node and repeat the same, and since there are only n-1 edges and k varies form 1 to n-1 we will colour all edges differntly when k == n-1, because it is best to use all of the k colours as it breaks the graph at k different places.
*/
void solve()
{
    int n;
    cin >> n;
    // v[i] contains the weight of each vertex
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // keeping track of degree of each node
    vector<int> degree(n);
    for (int i = 0; i < n - 1; i++)
    {
        int from, to;
        cin >> from >> to;
        from--;
        to--;
        degree[from]++;
        degree[to]++;
    }
    vector<int> x;
    // initaily when k = 1; then i colour all the edges with the same colour
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        // for each node
        for (int j = 1; j < degree[i]; j++)
        {
            // for each neighbour or child of the node
            x.push_back(v[i]);
        }
        ans += v[i];
    }
    sort(x.begin(), x.end(), greater<int>());
    for (auto node : x)
    {
        cout << ans << " ";
        ans += node;
    }
    cout << ans << endl;
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