//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    Node* getMiddle(Node* head)
    {
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    Node* merge(Node* left,Node* right)
    {
        Node* dummy = new Node(-1);
        Node* tail = dummy;
        
        while(left && right)
        {
            if(left->data < right->data)
            {
                tail->next = left;
                left = left->next;
            }
            else{
                tail->next = right;
                right = right->next;
            }
            
            tail = tail->next;
        }
        
        while(left)
        {
            tail->next = left;
            left = left->next;
            tail = tail->next;
        }
        
        while(right)
        {
            tail->next = right;
            right = right->next;
            tail = tail->next;
        }
        return dummy->next;
    }
    
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(!head ||!head->next) return head;
        
        Node* left = head;
        Node* right = getMiddle(head);
        Node* tmp = right->next;
        right->next = NULL;
        right = tmp;
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        return merge(left,right);
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends