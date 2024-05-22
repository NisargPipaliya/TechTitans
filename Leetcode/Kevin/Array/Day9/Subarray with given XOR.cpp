//  Link : https://www.interviewbit.com/problems/subarray-with-given-xor/

// Less Optimal Solutution

public class Solution {
    public int solve(int[] a, int b) {
        List<Integer> l = new ArrayList<Integer>();
        l.add(0);
        int xor = 0;
        for(int i=0;i<a.length;i++){
            xor = xor ^ a[i];
            l.add(xor);
        }
        int count = 0;
        
        for(int i=0;i<a.length;i++){
            for(int j = i+1; j< a.length+1;j++){
                if((l.get(i) ^ l.get(j) )== b){
                    count++;
                }
            }
        }
        
        return count;
    }
}


// Optimal Solution

public class Solution {
    public int solve(int[] a, int b) {
        // List<Integer> l = new ArrayList<Integer>();
        // l.add(0);
        // int xor = 0;
        // for(int i=0;i<a.length;i++){
        //     xor = xor ^ a[i];
        //     l.add(xor);
        // }
        // int count = 0;
        
        // for(int i=0;i<a.length;i++){
        //     for(int j = i+1; j< a.length+1;j++){
        //         if((l.get(i) ^ l.get(j) )== b){
        //             count++;
        //         }
        //     }
        // }
        
        // return count;
        
        Map<Integer, Integer> mp = new HashMap<Integer, Integer>();
        mp.put(0, 1);
        int xor = 0;
        int count = 0;

        for(int i =0;i<a.length; i++){
            xor = xor ^ a[i];
            int x = xor ^ b;
            
            if(mp.get(x) != null){
                count += mp.get(x);
            }
            
            if(mp.get(xor) == null){
                mp.put(xor, 1);
            }else{
                mp.put(xor, mp.get(xor)+1);
            }
        }
        return count;
    }
}
    