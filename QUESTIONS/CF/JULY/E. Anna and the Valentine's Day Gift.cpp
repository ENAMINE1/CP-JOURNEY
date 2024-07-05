// Date: 05-07-2024
// Start Time: 12:09:21
// End Time  : 14:10:28
// Time Taken: 121 minutes
// Author: Shashwat Kumar
// QUESTION LINK: https://codeforces.com/problemset/problem/1931/E
// Rating: 1400
// Description: How many digits will be left in the last number in the array after some operations
// Solved: Yes
// Learning: If you have to write more than 60 or 70 lines of code for a problem less than 1500 rating question then you porbably need to rethink for a different approach, the commented code is the previous thought

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
#define endl '\n'

/************************************************************************************************Main Function**************************************************/

/*
long long flip(long long a)
{
    // actually the number of digits is log10(a) + 1
    int digits = log10(a);
    // debug(digits);
    long long temp = a;
    a = 0;
    for (int i = digits; i >= 0; i--)
    {
        a += (temp / (long long)pow(10, i)) * (long long)pow(10, digits - i);
        temp = temp % (long long)pow(10, i);
    }
    return a;
}

long long concat(long long a, long long b)
{
    int digits = log10(b) + 1;
    a = a * (long long)pow(10, digits);
    a += b;
    return a;
}

class customComparator
{
public:
    bool operator()(long long a, long long b)
    {
        return flip(a) > flip(b);
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    priority_queue<long long> non_zero;
    priority_queue<int, vector<int>, customComparator> zero;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp % 10)
            non_zero.push(temp);
        else
            zero.push(temp);
    }
    int turn = 0; // 0 is for alice and 1 is for bob
    // debug(non_zero.size(), zero.size());

    while (!(non_zero.size() == 1 && zero.empty()))
    {
        // debug(non_zero.size(), zero.size());
        if (turn)
        {
            // bob's strategy
            long long a, b;
            if (!zero.empty())
            {
                a = zero.top();
                zero.pop();
                if (zero.size() >= 1)
                {
                    b = zero.top();
                    long long temp = flip(b);
                    if (log10(temp) >= log10(non_zero.top()))
                        zero.pop();
                    else
                    {
                        b = non_zero.top();
                        non_zero.pop();
                    }
                }
                else
                {
                    b = non_zero.top();
                    non_zero.pop();
                }
            }
            else
            {
                a = non_zero.top();
                non_zero.pop();
                b = non_zero.top();
                non_zero.pop();
            }
            long long c = concat(a, b);
            if (c % 10)
                non_zero.push(c);
            else
                zero.push(c);
            debug(a, b, c);
        }
        else
        {
            if (!zero.empty())
            {
                long long a = zero.top();
                zero.pop();
                // O(9) for flipping
                a = flip(a);
                debug(a);
                non_zero.push(a);
            }
        }
        turn ^= 1;
    }
    debug(non_zero.size());
    long long largest = non_zero.top();
    cerr
        << largest << endl;
    debug((int)log10(largest) + 1, m);
    if (log10(largest) >= m)
        cout << "Sasha" << endl;
    else
        cout << "Anna" << endl;
    non_zero.pop();
}
*/

void solve()
{
    int n, m;
    cin >> n >> m;
    // my target is to get more than m digits in my final answer
    vector<int> trailing_zeros_in_a_number;
    // for sure anna will not be able to remove the non zero digits so simply add them to the final number
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        int zeros = 0;
        int non_zero_digits = 0;
        while (!(temp % 10))
            zeros++, temp /= 10;
        while (temp)
            non_zero_digits++, temp /= 10;
        m -= non_zero_digits;
        trailing_zeros_in_a_number.push_back(zeros);
    }
    // now anna wiil try to remove those numbers which have the max number of zeros and then when sasha's turn will come he will try to get the next number with the largest number of zeros and concatenate it with another number so that the zeros in the number reflect in the final number
    sort(trailing_zeros_in_a_number.begin(), trailing_zeros_in_a_number.end(), greater<int>());
    for (int i = 1; i < trailing_zeros_in_a_number.size(); i += 2)
        m -= trailing_zeros_in_a_number[i];
    cout << ((m < 0) ? "Sasha" : "Anna") << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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
    return 0;
}