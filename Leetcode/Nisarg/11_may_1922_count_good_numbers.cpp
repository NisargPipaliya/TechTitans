#define MOD 1000000007
class Solution {
    
    long long power(long long a,long long b){
        if(b == 0)
            return 1;
        long long temp = power(a,b/2);
        long long ans = (temp * temp) % MOD;
        if(b&1){
            ans = (ans * (a%MOD)) % MOD;
        }
        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        if(n == 1)
            return 5;
        long long four,five;
        if(n&1){
            four = n/2;
            five = (n/2)+1;
        }else{
            four = n/2;
            five = four;
        }
        
        long long int temp1 = power(4,four) % MOD;
        long long int temp2 = power(5,five) % MOD;
        return (temp1 * temp2) % MOD;
    }
};