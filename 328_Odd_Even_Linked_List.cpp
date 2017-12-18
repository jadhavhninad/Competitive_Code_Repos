/*
328_Odd Even Linked List
*/
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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *even_walker, *odd_walker, *even_head;
        odd_walker = head;
        even_walker = head->next;
        odd_walker->next = NULL;
        even_head = even_walker;
        
        while(true){
            if(even_walker->next != NULL && even_walker->next != odd_walker){
                odd_walker->next = even_walker->next;
                odd_walker = odd_walker->next;
            }
            
            // we check for odd_wallker->next != even_walker in case previous if condition block was not executed.
            if(odd_walker->next != NULL && odd_walker->next != even_walker){
                even_walker->next = odd_walker->next;
                even_walker = even_walker->next;
            }
            
            if(odd_walker->next == NULL || even_walker->next == NULL){
                odd_walker->next = even_head;
                even_walker->next = NULL;
                break;
            }
        }
        
        return head;
    }
};
