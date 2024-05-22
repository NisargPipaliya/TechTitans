
// Link :: https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        int max = 0;
        vector<int> ans;
        for(int i = n-1; i>=0; i--){
            if(a[i] >= max){
                ans.insert(ans.begin(), a[i]);
                max = a[i];
            }
        }
        return ans;
    }
};