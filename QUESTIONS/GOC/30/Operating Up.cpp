// Date: 18-06-2024
// Start Time: 10:00:48
// End Time  : 10:25:00
// Time Taken: 24 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://www.hackerrank.com/contests/goc-cdc-series-30/challenges/matrix-up/problem
// Rating: Medium
// Description: Find the minimum number of changes required to get Y in the nxn matrix
// Solved: No
// Learning: How to elegantly write code for brute force solution

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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repi(i, a, n) for (ll i = a; i < n; i++)
#define repii(i, a, n, b) for (ll i = a; i < n; i += b)
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
    int n;
    cin >> n;
    // these two vectors keep track fo number of elements in the matrix of each type in Y and not Y
    int y[3] = {0, 0, 0};
    int ny[3] = {0, 0, 0};
    rep(i, n)
        rep(j, n)
    {
        ll k;
        cin >> k;
        // debug(k);
        if ((i == j && i <= n / 2) || (i == n - j - 1 && i <= n / 2) || (i >= n / 2 && j == n / 2))
            y[k]++;
        else
            ny[k]++;
    }

    int ty = 3 * (n - 1) / 2 + 1;
    int ans = n * n;
    ans = min(ans, ty - y[0] + min(n * n - ty - ny[1], n * n - ty - ny[2]));
    ans = min(ans, ty - y[1] + min(n * n - ty - ny[0], n * n - ty - ny[2]));
    ans = min(ans, ty - y[2] + min(n * n - ty - ny[0], n * n - ty - ny[1]));
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

/*
Sanghi loves the letter . He gives you a  matrix ( is odd) where each entry is either  or . He asks you to make a letter  in the matrix by changing any element of matrix any number of times. A matrix is said to contain letter  if:

All numbers on the diagonals starting from upper left and upper right corners down to the centre of the matrix as well as the numbers stretching down vertically from the centre of the matrix are equal. All these are the numbers making .
All other numbers that are not part of  should be equal and different from the numbers that make
Find the minimum number of operations that are needed to make the matrix contain letter  and make Sanghi happy.

Input Format

First line contains a single integer , denoting the number of test cases.

First line of each test case contains a single integer , denoting the dimension of the matrix.

Next  lines of each test case each contain  integers, denoting the elements of the matrix.

Constraints


   is odd.


Sum of  over all test cases doesn't exceed

Output Format

For each test case, output in a single line an integer, denoting the minimum number of operations required.

Sample Input 0

2
3
1 0 1
0 1 0
0 0 0
5
0 0 0 0 0
1 1 1 1 1
2 2 2 2 2
0 0 0 0 0
0 0 1 0 0
Sample Output 0

1
11
*/