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

//Here we will not use (fast != NULL && fast->next != NULL) because in this we need first middle node when nodes are even.

class Solution {
public: 
    ListNode* reverseList(ListNode *head){
        ListNode *temp = head;
        ListNode *prev = NULL;

        while(temp != NULL){
            ListNode *forward = temp->next;
            temp->next = prev;
            prev = temp;
            temp = forward;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        if(head == NULL || head->next == NULL){
            return true;
        }

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverseList(slow->next);
        slow = slow->next;

        while(slow != NULL){
            if(slow->val != head->val){
                return false;
            }
            else{
                slow = slow->next;
                head= head->next;
            }
        }
        return true;
    }
};