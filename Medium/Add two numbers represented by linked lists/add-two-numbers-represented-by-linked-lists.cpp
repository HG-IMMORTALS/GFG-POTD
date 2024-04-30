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
    //Function to add two numbers represented by linked list.
      void reverseNode(struct Node*& head) {
        if (head == NULL || head->next == NULL)
            return;
        
        Node* prev = NULL;
        Node* current = head;
        Node* next;
    
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
    
        head = prev;
    }
    
    void insertAtBeginning(struct Node*& head, int data){
        Node* temp = new Node(data);
        temp -> next = head;
        head = temp;
    }
    
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        //Removes Unneccessary zeros
        while(num1->data == 0 && num1->next != NULL)
            num1 = num1->next;
        while(num2->data == 0 && num2->next != NULL)
            num2 = num2->next;
        
        reverseNode(num1);
        reverseNode(num2);
            
        Node* sum = NULL;
        
        //Carry
        int c = 0;
        
        while (num1 || num2 || c){
            //temporary sum
            int s = c;
            if (num1){
                s += num1->data;
                num1 = num1->next;
            }
            if (num2){
                s += num2->data;
                num2 = num2->next;
            }
            insertAtBeginning(sum, s%10);
            c = s/10;
        }
           
        return sum;
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
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends