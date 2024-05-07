/*

DOUBLE A NUMBER REPRESENTED AS A LINKED LIST - https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/

You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

Return the head of the linked list after doubling it.
 

Example 1:


Input: head = [1,8,9]
Output: [3,7,8]
Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.
Example 2:


Input: head = [9,9,9]
Output: [1,9,9,8]
Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998.

*/

class Solution {
    public ListNode doubleIt(ListNode head) {
        Stack<Integer> st = new Stack<>();
        ListNode temp = head;
        while (temp != null) {
            st.push(temp.val);
            temp = temp.next;
        }
        ListNode newHead = null;
        int ans = 0;
        while (!st.empty() || ans != 0) {
            newHead = new ListNode(0, newHead);
            if (!st.empty())
                ans += (st.pop() * 2);
            newHead.val = ans % 10;
            ans /= 10;
        }
        return newHead;
    }
}