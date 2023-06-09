//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
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
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node *newHead = reverseList(head);
        Node *temp = newHead;
        Node *prev = NULL;
        Node *temp2 = newHead;
        
        int carry = 0;
        while(temp != NULL){
            int sum = 0;
            if(prev == NULL){
                sum = temp->data + 1;
            }
            else{
                sum = temp->data + carry;
            }
            
            carry = sum/10;
            temp->data = sum%10;
            prev = temp;
            temp = temp->next;
        }
        
        if(carry == 1){
            Node *newNode = new Node(1);
            prev->next = newNode;
        }
        return reverseList(temp2);
    }
};







//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends