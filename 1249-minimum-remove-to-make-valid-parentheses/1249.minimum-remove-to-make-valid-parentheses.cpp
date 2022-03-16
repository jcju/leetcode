/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 *
 * https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/
 *
 * algorithms
 * Medium (64.86%)
 * Likes:    4461
 * Dislikes: 73
 * Total Accepted:    392.4K
 * Total Submissions: 596.6K
 * Testcase Example:  '"lee(t(c)o)de)"'
 *
 * Given a string s of '(' , ')' and lowercase English characters.
 * 
 * Your task is to remove the minimum number of parentheses ( '(' or ')', in
 * any positions ) so that the resulting parentheses string is valid and return
 * any valid string.
 * 
 * Formally, a parentheses string is valid if and only if:
 * 
 * It is the empty string, contains only lowercase characters, or
 * It can be written as AB (A concatenated with B), where A and B are valid
 * strings, or
 * It can be written as (A), where A is a valid string.
 * 
 * 
 * Example 1:
 * 
 * Input: s = "lee(t(c)o)de)"
 * Output: "lee(t(c)o)de"
 * Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
 * 
 * Example 2:
 * 
 * Input: s = "a)b(c)d"
 * Output: "ab(c)d"
 * 
 * Example 3:
 * 
 * Input: s = "))(("
 * Output: ""
 * Explanation: An empty string is also valid.
 * 
 * Constraints:
 * 
 * 1 <= s.length <= 10^5
 * s[i] is either'(' , ')', or lowercase English letter.
 * 
 */

// @lc code=start
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int balance = 0;
        for (int i = 0; i < s.size(); i++) {       // left to right
            if (s[i] == '(')
                balance++;
            else if (s[i] == ')') {
                if (balance <= 0)
                    s.erase(s.begin() + (i--));    // removing orphan ')'
                else 
                    balance--;
            }  
        }
        balance = 0;    
        for (int i = s.size() - 1; i >= 0; i--) {  // right to left
            if (s[i] == ')')
                balance--; 
            else if (s[i] == '(') {                // removing orphan '('
                if (balance >= 0) 
                    s.erase(s.begin() + i);
                else 
                    balance++;
            }    
        }
        return s;   
    }
};
// @lc code=end

