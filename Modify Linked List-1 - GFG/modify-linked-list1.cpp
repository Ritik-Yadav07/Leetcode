//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
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
class Solution{
    public:
   
    struct Node* middleNode(struct Node* head)
    {
        if(head->next==NULL)
        {
            return head;
        }

        struct Node* slow = head;
        struct Node* fast = head->next;

        while(fast!=NULL)
        {
            fast = fast->next;
            if(fast!=NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        return slow;
    }
    


    struct Node* reverse_the_half_list(struct Node* head)
    {
        struct Node* prev = NULL;
        struct Node* curr = head;
        struct Node* next;
        
        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    
    struct Node* modifyTheList(struct Node *head)
    {
        //add code here.
        struct Node *middle = middleNode(head);
        
        middle->next = reverse_the_half_list(middle->next);
        
        
        struct Node *temp = middle->next;
        struct Node *start_temp = head;
        
        while(temp!=NULL)
        {
            int val = start_temp->data;
            start_temp->data = temp->data - start_temp->data;
            temp->data = val;
            
            start_temp = start_temp->next;
            temp = temp->next;
        }
        
        middle->next = reverse_the_half_list(middle->next);
        
        return head;
        
    } 
    
   
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends