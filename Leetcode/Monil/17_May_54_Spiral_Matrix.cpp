#include <vector>
#include <algorithm>
using namespace std;class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral;
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, right = n - 1, bottom = m - 1, left = 0;
        
        while (spiral.size() < n * m) {
            for (int j = left; j <= right; ++j)
                spiral.push_back(matrix[top][j]);
            ++top;
            
            for (int i = top; i <= bottom; ++i)
                spiral.push_back(matrix[i][right]);
            --right;
            
            if (top <= bottom) {
                for (int j = right; j >= left; --j)
                    spiral.push_back(matrix[bottom][j]);
                --bottom;
            }
            
            if (left <= right) {
                for (int i = bottom; i >= top; --i)
                    spiral.push_back(matrix[i][left]);
                ++left;
            }
        }
        
        return spiral;
    }
};