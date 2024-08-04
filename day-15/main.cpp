/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // setting dummy node to head of list
        ListNode* Dummy = new ListNode(0, head);
        // iterating throught the list
        ListNode* lprev = Dummy;
        ListNode* cur = head;
        for (int i=0;i<(left-1);i++){
            lprev = cur;
            cur = cur->next;
        }
        // reversing the list from left to right
        ListNode* prev = NULL;
        for (int i=0; i<(right - left + 1);i++){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        
        lprev->next->next = cur;
        lprev->next = prev;
        return Dummy->next;
    }
};



