//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    int min = -1;
    int max = -1;
    
    for(int i = 0; i<n; i++)
    {
        if(arr[i]==x)
        {
            pair<int, int> ans;
            ans.first = x;
            ans.second = x;
            return ans;
        }
        if(arr[i]>x)
        {
            if(max == -1)
            {
                max = arr[i];
            }
            else{
                if(max > arr[i])
                {
                    max = arr[i];
                }
            }
        }
        else
        {
            if(min == -1)
            {
                min = arr[i];
            }
            else{
                if(min < arr[i])
                {
                    min = arr[i];
                }
            }
        }
    }
    pair<int, int> ans;
    ans.first = min;
    ans.second = max;
    return ans;
}