
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next() {}
  };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next!=nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(slow==fast)
            {
                slow = head;

                while(slow!=fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};