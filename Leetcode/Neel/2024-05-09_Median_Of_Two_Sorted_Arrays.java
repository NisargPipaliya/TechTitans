/*

MEDIAN OF TWO SORTED ARRAYS - https://leetcode.com/problems/median-of-two-sorted-arrays/

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.


Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

*/

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int l1 = nums1.length, l2 = nums2.length;
        int l = l1 + l2;
        int[] arr = new int[l];
        int i = 0, j = 0, k = 0;
        while (i < l1 && j < l2) {
            if (nums1[i] < nums2[j])
                arr[k++] = nums1[i++];
            else
                arr[k++] = nums2[j++];
        }
        while (i < l1) {
            arr[k++] = nums1[i++];
        }
        while (j < l2) {
            arr[k++] = nums2[j++];
        }
        int mid = arr.length / 2;
        if (arr.length % 2 != 0) {
            return (double)(arr[mid]);
        }
        return (double)((arr[mid - 1] + arr[mid]) / 2.0);
    }
}