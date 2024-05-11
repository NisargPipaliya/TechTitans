
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int cnt = 0;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode *cur = head, *nex = dummy, *pre = dummy;

        if(!head || k == 1)
            return head;
        while(cur)
        {
            cnt++;
            cur = cur->next;
        }

        while(cnt >= k)
        {
            cur = pre->next;
            nex = cur->next;

            for(int i = 0; i < k-1; i++)
            {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }

            cnt -=k;
            pre = cur;
        }
        return dummy->next;

    }
};