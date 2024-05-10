
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = nullptr;
        while(head)
        {
            ListNode* n = head;
            head = head->next;
            n->next = temp;
            temp = n;
        }
        return temp;
    }
};