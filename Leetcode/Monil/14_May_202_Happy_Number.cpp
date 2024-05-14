#include <map>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        
        map<int,int> m;

        int val = n;
        int index;

        while(1)
        {
            int sum = 0;

            while(val > 0)
            {
                index = val%10;
                sum += index*index;
                val = val/10;
            }

            if(sum == 1)
            {
                return true;
            }
            if(m[sum]==1)
            {
                return false;
            }

            m[sum]=1;
            val = sum;
        }
    }
};