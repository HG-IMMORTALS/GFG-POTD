//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
    
    bool isVowel(char c) {
        return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u');
    }
    
 public:

    struct Node* arrangeCV(Node* head) 
    {
        Node *dummy = new Node(1);
        dummy->next = head;
        
        Node *vowel = dummy;
        
        // Move the vowels pointer to the last vowel from the start
        while (vowel->next and isVowel(vowel->next->data)) {
            vowel = vowel->next;
        }
        
        // If the linked list had only vowels
        if (!vowel->next)
            return dummy->next;
        
        
        Node *tmp = vowel->next->next;
        Node *prev = vowel->next;
        
        while (tmp) {
            
            // If it's a vowel, then it needs to come after the 'vowel' ptr
            if (isVowel(tmp->data)) {
                prev->next = tmp->next;
                tmp->next = vowel->next;
                
                vowel->next = tmp;
                vowel = vowel->next;
            }
            
            prev = tmp;
            tmp = tmp->next;
        }
        
        return dummy->next;
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends