#include<vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        
        int dist = 0;
        int index = -1;
        

        for(int i = 0;i< points.size();i++)
        {
            int sum = 0;
            if(x == points[i][0] || y == points[i][1])
            {
                sum = abs(x - points[i][0]) + abs(y - points[i][1]);
                if(index == -1)
                {
                    dist = abs(x - points[i][0]) + abs(y - points[i][1]);
                    index = i;
                }
                if(sum < dist)
                {
                    dist = sum;
                    index = i;
                }
            }
        }
        return index;
    }
};