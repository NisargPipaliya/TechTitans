# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    # def insert(self,head,inode):
    #     p = head
    #     q = p

    #     while(p != None and p.val < inode.val):
    #         q = p
    #         p = p.next
    #     if(p == None):
    #         q.next = inode
    #         return
    #     inode.next = p
    #     q.next = inode

    def find_mid(self,head):
        slow = head
        fast = head

        while(fast.next != None and fast.next.next != None):
            slow = slow.next
            fast = fast.next.next
        return slow

    def merge_sort(self,head):
        if(head == None or head.next == None):
            return head
        left_head = head
        mid = self.find_mid(head)
        right_head = mid.next
        mid.next = None

        left_head = self.merge_sort(left_head)
        right_head = self.merge_sort(right_head)

        return self.merge(left_head,right_head)

    def merge(self,left,right):
        ans = ListNode()
        p = left
        q = right
        r = ans

        if p.val < q.val:
            ans.val = p.val
            p = p.next
        else:
            ans.val = q.val
            q = q.next

        while(p and q):
            temp = ListNode()
            if p.val < q.val:
                temp.val = p.val
                p = p.next
            else:
                temp.val = q.val
                q = q.next
            
            r.next = temp
            r = r.next
        while p != None:
            temp = ListNode()
            temp.val = p.val
            p = p.next
            r.next = temp
            r = r.next

        while q != None:
            temp = ListNode()
            temp.val = q.val
            q = q.next
            r.next = temp
            r = r.next
        
        return ans

    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # ans = ListNode()
        # ans.val = float('-inf')

        # p = head
        # while p != None:
        #     temp = ListNode()
        #     temp.val = p.val
        #     self.insert(ans,temp)
        #     p = p.next

        # return ans.next
        if(head == None):
            return head
        return self.merge_sort(head)