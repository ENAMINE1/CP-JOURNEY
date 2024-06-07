// Date: 07-06-2024
// Start Time: 15:51:58
// End Time  : 17:22:40
// Time Taken: 90 minutes
// Author: Shashwat Kumar
// QUESTION LINK: Algozenith
// Rating: Hard
// Description: remove components of size >= k till you cant find anymore and apply gravity
// Solved: Yes
// Learning: How to implement what you think

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

#define F first
#define S second
vvi table;
int n, K;
int comp[1005][15];
int comp_size[1001]; // tells you the size of a comp with comp id as the idx and multiple components with same no in them can have differenct comp sizes and we number each componet with a different number and at max there can be N*10 components
// vpii dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
// replace the numbers to correct places
void gravity()
{
    for (int j = 0; j < 10; j++)
    {
        int top = n - 1, bottom = n - 1;
        while (top >= 0)
        {
            while (top >= 0 && table[top][j] == 0)
                top--;
            if (top >= 0)
                table[bottom--][j] = table[top--][j];
        }
        while (bottom >= 0)
            table[bottom--][j] = 0;
    }
}

void dfs(int x, int y, int num, int c)
{
    // first check whether i can go to cell [x][y] or not and if the cell is visited or not and whether it contains the same integers as me
    if (x < 0 || x >= n || y < 0 || y > 9 || comp[x][y] != 0 || table[x][y] != num)
        return;
    comp[x][y] = c;
    comp_size[c]++;
    // go in all 4 directions
    for (int i = 0; i < 4; i++)
    {
        dfs(x + dir[i].F, y + dir[i].S, num, c);
    }
}
// iterate over all the cells and find all the cells with the same value as own and replace them with 0 and call gravity and return false when no more adjustments can be done
bool iterate()
{
    // before runnig the dfs to number the components just empty the comp array
    // comp.resize(n + 1, vi(10, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            comp[i][j] = 0;
        }
    }
    // run the dfs from all the cells
    int component_num = 0;
    // adding extra 0 in the begining of the array to make the index 1 based
    // gravity();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 10; j++)
            if (table[i][j] != 0 && !comp[i][j])
            {
                // do the dfs
                component_num++;
                comp_size[component_num] = 0;
                dfs(i, j, table[i][j], component_num);
            }
    // after every iteration check whether there is any component with size >= k
    bool ret_val = false;
    for (int k = 0; k < component_num; k++)
    {
        if (comp_size[k] >= K)
        {
            // remove those numbers from the table
            for (int i = 0; i < n; i++)
                for (int j = 0; j < 10; j++)
                    if (comp[i][j] == k)
                        table[i][j] = 0;
            ret_val = true;
        }
    }
    gravity();

    while (component_num)
        comp_size[component_num--] = 0;
    return ret_val;
}

void solve()
{
    cin >> n >> K;
    table.resize(n, vi(10, 0));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
            table[i][j] = s[j] - '0';
    }
    // intput taken
    while (iterate())
        ;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
            cout << table[i][j];
        cout << endl;
    }
    cout << endl;
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

/*
TEST CASE
6 3
0000000000
0000000300
0054000300
1054502230
2211122220
1111111223

SOLUTION
0000000000
0000000000
0000000000
0000000000
1054000000
2254500000
*/