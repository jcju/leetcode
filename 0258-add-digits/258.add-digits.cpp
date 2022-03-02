/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 *
 * https://leetcode.com/problems/add-digits/description/
 *
 * algorithms
 * Easy (59.56%)
 * Likes:    2335
 * Dislikes: 1630
 * Total Accepted:    455.3K
 * Total Submissions: 731.9K
 * Testcase Example:  '38'
 *
 * Given an integer num, repeatedly add all its digits until the result has
 * only one digit, and return it.
 * 
 * Example 1:
 * 
 * Input: num = 38
 * Output: 2
 * Explanation: The process is
 * 38 --> 3 + 8 --> 11
 * 11 --> 1 + 1 --> 2 
 * Since 2 has only one digit, return it.
 * 
 * Constraints:
 *  
 * 0 <= num <= 2^31 - 1
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        int res = (num < 10) ? num : addDigits(num / 10) + num % 10;
        return (res < 10) ? res : addDigits(res);
    }
};
// @lc code=end

