/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* help(ListNode*head, ListNode* parent){
        if(!head)
            return NULL;
        if(head->next == nullptr){
            head->next = parent;
            return head;
        }
        ListNode* ans = help(head->next,head);
        head->next = parent;
        return ans;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head)
            return false;
        ListNode *slow = head, *fast = head;

        while(fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* nhead = help(slow->next,nullptr);
        ListNode *p = head, *q = nhead;

        while(q && p && p->val == q->val){
            p = p->next;
            q = q->next;
        }
        help(slow->next,nullptr);
        return q == nullptr;
    }
};