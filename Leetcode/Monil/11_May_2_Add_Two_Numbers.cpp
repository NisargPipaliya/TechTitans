
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l = new ListNode(0);
        ListNode* head = l;
        ListNode* t1 = l1;
        ListNode* t2 = l2;

        int carry = 0;

        while(t1 && t2)
        {
            int sum = t1->val + t2->val;
            if(carry)
            {
                sum += carry;
                carry = 0;
            }
            if(sum >= 10)
            {
                sum = sum - 10;
                carry = 1;
            }

            ListNode* n = new ListNode(sum);
            head->next = n;
            head = head->next;

            t1 = t1->next;
            t2 = t2->next;
        }

        while(t1)
        {
            int sum = t1->val;
            if(carry)
            {
                sum += carry;
                carry = 0;
            }
            if(sum >= 10)
            {
                sum = sum - 10;
                carry = 1;
            }

            ListNode* n = new ListNode(sum);
            head->next = n;
            head = head->next;

            t1 = t1->next;
        }
        while(t2)
        {
            int sum = t2->val;
            if(carry)
            {
                sum += carry;
                carry = 0;
            }
            if(sum >= 10)
            {
                sum = sum - 10;
                carry = 1;
            }

            ListNode* n = new ListNode(sum);
            head->next = n;
            head = head->next;

            t2 = t2->next;
        }
        if(carry)
        {
            ListNode* n = new ListNode(carry);
            head->next = n;
            carry = 0;
        }
        return l->next;
    }
};