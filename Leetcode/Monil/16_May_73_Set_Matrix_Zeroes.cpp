#include <vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> r(matrix.size(),0);
        vector<int> c(matrix[0].size(),0);

        for(int i = 0; i<matrix.size(); i++)
        {
            for(int j = 0; j<matrix[0].size(); j++)
            {
                if(matrix[i][j]==0)
                {
                    c[j]=1;
                    r[i]=1;
                }
            }
        }
        for(int i = 0; i<matrix.size(); i++)
        {
            for(int j = 0; j<matrix[0].size(); j++)
            {
                if(c[j] ==1 || r[i]==1)
                {
                    matrix[i][j]=0;
                }
            }
        }
    }
};