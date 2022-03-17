/*
 * @lc app=leetcode id=946 lang=cpp
 *
 * [946] Validate Stack Sequences
 *
 * https://leetcode.com/problems/validate-stack-sequences/description/
 *
 * algorithms
 * Medium (64.77%)
 * Likes:    3422
 * Dislikes: 60
 * Total Accepted:    170.7K
 * Total Submissions: 252.9K
 * Testcase Example:  '[1,2,3,4,5]\n[4,5,3,2,1]'
 *
 * Given two integer arrays pushed and popped each with distinct values, return
 * true if this could have been the result of a sequence of push and pop
 * operations on an initially empty stack, or false otherwise.
 * 
 * Example 1:
 * Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
 * Output: true
 * Explanation: We might do the following sequence:
 * push(1), push(2), push(3), push(4),
 * pop() -> 4,
 * push(5),
 * pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
 * 
 * Example 2:
 * Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
 * Output: false
 * Explanation: 1 cannot be popped before 2.
 * 
 * Constraints:
 * 
 * 1 <= pushed.length <= 1000
 * 0 <= pushed[i] <= 1000
 * All the elements of pushed are unique.
 * popped.length == pushed.length
 * popped is a permutation of pushed.
 * 
 */

// @lc code=start
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int pos = -1, posRight = -1;
        for (int i = 0; i < popped.size(); i++) {
            if (i+1 == popped.size())
                return true;
            pos = findIndex(pushed, popped[i]);
            posRight = findIndex(pushed, popped[i+1]);
            if (posRight == pos - 1 || posRight > pos) {
                pushed.erase(pushed.begin() + pos);
                continue;
            } else
                return false;            
        }
        return true;
    }    
    int findIndex(vector<int>& vec, int num) {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == num)
                return i;
        }
        return -1; 
    }
};
// @lc code=end

