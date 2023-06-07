//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
public: 
    Node* reverseList(Node *head){
        Node *temp = head;
        Node *prev = NULL;

        while(temp != NULL){
            Node *forward = temp->next;
            temp->next = prev;
            prev = temp;
            temp = forward;
        }
        return prev;
    }

    bool isPalindrome(Node* head) {
        Node *slow = head;
        Node *fast = head;

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
            if(slow->data != head->data){
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



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends