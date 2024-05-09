# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        p = headA
        q = headB
        
        while p != q:
            p = p.next
            q = q.next

            if p == q:
                return p

            if p == None:
                p = headB
            if q == None:
                q = headA

        return p
            