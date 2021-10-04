class Solution {
public:
    bool canJump(vector<int>& nums) {
        auto it = nums.begin();
        return canJumpRecur(nums, it);
    }
    bool canJumpRecur(vector<int> &nums, vector<int>::iterator itStart) {
        if (itStart + *itStart >= nums.end() - 1) {     // quit with success: reach the end;
            return true;
        } else if (*itStart == 0) {                     // quit with failure: no moves;
            return false;
        } else {
            int maxReach = 0, iBest = 1;                // greedy search: max(i + *i)
            for (int i = 1; i <= *itStart; i++) {       
                if (i + *(itStart + i) >= maxReach) {   // ">=": when maxReach equal, save the larger i
                    maxReach = i + *(itStart + i);
                    iBest = i;
                }
            }
            return canJumpRecur(nums, itStart + iBest);
        }
    }
};
