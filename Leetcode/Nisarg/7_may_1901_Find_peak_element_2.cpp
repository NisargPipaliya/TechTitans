#include<vector>
using namespace  std;
class Solution {
    int findMax(vector<vector<int>> &mat, int rows, int cols, int col){
        int maxi = INT_MIN;
        int ans = 0;
        for(int i = 0; i < rows; i++){
            if(maxi < mat[i][col])
            {
                maxi = mat[i][col];
                ans = i;
            }
        }
        return ans;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int l = 0, h = m - 1;

        while(l <= h){
            int mid = (l+h) / 2;
            int row = findMax(mat,n,m,mid);
            int left = mid - 1 >=0 ? mat[row][mid-1] : -1;
            int right = mid + 1 < m ? mat[row][mid+1] : -1;

            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row,mid};
            }else if(mat[row][mid] < left)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return {-1,-1};
    }
};