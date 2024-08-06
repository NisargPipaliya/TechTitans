
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        // int cnt = 0;
        // ListNode* temp = head;

        // while (temp)
        // {
        //     cnt++;
        //     temp = temp->next;
        // }
        // if(cnt%2 == 0)
        // {
        //     cnt = (cnt/2) + 1;
        // }
        // else{
        //     cnt = (cnt+1)/2;
        // }

        // while(head)
        // {
        //     cnt--;

        //     if(cnt<=0)
        //     {
        //         return head;
        //     }
        //     head = head->next;
        // }
        // return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};