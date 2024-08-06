# Easy
---

### [Floor in a Sorted Array](https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?track=DSASP-Searching&amp%253BbatchId=154&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-a-sorted-array)

```
class Solution{
    
    // Function to find floor of x
    // arr: input array
    // n is the size of array
    static int findFloor(long arr[], int n, long x)
    {
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] >= x) {
                ans = mid;
                //look for smaller index on the left
                high = mid - 1;
            } else {
                low = mid + 1; // look on the right
            }
        }
        if(ans< n && arr[ans] > x){
            return ans-1;
        }
        if(ans == n){
            return ans-1;
        }
        return ans;
    }
    
    
}
```

### [Ceil The Floor](https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=ceil-the-floor)

```
class Solve {
    Pair getFloorAndCeil(int[] arr, int n, int x) {
        // code here
        int f=-1, c=Integer.MAX_VALUE;
        for(int i=0;i< n;i++){
            if(arr[i] == x){
                f = x;
                c= x;
                break;
            }
            if(arr[i] <  x && arr[i] > f){
                f = arr[i];
            }
            if(arr[i] > x && arr[i] < c){
                c = arr[i];
            }
        }
        
        if(c == Integer.MAX_VALUE )
            c = -1;
        
        return (new Pair(f,c));
    }
}

```

### [35. Search Insert Position](https://leetcode.com/problems/search-insert-position/description/)

```
class Solution {
    public int searchInsert(int[] nums, int target) {
        int l = 0, h = nums.length-1;

        while(l <= h){
            int m = (l + h) / 2;

            if(nums[m] == target){
                return m;
            }

            if(nums[m] > target){
                h = m-1;
            }
            else{
                l = m+1;
            }
        }

        return l;
    }
}
```

### [ Ceil The Floor of sorted array](https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401?leftPanelTabValue=SUBMISSION)

```
public class Solution {
    public static int[] getFloorAndCeil(int[] a, int n, int x) {
      // Wriute your code here.
      int c = Solution.getCeil(a, n, x);
      int f = Solution.getFloor(a, n, x);
      int[] ans = {f, c};
      return ans;      
    }

    public static int getFloor(int[] a, int n, int x){
      int l = 0, h = n-1, f = -1;
      while(l <= h){
        int m = (l + h) / 2;

        if(a[m] == x){
          return x;
        }

        if(a[m] <= x){
          f= m;
        }
        if(a[m] <= x){
          l = m+1;
        }
        else{
          h = m-1;
        }
      }
    if(f != -1)
          return a[f];

        

      return f;
    }

    public static int getCeil(int[] a, int n, int x){
      int l = 0, h = n-1, f = -1;
      while(l <= h){
        int m = (l + h) / 2;

        if(a[m] == x){
          return x;
        }

        if(a[m] >= x){
          f= m;
        }
        if(a[m] <= x){
          l = m+1;
        }
        else{
          h = m-1;
        }
      }
    if(f != -1)
          return a[f];
    
      return f;
    }
    
}
```

### [34. Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

```
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int f = floorIndex(nums, target, 0, nums.length -1);
        int c = ceilIndex(nums, target, 0, nums.length -1);
        int[] arr = {c, f};
        return arr;
    }
    public int ceilIndex(int[] nums, int target, int l, int h){
        if(l > h){
            return -1;
        }

        int m = (l + h) / 2;
        if(nums[m] == target){
            int f = m;
            int x = ceilIndex(nums, target, l, m-1);
            if(x != -1){
                return x;
            }
            return f;
        }else if(nums[m] > target){
            return ceilIndex(nums, target, l, m-1);
        }else{
            return ceilIndex(nums, target, m+1, h);
        }
    }

    public int floorIndex(int[] nums, int target, int l, int h){
        if(l > h){
            return -1;
        }

        int m = (l + h) / 2;
        if(nums[m] == target){
            int f = m;
            int x = floorIndex(nums, target, m+1, h);
            if(x != -1){
                return x;
            }
            return f;
        }else if(nums[m] > target){
            return floorIndex(nums, target, l, m-1);
        }else{
            return floorIndex(nums, target, m+1, h);
        }
    }
}
```

### [Number of occurrence](https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-occurrence)

```
class Solution {
    int count(int[] nums, int n, int target) {
        // code here
        int f = floorIndex(nums, target, 0, nums.length -1);
        int c = ceilIndex(nums, target, 0, nums.length -1);
        if(f == -1 && c == -1){
            return 0;
        }
        return f-c+1;
    }
    
    public int ceilIndex(int[] nums, int target, int l, int h){
        if(l > h){
            return -1;
        }

        int m = (l + h) / 2;
        if(nums[m] == target){
            int f = m;
            int x = ceilIndex(nums, target, l, m-1);
            if(x != -1){
                return x;
            }
            return f;
        }else if(nums[m] > target){
            return ceilIndex(nums, target, l, m-1);
        }else{
            return ceilIndex(nums, target, m+1, h);
        }
    }

    public int floorIndex(int[] nums, int target, int l, int h){
        if(l > h){
            return -1;
        }

        int m = (l + h) / 2;
        if(nums[m] == target){
            int f = m;
            int x = floorIndex(nums, target, m+1, h);
            if(x != -1){
                return x;
            }
            return f;
        }else if(nums[m] > target){
            return floorIndex(nums, target, l, m-1);
        }else{
            return floorIndex(nums, target, m+1, h);
        }
    }
}
```

### [33. Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/description/)

```
class Solution {
    public int search(int[] nums, int n) {
        int l = 0;
        int h = nums.length -1;
        int ans = -1;
        while(l <= h){
            int m = (l + h)/2;
            if(nums[m] == n){
                ans = m;
            }
            if(nums[l] <= nums[m]){
                if(nums[l] <= n && nums[m] >= n){
                    h = m-1;
                } 
                else {
                    l = m + 1;
                }
            }else{
                if(nums[m] <= n && nums[h] >= n){
                    l = m + 1;
                }
                else {
                    h = m -1 ;
                }
            }
        }
        return ans;
    }
}
```


### [81. Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/)

```
class Solution {
    public boolean search(int[] nums, int n) {

        int l = 0;
        int h = nums.length -1;
        int ans = -1;
        while(l <= h){
            int m = (l + h)/2;
            if(nums[m] == n){
                ans = m;
            }

            // Edge Case
            if (nums[l] == nums[m] && nums[m] == nums[h]) {
                l = l + 1;
                h = h - 1;
                continue;
            }

            if(nums[l] <= nums[m]){
                if(nums[l] <= n && nums[m] >= n){
                    h = m - 1;
                } 
                else {
                    l = m + 1;
                }
            }else{

                if(nums[m] <= n && nums[h] >= n){
                    l = m + 1;
                }
                else {
                    h = m - 1;
                }
            }
        }
        if(ans == -1){
            return false;
        }

        return true;
    }
}
```