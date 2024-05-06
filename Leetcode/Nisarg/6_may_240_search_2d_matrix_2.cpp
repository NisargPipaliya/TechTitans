#include<vector>
using namespace std;

class Solution {
    bool bSearch(vector<int> &arr, int l, int h, int target){
        if(l > h)
            return false;
        int mid = (l+h)/2;

        if(arr[mid] == target)
            return true;
        else if( arr[mid] > target)
            h = mid - 1;
        else 
            l = mid + 1;
        return bSearch(arr,l,h,target);
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size(), n = matrix[0].size() - 1;

        for(int i = 0; i < m; i++)
        {
            bool ans = bSearch(matrix[i], 0,n,target);
            if(ans)
                return ans;

        }
        return false;
    }
};