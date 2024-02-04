//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
     Node* Reverse(Node* head)
    {
        Node* prev=NULL;
        while(head)
        {
            Node* ahead=head->next;
            head->next=prev;
            prev=head;
            head=ahead;
        }
        return prev;
    }
    pair<Node*,bool> SubtractLL(Node* head1,Node* head2)
    {
        Node* ans=new Node(-1);
        Node* curr=ans;
        int carry=0;
        while(head1 && head2)
        {
            int first=head1->data;
            if(carry==1)
            {
                if(first==0) 
                {
                    first=9;
                    carry=1;
                }
                else
                {
                    first--;
                    carry=0;
                }
            }
            int second=head2->data;
            if(first<second)
            {
                first+=10;
                carry=1;
            }
            curr->next=new Node(first-second);
            curr=curr->next;
            head1=head1->next;
            head2=head2->next;
        }
        while(head1)
        {
            int first=head1->data;
            if(carry==1) 
            {
                if(first==0)
                {
                    carry=1;
                    first=9;
                }
                else
                {
                     carry=0;
                     first--;
                }
            }
            curr->next=new Node(first);
            curr=curr->next;
            head1=head1->next;
        }
        if(carry==1) return {NULL,false};
        while(head2)
        {
            if(head2->data!=0) return {NULL,false};
            head2=head2->next;
        }
        curr->next=NULL;
        return {ans->next,true};
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        head1=Reverse(head1);
        head2=Reverse(head2);
        pair<Node*,bool> one=SubtractLL(head1,head2);
        pair<Node*,bool> two=SubtractLL(head2,head1);
        
        if(one.second==true)
        {
            Node* temp1=Reverse(one.first);
            while(temp1->next && temp1->data==0) temp1=temp1->next;
            return temp1;
        }
        if(two.second==true)
        {
            Node* temp2=Reverse(two.first);
            while(temp2->next && temp2->data==0) temp2=temp2->next;
            return temp2;
        }
        return NULL;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends