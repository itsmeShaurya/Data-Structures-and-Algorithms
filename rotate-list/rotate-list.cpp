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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }

        ListNode* curr = head;
        int length = 1;
        while(curr->next != NULL){
            length++;
            curr = curr->next;
        }
        curr->next = head;
        k = k%length;
        k = length - k;

        while(k--){
            curr = curr->next;
        }
        head = curr->next;
        curr->next = NULL;
        return head;

    }
};