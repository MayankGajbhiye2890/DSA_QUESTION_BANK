#include<bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* merge(ListNode* &l1, ListNode* &l2){
        ListNode * result = new ListNode(-1);
        ListNode * curr = result;
        while(l1 != NULL || l2!=NULL){
            if(l1==NULL){
                curr->next = l2;
                l2 = l2->next;
            }
            else if(l2==NULL){
                curr->next = l1;
                l1 = l1->next;
            }
            //now we know lodes are not null so we need to compare which one is shorter

            else if(l1->val< l2->val){
                curr->next = l1;
                l1= l1->next;
            }
            else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        return result->next;
    }
    ListNode* mergeKLL(vector<ListNode*>& lists, int s, int e){
        //BASE CASE IN WHICH START AND END WILL BE SAME WHICH INDICATES WE REACHED AT A SINGLE ELEMENT ARRAY
        if(s==e){
            return lists[s];
        }

        int mid = s+(e-s)/2;
        //call recursivey left and right side

        ListNode * left = mergeKLL(lists, s, mid);
        ListNode * right = mergeKLL(lists, mid+1, e);

        //merge left and right linked lists
        return merge(left, right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       if(lists.empty()) return NULL;
       int n = lists.size()-1;
       return mergeKLL(lists, 0, n);   
    }
};
