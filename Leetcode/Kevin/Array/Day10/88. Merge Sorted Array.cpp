// Linik :: https://leetcode.com/problems/merge-sorted-array/

class Solution {
    public void merge(int[] num1, int m, int[] num2, int n) {
        int x = 0;
        int y= 0;

        while(y<n && x < m + y && x < m+n -1){
            if(num1[x] <= num2[y]){
                x++;
                continue;
            }
            else{
                int z = m+y;
                while(z > x){
                    num1[z] = num1[z-1];
                    z--;
                }
                num1[x] = num2[y];
                x++;
                y++;
            }

        }
        while(y < n && x < m+n){
            num1[x] = num2[y];
            x++;
            y++;
        }
    }
}