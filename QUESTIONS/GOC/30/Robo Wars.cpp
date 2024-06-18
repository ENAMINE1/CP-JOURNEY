// Date: 18-06-2024
// Start Time: 10:41:22
// End Time  : 11:07:38
// Time Taken: 26 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://www.hackerrank.com/contests/goc-cdc-series-30/challenges/robo-wars/problem
// Rating: Easy
// Description: Robots are kept on a line and each can move left or right; if any 2 collide then the one with smaller absolute value of strngth gets destroyed; eventually tell the robots which survive
// Solved: No
// Learning: Used stack to solve the problem, could have been solved without stack just had to think

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
    stack<int> surviving_robots;
    int n;
    cin >> n;
    rep(i, n)
    {
        int temp;
        cin >> temp;
        // if the stack is empty of if the top robots has the same sign as the current
        if (surviving_robots.empty() || 1LL * temp * surviving_robots.top() > 0 || surviving_robots.top() < 0 && temp > 0)
            surviving_robots.push(temp);
        else if (surviving_robots.top() > 0 && temp < 0)
        {
            // these two robots will collide
            while (!surviving_robots.empty() && surviving_robots.top() > 0 && surviving_robots.top() < abs(temp))
            {
                surviving_robots.pop();
            }
            if (surviving_robots.empty())
                surviving_robots.push(temp);
            else
            {
                if (surviving_robots.top() < 0)
                {
                    surviving_robots.push(temp);
                }
                else if (surviving_robots.top() > abs(temp))
                {
                    // do nothing
                }
            }
        }
    }
    vi ans;
    while (!surviving_robots.empty())
    {
        ans.pb(surviving_robots.top());
        surviving_robots.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto num : ans)
        cout << num << " ";
    cout << endl;
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
A Robo-War is being organized in KGP. There are  robots participating in the war. The  robots are placed in a line. The  robot is at position , has power  and it moves only towards left if  and moves towards right if .

When the war starts, each robot starts moving at the same speed either towards right or left according to the rule mentioned above. If the  and  robots collide, the  robot will instantly destroy  robot and continue to move in it's original direction if and only if it has more power, i.e. . The war ends when no more collisions are possible. All the surviving robots are declared victors.

Vivan wants to place a bet in the tournament in order to win some money. Help him determine the robots which will win the tournament.

Input Format

First line contains a single integer , the number of test cases.

First line of each test case contains a single integer , the number of robots.

Second line of each test case contains  integers, .

Constraints

.

.

.

Sum of n over all test cases doesn't exceed .

 are pairwise distinct.

Output Format

For each test case,

on the first line print an integer , the number of winners.
on the second line print  integers  , the value of winning robots sorted according to their final position
Sample Input 0

2
7
3 -4 6 1 -2 7 5
4
3 6 -4 -2
Sample Output 0

4
-4 6 7 5
2
3 6
Explanation 0

In the first test case, the following sequence of collisons take place:

When the war begins, the first robot collides with the second and gets destroyed instantly, while simultaneously, the fourth robot collides with the fifth, resulting in the destruction of the fourth robot. The resulting array is: .
Now the second robot collides with the third resulting in destruction of third robot. The resulting array is .
No more collisons can take place now, hence the game ends and the remaining robots are the victors.
*/