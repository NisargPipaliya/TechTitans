#include<vector>
using namespace std;

int lb(vector<int> &arr, int l, int h){
    if(l > h)
        return -1;
    
    int mid = (l+h)/2;

    if(arr[mid] == 1)
    {
        while(arr[mid] == 1 && mid >= 0)
            mid--;
        ++mid;
        return arr.size() - mid ;
    }else if(arr[mid] == 0){
        l = mid + 1;
    }
    return lb(arr,l,h);
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    //    Write your code here.
    int ans = INT_MAX, tans = -1;
    for(int i = 0; i < n; i++){
        int temp = lb(matrix[i],0,m-1);

        if(temp > tans){
            tans = temp;
            ans = i;
        }
    }
    return ans;
}