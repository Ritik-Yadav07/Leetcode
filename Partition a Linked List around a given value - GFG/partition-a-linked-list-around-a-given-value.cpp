//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}

// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    // code here
    struct Node* h1 = new Node(-1);
    struct Node* h2 = new Node(-1);
    struct Node* h3 = new Node(-1);
    struct Node* ptr1 =h1;
    struct Node* ptr2 =h2;
    struct Node* ptr3 =h3;

        while(head){
            int data = head->data;
            if(data<x){
                ptr1->next = new Node(data);
                ptr1 = ptr1->next;
            }
            else if(data==x){
                 ptr2->next = new Node(data);
                ptr2 = ptr2->next;
            }
            else{
                ptr3->next = new Node(data);
                ptr3 = ptr3->next;

            }
            head = head->next;
        }
        if(h2->next!=NULL){
            ptr1->next = h2->next;
            ptr2->next = h3->next;
        }
        else{
            ptr1->next = h3->next;
        }
        return h1->next;
}