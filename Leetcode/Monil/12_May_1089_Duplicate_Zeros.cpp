#include <vector>  
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        
        for(int i = 0; i<n; i++)
        {
            if(arr[i] == 0)
            {
                arr.insert(arr.begin()+i,0);
                i = i+1;
                arr.pop_back();
            }
        }
    }
};