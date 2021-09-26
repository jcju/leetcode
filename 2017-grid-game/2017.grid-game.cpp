class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        
        int n = grid[0].size();

        long remainSumTop = accumulate(begin(grid[0])+1, end(grid[0]), 0l);
        long remainSumBottom = 0;
        long remainSum = max(remainSumTop, remainSumBottom);

        long minRemainSum = remainSum;
        for (int c = 1; c < n; c++)           
        {
            remainSumTop -= grid[0][c];
            remainSumBottom += grid[1][c-1];
            remainSum = max(remainSumTop, remainSumBottom);

            if (remainSum < minRemainSum)
            {
                minRemainSum = remainSum;
            }
        }

        return minRemainSum;
        
    }
};
