// Date: 25-06-2024
// Start Time: 16:11:56
// End Time  : 16:50:26
// Time Taken: 38 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/
// Rating: Hard
// Description: Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).
// Solved: Yes
// Learning: since the constrains were small recursion was able to pass the tl check and for dp you need to pass the current letters left as one of the parameter

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

vector<int> freq;
int m; // number of words
vector<int> ss;
vector<string> ww;
int rec(int idx)
{
    if (idx == m)
        return 0; // no more words to add to the set
    // check if the word can be formed with the left over letters
    int ans = 0;
    vector<int> left = freq;
    for (int i = 0; i < ww[idx].length(); i++)
    {
        debug(left[ww[idx][i] - 'a'], ww[idx][i] - 'a');
        if (left[ww[idx][i] - 'a'] == 0)
        {
            ans = INT_MIN;
            break;
        }
        left[ww[idx][i] - 'a']--;
    }
    debug(ans, idx);
    if (ans != INT_MIN)
    {
        // it means that we can add this word to our set
        int temp_score = 0;
        for (int i = 0; i < ww[idx].length(); i++)
        {
            freq[ww[idx][i] - 'a']--;
            temp_score += ss[ww[idx][i] - 'a'];
        }
        ans = rec(idx + 1) + temp_score;
        for (int i = 0; i < ww[idx].length(); i++)
        {
            freq[ww[idx][i] - 'a']++;
        }
    }
    debug(idx, ans, max(ans, rec(idx + 1)));
    ans = max(ans, rec(idx + 1));
    return ans;
}

int maxScoreWords(vector<string> &words, vector<char> &letters,
                  vector<int> &score)
{
    int n = letters.size();
    m = words.size();
    freq.assign(26, 0);
    ss = score;
    ww = words;
    for (int i = 0; i < n; i++)
    {
        freq[letters[i] - 'a']++;
    }
    return rec(0);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<char> letter(m);
    vector<int> cost(26);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> letter[i];
    }
    for (int i = 0; i < 26; i++)
    {
        cin >> cost[i];
    }
    cout << maxScoreWords(s, letter, cost);
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