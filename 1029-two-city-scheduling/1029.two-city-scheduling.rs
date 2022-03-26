/*
 * @lc app=leetcode id=1029 lang=cpp
 *
 * [1029] Two City Scheduling
 *
 * https://leetcode.com/problems/two-city-scheduling/description/
 *
 * algorithms
 * Medium (58.89%)
 * Likes:    3443
 * Dislikes: 265
 * Total Accepted:    170.1K
 * Total Submissions: 269.1K
 * Testcase Example:  '[[10,20],[30,200],[400,50],[30,20]]'
 *
 * A company is planning to interview 2n people. Given the array costs where
 * costs[i] = [aCosti, bCosti], the cost of flying the i^th person to city a is
 * aCosti, and the cost of flying the i^th person to city b is bCosti.
 * 
 * Return the minimum cost to fly every person to a city such that exactly n
 * people arrive in each city.
 * 
 * Example 1:
 * 
 * Input: costs = [[10,20],[30,200],[400,50],[30,20]]
 * Output: 110
 * Explanation: 
 * The first person goes to city A for a cost of 10.
 * The second person goes to city A for a cost of 30.
 * The third person goes to city B for a cost of 50.
 * The fourth person goes to city B for a cost of 20.
 * 
 * The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people
 * interviewing in each city.
 * 
 * Example 2:
 * 
 * Input: costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
 * Output: 1859
 * 
 * Example 3:
 * 
 * Input: costs =
 * [[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
 * Output: 3086
 * 
 * Constraints:
 * 
 * 2 * n == costs.length
 * 2 <= costs.length <= 100
 * costs.length is even.
 * 1 <= aCosti, bCosti <= 1000
 * 
 */

// @lc code=start
impl Solution {
    pub fn two_city_sched_cost(costs: Vec<Vec<i32>>) -> i32 {
        let size: usize = costs.len();
        let mut res: i32 = 0;
        let moneySaved: Vec<i32> = {
            let mut moneySaved: Vec<i32> = vec![0; size];
            for (idx, cost) in costs.into_iter().enumerate() {
                moneySaved[idx] = cost[1] - cost[0];
                res += cost[0];
            }
            moneySaved.sort();
            moneySaved
        };
        for idx in 0..size / 2 {
            res += moneySaved[idx];
        }
        res
    }
}

// @lc code=end

