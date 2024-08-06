
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:

    ListNode* reverse(ListNode* head)
    {
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        ListNode* newHead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;
        
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(head==nullptr || head->next == nullptr)
        {
            return true;
        }

        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* newHead = reverse(slow->next);
        ListNode* tail = newHead;

        while(tail!=nullptr)
        {
            if(head->val != tail->val)
            {
                reverse(newHead);
                return false;
            }
            head = head->next;
            tail = tail->next;
        }
        reverse(newHead);

        return true;
    }
};