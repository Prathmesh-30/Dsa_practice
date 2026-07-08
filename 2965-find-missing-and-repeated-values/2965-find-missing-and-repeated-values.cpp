class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> s;
        int n = grid.size();
        int a = -1, b = -1;
        long long actualSum = 0; 
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) { 
                actualSum += grid[i][j];

                
                if (s.find(grid[i][j]) != s.end()) {
                    a = grid[i][j];
                }
                s.insert(grid[i][j]);
            }
        }

        long long totalElements = n * n;
        long long expSum = totalElements * (totalElements + 1) / 2;
        
        b = expSum + a - actualSum;
        
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};