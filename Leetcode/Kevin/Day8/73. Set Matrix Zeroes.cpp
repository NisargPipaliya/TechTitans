// Link :: https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> c(m,0);
        vector<int> r(n,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    r[i] = 1;
                    c[j] = 1;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(r[i] || c[j]){
                    matrix[i][j] = 0;
                }
            }
        }

        

    }
};