class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int arr[2] = {0};
        for(int i : bills){
            if( i == 5)
                arr[0]++;
            else if(i == 10){
                if(arr[0] > 0)
                    arr[0]--;
                else 
                    return false;
                arr[1]++;
            }
            else if(i == 20){
                if(arr[1] > 0 && arr[0] > 0){
                    arr[1]--;
                    arr[0]--;
                }
                else if(arr[0] >= 3){
                    arr[0] -= 3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};