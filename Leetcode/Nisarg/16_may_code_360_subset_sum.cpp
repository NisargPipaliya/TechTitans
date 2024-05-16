bool help(int curr, int index, int n, int k, vector<int> &a){
    if(curr == k)
        return true;
    if(index == n || curr > k){
        return curr == k;
    }

    int c1 = curr + a[index++], c2 = curr;

    if(c1 <= k){
        bool a1 = help(c1,index,n,k,a);
        if(a1)
            return a1;
    }
    if(c2 <= k){
        bool a2 = help(c2,index,n,k,a);
        return a2;
    }
    return false;
}
bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here
    return help(0,0,n,k,a);
}