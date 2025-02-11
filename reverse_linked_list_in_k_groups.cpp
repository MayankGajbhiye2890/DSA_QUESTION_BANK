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
    int getLength(ListNode*&head){
        ListNode* temp = head;
        int ans = 0;

        while(temp!=NULL){
            ans++;
            temp = temp->next;
        }

        return ans;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }

        int length = getLength(head);
    
        if (length < k) {
            return head;
        }
        ListNode*curr=head;
        ListNode*next=NULL;
        ListNode*prev=NULL;
        int count=0;
        //int length = getLength(node * head);
        while (curr != NULL && count<k){
            next = curr -> next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }  
        //step 2 reverse after k node mtlb reccursion
        if(next != NULL){
            head->next = reverseKGroup(next, k);
        }
        return prev;

    }
};
