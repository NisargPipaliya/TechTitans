My code:
long long int MOD = 1e9+7;
    
    void help(int arr[], int index, int n, int curr, int sum, long long &ans){
        if(index > n)
            return;
        if(curr == sum ){
            ans = (ans + 1) % MOD;
            int c1 = curr + arr[index++];
            help(arr,index,n,c1,sum,ans);
            return;
        }
        int c1 = curr + arr[index++], c2 = curr;
        
        help(arr,index,n,c1,sum,ans);
        help(arr,index,n,c2,sum,ans);
    }
	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        long long ans = 0;
        help(arr,0,n,0,sum,ans);
        return ans % MOD;
	}