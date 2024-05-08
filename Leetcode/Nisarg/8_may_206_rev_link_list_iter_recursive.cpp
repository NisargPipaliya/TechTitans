//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(!head)
//             return NULL;
//         vector<int> v;
//         ListNode* p = head;
//         while(p){
//             v.emplace_back(p->val);
//             p = p->next;
//         }
//         reverse(v.begin(),v.end());

//         ListNode*ans = new ListNode(v[0]);
//         p = ans;
//         for(int i = 1; i < v.size(); i++){
//             p->next = new ListNode(v[i]);
//             p = p->next;
//         }
//         return ans;
//     }
// };

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
    ListNode* reverseList(ListNode* head) {
        return help(head,NULL);
    }
};