
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next() {}
  };

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};