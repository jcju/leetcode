/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (31.47%)
 * Likes:    4105
 * Dislikes: 5124
 * Total Accepted:    851.1K
 * Total Submissions: 2.6M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (i.e.,
 * x^n).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: x = 2.00000, n = 10
 * Output: 1024.00000
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: x = 2.10000, n = 3
 * Output: 9.26100
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: x = 2.00000, n = -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -100.0 < x < 100.0
 * -2^31 <= n <= 2^31-1
 * -10^4 <= x^n <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {    
        if (n == 0)
            return 1;
        if (n == 1)
            return x;        
        if (n == -1)
            return 1/x;
        double pow = myPow(x, n/2);
        if (n % 2 == 0)
            return pow * pow;
        if (n % 2 == -1)
            return pow * pow * (1/x);
        else
            return pow * pow * x;
    }
};
// @lc code=end

