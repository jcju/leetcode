/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 *
 * https://leetcode.com/problems/wiggle-subsequence/description/
 *
 * algorithms
 * Medium (43.11%)
 * Likes:    3978
 * Dislikes: 128
 * Total Accepted:    188.4K
 * Total Submissions: 394.2K
 * Testcase Example:  '[1,7,4,9,2,5]'
 *
 * A wiggle sequence is a sequence where the differences between successive
 * numbers strictly alternate between positive and negative. The first
 * difference (if one exists) may be either positive or negative. A sequence
 * with one element and a sequence with two non-equal elements are trivially
 * wiggle sequences.
 * 
 * 
 * For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences
 * (6, -3, 5, -7, 3) alternate between positive and negative.
 * In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences.
 * The first is not because its first two differences are positive, and the
 * second is not because its last difference is zero.
 * 
 * 
 * A subsequence is obtained by deleting some elements (possibly zero) from the
 * original sequence, leaving the remaining elements in their original order.
 * 
 * Given an integer array nums, return the length of the longest wiggle
 * subsequence of nums.
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> diffVec;
        for (int i = 1; i < nums.size(); i++) {
            int diff = nums[i] - nums[i-1];
            if (diff != 0)                  // discard when diff == 0
                diffVec.push_back(diff);
        }
        for (int i = 1; i < diffVec.size(); i++) {
            if (sign(diffVec[i]) == sign(diffVec[i-1])){
                diffVec.erase(diffVec.begin() + i);
                i--;
            }
        }
        return diffVec.size() + 1;
    }
    bool sign(int num) {
        return (num >= 0) ? true : false;
    }
};
// @lc code=end

