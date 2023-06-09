//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverseList(Node *head){
        Node*temp = head;
        Node *prev = NULL;
        
        while(temp != NULL){
            Node *forward = temp->next;
            temp->next = prev;
            prev = temp;
            temp = forward;
        }
        return prev;
    }    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
        // code here
        Node *head1 = reverseList(l1);
        Node *head2 = reverseList(l2);
        
        Node *dummy = new Node(0);
        Node *curr = dummy;

        int carry = 0;
        while(head1 != NULL || head2 != NULL || carry){
            int sum = 0;
            if(head1 != NULL){
                sum += head1->data;
                head1 = head1->next;
            }
            if(head2 != NULL){
                sum += head2->data;
                head2 = head2->next;
            }
            sum += carry;
            carry = sum/10;
            Node *node = new Node(sum%10);
            curr->next = node;
            curr = node;
        }
        return reverseList(dummy->next);        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends