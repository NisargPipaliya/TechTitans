
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next() {}
 };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         ListNode *temp1 = headA;
         ListNode *temp2 = headB;

         while(temp1 && temp2)
         {
            if(temp1 == temp2)
            {
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;

            if(temp1 || temp2)
            {
                if(temp1 == nullptr)
                {
                    temp1 = headB;
                }
                if(temp2 == nullptr)
                {
                    temp2 = headA;
                }
            }
         } 
         return nullptr;
    }
};