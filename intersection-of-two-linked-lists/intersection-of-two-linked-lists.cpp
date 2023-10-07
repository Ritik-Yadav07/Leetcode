/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(!headA || !headB) return NULL;
        
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        int len1 = 0;
        int len2 = 0;
        
        while(ptr1){
            len1++;
            ptr1 = ptr1->next;
        }
        
        while(ptr2){
            len2++;
            ptr2 = ptr2->next;
        }
        
        int diff = abs(len1-len2);
        ptr1 = headA;
        ptr2 = headB;
        
        if(len1>len2){
            while(diff--){
                ptr1 = ptr1->next;
            }
        }
        else{
            while(diff--){
                ptr2 = ptr2->next;
            }
        }
        
        while(ptr1 && ptr2){
            if(ptr1==ptr2) return ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        return NULL;
        
    }
};