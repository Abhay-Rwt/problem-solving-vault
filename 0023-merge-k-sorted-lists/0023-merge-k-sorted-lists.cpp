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
public:
    ListNode* sortLL(ListNode* root1, ListNode* root2){
        if(root1 == NULL) return root2;
        if(root2 == NULL) return root1;

        ListNode* head = new ListNode(-1);
        ListNode* tail = head;
        
        while(root1 != NULL && root2 != NULL){
            if(root1->val <= root2->val){
                tail->next = root1;
                root1 = root1->next;
            }
            else{
                tail->next = root2;
                root2 = root2->next;
            }
            tail = tail->next;
        }

        if(root1 != NULL){
            tail->next = root1;
        }
        
        if(root2 != NULL){
            tail->next = root2;
        }

        return head->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* root = NULL;
        for(int i=n-1; i>=0; i--)
        {
            root = sortLL(root, lists[i]);
        }

        return root;
    }
};