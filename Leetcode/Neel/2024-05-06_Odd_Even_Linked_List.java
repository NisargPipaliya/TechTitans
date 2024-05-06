/*

ODD EVEN LINKED LIST - https://leetcode.com/problems/odd-even-linked-list/

Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.


Example 1:


Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:


Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]

*/

class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null)
            return head;

        ListNode oddNode = head;
        ListNode evenNode = head.next;
        ListNode head2 = evenNode;

        while (evenNode != null && evenNode.next != null) {
            oddNode.next = oddNode.next.next;
            evenNode.next = evenNode.next.next;

            oddNode = oddNode.next;
            evenNode = evenNode.next;
        }
        oddNode.next = head2;

        return head;
    }
}