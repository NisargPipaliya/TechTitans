# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteMiddle(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if(head == None):
            return head

        slow = head
        fast = head
        follow = slow
        while fast != None and fast.next != None:
            follow = slow
            slow = slow.next
            fast = fast.next.next
        
        follow.next = slow.next
        if(fast == slow):
            return None

        return head