### [78\. Subsets](https://leetcode.com/problems/subsets/)

Difficulty: **Medium**  

Related Topics: [Array](https://leetcode.com/tag/array/), [Backtracking](https://leetcode.com/tag/backtracking/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

Runtime: **0 ms**, faster than **100.00%** of C++ submissions.  
Memory Usage: **7.0 MB**, less than **83.97%** of C++ submissions.

<br/>
A iterative solution using Cascading method. In $i$th iteration, the first $2^{i-1}$ of the output array are invariant. Time: $O(N×2^N)$, Memory $O(N×2^N)$.


