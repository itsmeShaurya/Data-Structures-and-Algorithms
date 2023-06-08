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
     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL){
            return list2;
        }

        if(list2 == NULL){
            return list1;
        }

       
        if(list1->val > list2->val){
            swap(list1, list2);
        }

        ListNode* res = list1;
        while(list1 != NULL && list2 != NULL){
            ListNode* temp = NULL;
            while(list1 != NULL && list1->val <= list2->val){
                temp = list1;
                list1 = list1->next;
            }
            temp->next = list2;
            swap(list1, list2);
        }
        return res;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *temp = NULL;

        while(fast != NULL && fast->next != NULL){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;

        ListNode *list1 = sortList(head);
        ListNode *list2 = sortList(slow);

        return mergeTwoLists(list1, list2);
    }
};