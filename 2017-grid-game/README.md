
### [2017\. Grid Game](https://leetcode.com/problems/grid-game/)

Difficulty: **Medium**

Runtime: **152 ms**, faster than **83.33%** of C++ submissions.  
Memory Usage: **62.8 MB**, less than **91.67%** of C++ submissions.

<br/>  
You don't need to write a func to calculate optimal path & score for second robot, which will cause TLE.  

After first Robot's pass, the 2D array will have a "Z-shape" all zero path. The second Robot has actually only TWO options:

1. Going down on `the first column`, score all non-zeros on the row Bottom;
2. Going down on `the last column` (rightmost), score all non-zeros on the row Top;

All other moves will have lower score than these two, obviously.

Then the question is simplified: just go through the columns, to find the `column i` that minimize the bigger one of two `row sums` (blue area below).

<img src="https://miro.medium.com/max/1400/1*nrzdTiRnDqs-Lv6_hBYSiA@2x.jpeg" width="560">

In other words, to minimize *max*(*sumRowTop*, *sumRowBottom*), you need to make *sumRowTop* and *sumRowBottom* as close as possible.

