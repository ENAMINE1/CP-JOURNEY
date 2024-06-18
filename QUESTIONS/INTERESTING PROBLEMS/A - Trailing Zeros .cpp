// Date: 18-06-2024
// Start Time: 22:03:03
// End Time  :
// Time Taken:
// Author: Shashwat Kumar
// QUESTION LINK: https://atcoder.jp/contests/arc139/tasks/arc139_a
// Rating: Medium
// Description: create a strictly increasing array with t[i] trailing zeros in the a[i] number
// Solved: No
// Learning: how to find the smallest number than a given number with required number of trailing zeros

/*
The formula \( y_1 = \left( \left\lfloor \frac{A_{i-1}}{2^{T_i}} \right\rfloor + 1 \right) \cdot 2^{T_i} \) is used to find the smallest integer greater than \( A_{i-1} \) that has exactly \( T_i \) trailing zeros in its binary representation. Here's a detailed explanation of why this formula works:

### Understanding the Formula

1. **Divisibility by \( 2^{T_i} \)**:
   - For a number \( x \) to have \( T_i \) trailing zeros, it must be divisible by \( 2^{T_i} \).
   - This ensures \( x \) ends in \( T_i \) zeros when represented in binary form.

2. **Not Divisibility by \( 2^{T_i + 1} \)**:
   - To ensure the number has exactly \( T_i \) trailing zeros (and not more), \( x \) must not be divisible by \( 2^{T_i + 1} \).

3. **Finding \( y_1 \)**:
   - To find the smallest integer greater than \( A_{i-1} \) that is divisible by \( 2^{T_i} \):
     - We divide \( A_{i-1} \) by \( 2^{T_i} \), take the integer part of the division, add 1 to ensure the result is greater than \( A_{i-1} \), and then multiply back by \( 2^{T_i} \).
     - This ensures that \( y_1 \) is the smallest multiple of \( 2^{T_i} \) greater than \( A_{i-1} \).

### Why This Works

Let's break it down step-by-step:

#### Step-by-Step Breakdown

1. **Division and Floor Function**:
   - \( \left\lfloor \frac{A_{i-1}}{2^{T_i}} \right\rfloor \) gives the largest integer \( k \) such that \( k \cdot 2^{T_i} \leq A_{i-1} \).
   - This ensures that \( k \cdot 2^{T_i} \) is a multiple of \( 2^{T_i} \) that is less than or equal to \( A_{i-1} \).

2. **Increment and Multiplication**:
   - By adding 1, we get \( k + 1 \), which ensures the resulting multiple of \( 2^{T_i} \) is greater than \( A_{i-1} \).
   - Multiplying by \( 2^{T_i} \) again scales it back to the proper multiple of \( 2^{T_i} \).

3. **Ensuring the Number of Trailing Zeros**:
   - The result \( y_1 = (k + 1) \cdot 2^{T_i} \) is guaranteed to be divisible by \( 2^{T_i} \) but needs to be checked if it's not divisible by \( 2^{T_i + 1} \).

#### Example

Let's apply this formula with a specific example:

Suppose \( A_{i-1} = 5 \) and \( T_i = 2 \):

1. **Calculate the Floor Division**:
   - \( \left\lfloor \frac{5}{4} \right\rfloor = \left\lfloor 1.25 \right\rfloor = 1 \).

2. **Increment and Multiply**:
   - Increment: \( 1 + 1 = 2 \).
   - Multiply: \( 2 \cdot 4 = 8 \).

3. **Check \( \text{ctz}(8) \)**:
   - \( 8 \) in binary is \( 1000 \), which has \( \text{ctz}(8) = 3 \). Since this is not the required \( T_i = 2 \), we increment by \( 4 \):
   - Next candidate: \( 8 + 4 = 12 \).

4. **Check \( \text{ctz}(12) \)**:
   - \( 12 \) in binary is \( 1100 \), which has \( \text{ctz}(12) = 2 \). This matches \( T_i = 2 \).

Thus, \( A_i = 12 \) in this example.

### Conclusion

The formula \( y_1 = \left( \left\lfloor \frac{A_{i-1}}{2^{T_i}} \right\rfloor + 1 \right) \cdot 2^{T_i} \) efficiently finds the smallest number greater than \( A_{i-1} \) that has the exact number of trailing zeros specified by \( T_i \). It ensures \( y_1 \) is a multiple of \( 2^{T_i} \) and then checks the minimal increment needed to ensure it fits the criteria for trailing zeros. This guarantees the sequence \( A \) remains strictly increasing while meeting the trailing zero constraints.
*/

#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    long long ans = 0;
    for (int i = 0, t; i < N; i++)
    {
        cin >> t;
        long long pt = 1LL << t;
        ans = (ans / pt + 1) * pt;
        if (ans % (pt * 2) == 0)
            ans += pt;
    }
    cout << ans << "\n";
}
