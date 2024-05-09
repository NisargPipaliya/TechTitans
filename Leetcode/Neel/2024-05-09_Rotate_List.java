/*

ROTATE LIST - https://leetcode.com/problems/rotate-list/

Given the head of a linked list, rotate the list to the right by k places.


Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]

*/

class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || k == 0)
            return head;

        int n = 1;
        ListNode temp = head;
        while (temp.next != null) {
            n++;
            temp = temp.next;
        }

        k = k % n;
        if (k == 0)
            return head;

        ListNode last = head;
        for (int i = 1; i < n - k; i++) {
            last = last.next;
        }

        temp.next = head;
        head = last.next;
        last.next = null;

        return head;
    }
}